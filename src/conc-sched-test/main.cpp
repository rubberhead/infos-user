#include <infos.h>

static volatile bool terminate; 

static void terminate_ticker_thread_proc(void *arg)
{
    printf("Press <ENTER> to stop\n");
    while (getch() != '\n');
    printf("Stopping threads...\n");
    terminate = true;

    stop_thread(HTHREAD_SELF);
}

static void var_prio_ticker_proc(void *arg)
{
    unsigned int prio_lvl = (unsigned int)(unsigned long)arg; 
    while (!terminate) {
        printf("Running at priority %d!\n", prio_lvl); 
        usleep(1000000); // 1s
    }

    stop_thread(HTHREAD_SELF); 
}

int main(const char* cmdline)
{
    printf("Running scheduler test with concurrency!\n"); 

    terminate = false;
    HTHREAD threads[3]; 
    threads[0] = create_thread(
        var_prio_ticker_proc, 
        (void *)(unsigned long)2, 
        SchedulingEntityPriority::NORMAL
    ); 
    threads[1] = create_thread(
        var_prio_ticker_proc, 
        (void *)(unsigned long)3, 
        SchedulingEntityPriority::DAEMON
    ); 
    threads[2] = create_thread(
        var_prio_ticker_proc, 
        (void *)(unsigned long)1, 
        SchedulingEntityPriority::INTERACTIVE
    ); 
    threads[3] = create_thread(
        terminate_ticker_thread_proc, 
        nullptr, 
        SchedulingEntityPriority::REALTIME
    ); 

    for (unsigned int i = 0; i < 4; i++) {
        join_thread(threads[i]); 
    }

    printf("Scheduler test complete!\n"); 
    return 0;
}
