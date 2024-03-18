#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h> 

pthread_attr_t attr;
void *stack() {
    size_t stack_size;
    long tid = (long) pthread_self;
    pthread_attr_getstacksize(&attr, &stack_size);
    printf("thread %ld stack size = %li bytes\n", tid, stack_size);
    return NULL;
}

void *too_damn_long() {
    printf("thread %ld - taking way too damn long to process\n", (long) pthread_self());
    sleep(100);
    return NULL;
}

void *detached_calc() {
    pthread_detach(pthread_self());
    int n = rand() % 3;
    sleep(n);
    printf("detached_calc\n");
    pthread_exit(NULL);
}

// notice void*
    void *hello_world_run()
    {
        printf("hello world from thread = %lu\n", pthread_self());
        return NULL;
    }

int main()
{
    pthread_t detach = 0;
    int ret = pthread_create(&detach, NULL, detached_calc, NULL);

    if(ret != 0) {
        perror("could not create thread");
        exit(1);
    }

    pthread_t thread = 0, another = 0;
    pthread_create(&thread, NULL, hello_world_run, NULL);
    pthread_create(&another, NULL, hello_world_run, NULL);
    pthread_join(thread, NULL); // same thing as .join() in other languages
    pthread_join(another, NULL); // same thing as .join() in other languages

    // custom stack size for threads
    size_t ss = 0;
    pthread_attr_init(&attr);
    pthread_attr_getstacksize(&attr, &ss);

    printf("default stack size = %li\n", ss);
    ss = 90000;
    pthread_attr_setstacksize(&attr, ss);   

    pthread_t stakthread = 0;
    ret = pthread_create(&stakthread, NULL, stack, NULL);
    pthread_join(stakthread, NULL);

    if(ret != 0) {
        perror("could not create thread");
        exit(1);
    }

    // cancel a thread
    pthread_t too_long = 0;
    pthread_create(&too_long, NULL, too_damn_long, NULL);
    sleep(2);
    printf("canceling %ld\n", (long) too_long);
    pthread_cancel(too_long);


    pthread_exit(NULL); // cleanup

    return 0;
}