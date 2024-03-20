#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int mypid, myppid;
    printf("print pid and ppid\n");
    mypid = getpid();
    myppid = getppid();

    printf("pid: %d\n", mypid);
    printf("ppid: %d\n", myppid);

    //system("ps -ef");
    return 0;
}