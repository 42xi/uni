
obj-m = linux_module.o

obj-m += mod_stat_scheduler.o


KVERSION = $(shell uname -r)

modules all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
