#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_COUNT 10

void child_process()
{
    printf("child processing ...+\n");
    for (int i = 0; i < MAX_COUNT; i++)
    {
        printf("child print, value %d\n", i);
        usleep(100);
    }
    printf("child proces done ...\n");
}

void parent_proces()
{
    printf("parent proceessing ...\n");
    for (int i = 0; i < MAX_COUNT; i++)
    {
        printf("parent print, value %d\n", i);
        usleep(100);
    }
    printf("parent proces done ...\n");
}

int main()
{

    pid_t forked_pid = fork();

    printf("pid: %d\n", forked_pid);
    if (forked_pid == 0)
    {
        child_process();
    }
    else if (forked_pid > 0)
    {
        parent_proces();
    }
    else
    {
        printf("fork_failed");
        return 1;
    }

    return 0;
}