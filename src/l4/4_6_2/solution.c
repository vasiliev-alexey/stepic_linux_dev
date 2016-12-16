//
// Created by alexey on 12.11.16.
//


#include <fcntl.h>
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    int fds[2];
    char buf[4096];
    int i, rc, maxfd;
    int total = 0;
    fd_set watchset;


    if ((fds[0] = open("in1", O_RDONLY | O_NONBLOCK)) < 0) {
        perror("open in1");
        return 1;
    }

    if ((fds[1] = open("in2", O_RDONLY | O_NONBLOCK)) < 0) {
        perror("open in2");
        return 1;
    }


    FD_ZERO(&watchset);
    FD_SET(fds[0], &watchset);
    FD_SET(fds[1], &watchset);


    maxfd = fds[0] > fds[1] ? fds[0] : fds[1];


    while (FD_ISSET(fds[0], &watchset) || FD_ISSET(fds[1], &watchset)) {
        fd_set inset = watchset;
        if (select(maxfd + 1, &inset, NULL, NULL, NULL) < 0) {
            perror("select");
            return 1;
        }


        for (i = 0; i < 2; i++) {
            if (FD_ISSET(fds[i], &inset)) {

                rc = read(fds[i], buf, sizeof(buf) - 1);
                if (rc < 0) {
                    perror("read");
                    return 1;
                } else if (!rc) {
                    close(fds[i]);
                    FD_CLR(fds[i], &watchset);
                } else {
                    buf[rc] = '\0';
                    total = total + strtoul(buf, NULL, 10);
                }
            }
        }
    }
    printf("%d\n", total);
    return 0;
}