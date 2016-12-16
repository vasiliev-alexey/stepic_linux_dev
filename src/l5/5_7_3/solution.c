//
// Created by alexey on 19.11.16.
//

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int  chrcomp(const void *p1, const void *p2)
{
    return *(char *) p2 - *(char *) p1;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Wrong argument count!\n");
        return 1;
    }

    struct sockaddr_in local;
    int servsock = socket(AF_INET, SOCK_STREAM, 0);
    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(atoi(argv[1]));
    local.sin_family = AF_INET;
    bind(servsock, (struct sockaddr *) &local, sizeof(local));
    listen(servsock, 5);
    int clientsock = accept(servsock, NULL, NULL);

    const int BUF_SIZE = 5001;
    char buf[BUF_SIZE];
    while (1)
    {

        int string_len = read(clientsock, buf, BUF_SIZE) - 1;
        buf[string_len+1] = 0;
        if (strcmp(buf, "OFF") == 0)
            break;
        qsort(buf, string_len, sizeof(char), chrcomp);
        write(clientsock, buf, string_len + 1);
    }

    return 0;
}