#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h> 

struct Person
{
    char *firstName;
    char *lastName;
};

struct Bom {
    int firstNum;
    int secondNum;
};

void *intensive_calculation(void *bom) 
{
    struct Bom *b = (struct Bom *) bom;
    int n = rand() % 3;
    printf("calculating ...\n");
    sleep(n);

    int sum = b->firstNum + b->secondNum;
    return (void *) (intptr_t) sum;  

}

void *delayed_print(void *message)
{
    int n = rand() % 3;
    sleep(n);
    printf("message: %s\n", (char *)message);
    return NULL;
}
void *hello_who_run(void *arg)
{
    struct Person *person = (struct Person *)arg;
    printf("hello %s %s\n", person->firstName, person->lastName);
    return NULL;
}

// notice void*
void *hello_world_run()
{
    printf("hello world!\n");
    return NULL;
}

int main()
{
    pthread_t thread = 0;
    pthread_create(&thread, NULL, hello_world_run, NULL);
    pthread_join(thread, NULL); // same thing as .join() in other languages

    pthread_t secondThread = 0;
    struct Person person = {firstName : "Erkki", lastName : "Joosepinpoika"};
    pthread_create(&secondThread, NULL, hello_who_run, &person); // passing a struct to thread
    pthread_join(secondThread, NULL);                            // same thing as .join() in other languages

    pthread_t one = 0, two = 0;
    char *msg1 = "first";
    char *msg2 = "second";

    pthread_create(&one, NULL, delayed_print, (void *)msg1);
    pthread_create(&two, NULL, delayed_print, (void *)msg2);

    pthread_join(one, NULL);
    pthread_join(two, NULL);

    pthread_t calcThread = 0;
    struct Bom bom = {firstNum : 10, secondNum : 22};
    pthread_create(&calcThread, NULL, intensive_calculation, &bom); // passing a struct to thread

    intptr_t num;
    pthread_join(calcThread, (void **)&num);
    printf("calculation result %ld\n", num);

    pthread_exit(NULL); // cleanup

    return 0;
}