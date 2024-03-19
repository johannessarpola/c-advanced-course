#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

#define THREAD_NUM 10
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t alldoneConditionMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t alldoneCondition = PTHREAD_COND_INITIALIZER;
int threadsDone = 0;

void *combine_function(void *arg)
{
    pthread_mutex_lock(&alldoneConditionMutex); // mutex lock
    int *rs = (int *)arg;
    printf("waiting for calclulations to complete ...\n");
    while (threadsDone < THREAD_NUM)
    {
        pthread_cond_wait(&alldoneCondition, &alldoneConditionMutex);
    }
    printf("summing results of all threads ...\n");
    int sum = 0;
    for (int i = 0; i < THREAD_NUM; i++)
    {
        sum += rs[i];
    }
    printf("total was: %d\n", sum);
    pthread_mutex_unlock(&alldoneConditionMutex);
    return NULL;
}
void *thread_function(void *arg)
{
    int thread_id = *(int *)arg;
    int acquired_mutex = 0;

    while (!acquired_mutex)
    {
        // Use modulo to determine which mutex to acquire
        pthread_mutex_t *mutex;
        if (thread_id % 2 == 0)
        {
            mutex = &mutex1;
        }
        else
        {
            mutex = &mutex2;
        }

        // Attempt to acquire the mutex
        if (pthread_mutex_trylock(mutex) == 0)
        {
            printf("thread-%d acquired mutex\n", thread_id);
            acquired_mutex = 1; // Set the flag to exit the loop if mutex is acquired
        }
        else
        {
            // if can't acquire lock wait 1 second
            sleep(1);
        }
    }

    int n = rand() % 3;
    printf("thread-%d calculating ...\n", thread_id);
    sleep(n);

    if (thread_id % 2 == 0)
    {
        pthread_mutex_unlock(&mutex1);
        printf("thread-%d released mutex\n", thread_id);
    }
    else
    {
        pthread_mutex_unlock(&mutex2);
        printf("thread-%d released mutex\n", thread_id);
    }
    int sum = rand() % 100;
    threadsDone++;
    if (threadsDone == THREAD_NUM)
    {
        pthread_cond_signal(&alldoneCondition);
    }
    return (void *)(intptr_t)sum;
}

int main()
{
    pthread_t threads[THREAD_NUM];
    int thread_ids[THREAD_NUM];
    int results[THREAD_NUM];
    pthread_t combineThread = 0;
    // create a thread to sum all results once they've been calcluated
    pthread_create(&combineThread, NULL, combine_function, &results);

    for (int i = 0; i < THREAD_NUM; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    for (int i = 0; i < THREAD_NUM; i++)
    {
        int num;
        pthread_join(threads[i], (void **)&num);
        results[i] = num;
    }
    pthread_join(combineThread, NULL);
    printf("results: ");
    for (int i = 0; i < THREAD_NUM; i++)
    {
        printf("%d, ", results[i]);
    }
    printf("\n");

    return 0;
}
