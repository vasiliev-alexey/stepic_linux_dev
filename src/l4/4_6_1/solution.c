//
// Created by alexey on 12.11.16.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char cmd[80];
    char buf[256];
    int count = 0;
    int i;
    int buf_size = sizeof(buf);

    sprintf(cmd, "%s %s", argv[1], argv[2]);
    FILE *pfd = popen(cmd, "r");

    if ( pfd == 0 )
    {
        printf( "failed to open pipe\n" );
        return 1;
    }
    else {
        while (fgets(buf, buf_size, pfd) != NULL) {
            for (i = 0; i < buf_size; i++) {
                if (buf[i] == '\0')
                    break;
                if (buf[i] == '0')
                    count++;
            }
        }
        pclose(pfd);
        printf("%d\n", count);
        return 0;
    }
}