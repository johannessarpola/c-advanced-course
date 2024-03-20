#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#define THREAD_NUM 10
pthread_mutex_t lock;
pthread_mutex_t anotherLock = PTHREAD_MUTEX_INITIALIZER; // we can use macro to init
int j = 0;
int results[THREAD_NUM];
int slot = 0;

void *process()
{
    pthread_mutex_lock(&lock);
    int i = 0;
    j++;
    printf("started %d process\n", j);
    while (i < 5)
    {
        printf("%d ", j); // notice that this is buffered and will be printed after line change
        sleep(1);
        i++;
        fflush(stdout); // we can force flush with fflush
    }
    pthread_mutex_unlock(&lock);
    printf("\nprocess %d completed\n", j);
    return NULL;
}

void *another_process()
{
    printf("locking to calculate %d\n", slot);
    pthread_mutex_lock(&anotherLock);
    int n = rand() % 3;
    printf("calculating %d...\n", slot);
    sleep(n);
    int num = rand() % 100;
    results[slot] = num;
    slot++;
    pthread_mutex_unlock(&anotherLock);
    printf("released lock %d\n", slot);

}
int main()
{
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("could not init mutex\n");
        return 1;
    }
    pthread_t thread = 0, another = 0, third = 0;
    pthread_create(&thread, NULL, process, NULL);
    pthread_create(&another, NULL, process, NULL);
    pthread_create(&third, NULL, process, NULL);

    pthread_join(thread, NULL);
    pthread_join(another, NULL);
    pthread_join(third, NULL);
    printf("done!\n");
    pthread_exit(NULL); // cleanup

    pthread_t threads[THREAD_NUM];

    for (int i = 0; i < THREAD_NUM; i++)
    {
        pthread_create(&threads[i], NULL, another_process, NULL);
    }

    for (int i = 0; i < THREAD_NUM; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}