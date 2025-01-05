/*
 * Example to run a function every 1000 ms.
 *
 * Author: Rainer Keller, HS-Esslingen
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/workqueue.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rainer Keller");
MODULE_DESCRIPTION("Module to run work_handler recurrently");

static unsigned int delay_ms = 1000;
module_param(delay_ms, uint, 0644);
MODULE_PARM_DESC(delay_ms, "Verzögerung in Workhandler");

static void work_handler(struct work_struct *w);

static struct workqueue_struct *wq = NULL;
static DECLARE_DELAYED_WORK(dwork, work_handler);

static unsigned long delay;

static void work_handler(struct work_struct *w)
{

    static int times = 0;
    struct task_struct *task = current;

    for (int i = 0; i < task->latency_record_count; i++)
    {

        printk(KERN_INFO "Workhandler ist  %d mal gelaufen, Latennzaufzeichnung %d: Anzahl = %u, backtrace[0] = %pX\n", times, i, task->latency_record[i].count, (void *)task->latency_record[i].backtrace[0]);
    }

    times++;

    queue_delayed_work(wq, &dwork, delay);
}

__init int init_module(void)
{
    delay = msecs_to_jiffies(delay_ms);
    wq = alloc_workqueue("test", WQ_UNBOUND, 1);
    if (NULL == wq)
    {
        pr_err("Cannot allocate workqueue");
        return -1;
    }
    queue_delayed_work(wq, &dwork, delay);
    return 0;
}

__exit void cleanup_module(void)
{
    cancel_delayed_work_sync(&dwork);
    destroy_workqueue(wq);
    printk(KERN_INFO "Modul wird verlassen: mod_stat_scheduler\n");
}