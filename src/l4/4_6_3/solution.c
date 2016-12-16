//
// Created by alexey on 13.11.16.
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>

int sigusr1_count = 0;
int sigusr2_count = 0;

void sig_handler(int signal_number)
{
    if(signal_number==SIGUSR1)
    {
        ++sigusr1_count;
    }
    if(signal_number==SIGUSR2)
    {
        ++sigusr2_count;
    }
    if(signal_number==SIGTERM)
    {
        printf("%d %d\n", sigusr1_count, sigusr2_count);
        exit(0);
    }
}

int main()
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &sig_handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);

    while (1)
    {
        usleep(500000);
    }
    return 0;
}