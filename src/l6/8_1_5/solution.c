//
// Created by alexey on 26.11.16.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    int c;
    while (1)
    {
        static struct option long_options[] =
                {
                        {"query", required_argument, 0, 'q'},
                        {"longinformationrequest", no_argument, 0, 'i'},
                        {"version", no_argument, 0, 'v'}
                };
        int option_index = 0;
        c = getopt_long(argc, argv, "q:iv", long_options, &option_index);
        if (c == -1) break;
        switch (c)
        {
            case '?':
                printf("-\n");
                return 0;
        }

    }
    printf("+\n");
    return 0;
}