#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#define THREAD_NUM 10
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // we can use macro to init
int results[THREAD_NUM];
int slot = 0;

void *process()
{
    printf("locking to calculate %d\n", slot);
    pthread_mutex_lock(&lock);
    int n = rand() % 3;
    printf("calculating %d...\n", slot);
    sleep(n);
    int num = rand() % 100;
    results[slot] = num;
    slot++;
    pthread_mutex_unlock(&lock);
    printf("released lock %d\n", slot);
    return NULL;
}
int main()
{

    pthread_t threads[THREAD_NUM];

    for (int i = 0; i < THREAD_NUM; i++)
    {
        pthread_create(&threads[i], NULL, process, NULL);
    }

    for (int i = 0; i < THREAD_NUM; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("results: ");
    for (int i = 0; i < THREAD_NUM; i++)
    {
        printf("%d, ", results[i]);
    }
    printf("\n");

    return 0;
}