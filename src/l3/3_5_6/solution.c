//
// Created by alexey on 06.11.16.
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


int main()
{
    int i;
    if (getppid() == 1) return 0;
    i = fork();
    if (i < 0) exit(1);
    if (i > 0) exit(0);
    printf ("%d\n", (int) getpid ());
    setsid();
    for (i = getdtablesize(); i >= 0; --i) close(i);
    while (1) sleep(1);

}