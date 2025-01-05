/**
 * Example program to show the usage of CPU' clockticks counter, i.e.
 * - the rdtsc instruction on Intel x86-64 processors and
 * - the CNTVCT_EL0 machine register on Aarch64 processors
 * Instead of fancy configuring-magic (autoconf, cmake), just use
 * pre-defined C-preprocessor macros to figure the corresponding
 * assembler sequence.
 *
 * Compile and execute with:
 *   gcc -Wall -O2 -o tsc tsc.c
 *   ./tsc
 *
 * Author: Rainer Keller, HS-Esslingen, 2019-2024
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#include <assert.h>

#ifndef NUM
#define NUM (100 * 1000)
#endif

/**
 * @brief Return the number of clock-ticks.
 *
 * This is highly CPU implementation-dependant and may only be
 * used to measure short periods of time (due to roll-around),
 * and only within one CPU core (due to rescheduling onto a
 * different core, i.e. might need core-binding using numactl).
 * Clock ticks are reset upon boot (or rather initialization time
 * of this very core).
 *
 * @return  The number of clock-ticks since boot.
 */
inline uint64_t getticks()
{
    uint64_t tsc = 0;

#if defined(__i386__)                          // Intel 80386: 32-Bit
    __asm__ __volatile__("rdtsc" : "=A"(tsc)); // has a special syntax for register edx:eax

#elif defined(__x86_64__) // Intel x86-64: 64-Bit
    unsigned int lo, hi; // we have to register: the lower 32-bit, the higher 32-bit
    __asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
    tsc = ((uint64_t)hi << 32) | (uint64_t)lo; // and we shift the register edx:eax into place.

#elif defined(__aarch64__) // ARM Aarch64: is a bit more tricky, since
                           // e.g. Apple M1-M4 are different than Raspberry PI's cores...
    __asm__ __volatile__("mrs %0,  CNTVCT_EL0" : "=r"(tsc));
    // __asm__ __volatile__("mrs %0, PMCCNTR_EL0" : "=r"(tsc));
#else
#error "Clock ticks (time stamp counter) not available on this processor?
#endif
    return tsc;
}

/**
 * This function just acts as a marker in the generated Assembly code and is
 * basically a No-Op together with a (useless) Jump to the next instruction.
 *
 * Thankfully, x86, x86-64 and Aarch64 all call this snstruction nop.
 * NLT is just a text-string for newline and tab-character for pretty-printing
 * the assembler output, when compiling with "gcc -fverbose-asm -S -o tsc.S tsc.c"
 */
#define NLT "\n\t"
inline void marker()
{
    __asm__ __volatile__(
        "nop" NLT
#if defined(__x86_64__)
        "jmp L%=" NLT
        "L%=:"
#endif
        : // Output
    );
}

/**
 * @brief Function to measure the average of running getticks.
 *
 * Measures the time it takes to issue a clock-tick fetching instruction,
 * using system time _and_ the clock-tick function itselve and returns
 * both in the corresponding parameters
 *
 * @param avg_time_usec The time per clock-tick in micro-seconds
 * @param avg_ticks     The average number of clock-ticks per clock-tick measurement
 *
 * @return  Non-sense to get the compiler to NOT optimize away the loop
 */
uint64_t avg(double *avg_time_usec, double *avg_ticks)
{
    uint64_t ret = 0;
    uint64_t start;
    uint64_t stop;
    struct timeval start_tv;
    struct timeval stop_tv;
    assert(NULL != avg_time_usec);
    assert(NULL != avg_ticks);

    gettimeofday(&start_tv, NULL);
    start = getticks();
    for (int i = 0; i < NUM; i++)
        ret += getticks();
    stop = getticks();
    gettimeofday(&stop_tv, NULL);
    *avg_ticks = 1.0 * (stop - start) / NUM;
    *avg_time_usec = ((stop_tv.tv_sec - start_tv.tv_sec) * (1000.0 * 1000.0 * 1000.0) + (stop_tv.tv_usec - start_tv.tv_usec)) / NUM;
    return ret;
}

int main(int argc, char *argv[])
{

    double avg_time_usec;
    double avg_ticks;

    avg(&avg_time_usec, &avg_ticks);

    printf("NUM:%d avg_time_usec:%f avg_ticks:%f\n",
           NUM, avg_time_usec, avg_ticks);

    return EXIT_SUCCESS;
}
