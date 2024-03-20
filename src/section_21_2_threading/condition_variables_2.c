#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

#define THREAD_NUM 16 // in this example it needs to be even
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t evenStevensDone = PTHREAD_COND_INITIALIZER;

int numberEvenStevensDone = 0;
int counter = 0;

void *func(void *data)
{
    int *x = (int *)data;
    pthread_mutex_lock(&lock);

    if (*x % 2 == 0)
    {
        numberEvenStevensDone++;
    }
    else
    {
        pthread_cond_wait(&evenStevensDone, &lock);
    }

    counter++;
    printf("message is %d, thread id = %lud modified the counter to %d\n", *x, pthread_self(), counter);
    printf("message is %d, thread id = %lud read the counter %d\n", *x, pthread_self(), counter);

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t threads[THREAD_NUM];
    int thread_ids[THREAD_NUM];

    for (int i = 0; i < THREAD_NUM; i++)
    {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, func, &thread_ids[i]) != 0)
        {
            perror("could not create thread");
            return 1;
        }
    }

    while (1)
    {
        if (numberEvenStevensDone == THREAD_NUM / 2)
        {
            printf("... triggered broadcast for odd threads ...\n");
            pthread_cond_broadcast(&evenStevensDone);
            break;
        }
        // just here to save some cycles
        sleep(1);
    }

    for (int i = 0; i < THREAD_NUM; i++)
    {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < THREAD_NUM; i++)
    {
        pthread_exit(&threads[i]);
    }

    return 0;
}
