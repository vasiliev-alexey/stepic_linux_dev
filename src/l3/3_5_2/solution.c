#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>

typedef long long int num;
num pid;
num ppid;
char tcomm[PATH_MAX];
char state;

FILE *input;

int main(int argc, char *argv[]) {
    input = NULL;
    input = fopen("/proc/self/stat", "r");
    fscanf(input, "%lld %s %c %lld ", &pid, tcomm, &state, &ppid);
    printf("%lld\n", ppid);
    return 0;
}