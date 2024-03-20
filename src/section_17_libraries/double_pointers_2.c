#include <stdio.h>
#include "malloc.h"
#include "string.h"

/*
Change only local copy of value
*/
void foo(int *ptr) {
    int a = 5;
    ptr = &a;
    // ptr is a local copy so the value does not change
    printf("inside foo: %d\n", *ptr);

}

/*
Alter the value through double pointer
*/
void baz(int **ptr) {
    int a = 77;
    *ptr = &a;
    // you can alter the value with douple pointer
    printf("inside baz: %d\n", **ptr);

}
/*
allocate memory test
*/
void bar(char *ptr) {
    ptr = malloc(255); // memory leaks as you allocate memory for the copy
    strcpy(ptr, "Hello World");
    printf("inside bar: %s\n", ptr);
}

/*
double pointers to rescue
*/
void biz(char **ptr) {
    *ptr = malloc(255);
    strcpy(*ptr, "Hello World");
    printf("inside biz: %s\n", *ptr);
}

int main(int argc, char const *argv[])
{
    int *ptr = NULL;
    ptr = (int *) malloc(sizeof(int));
    *ptr = 22;
    foo(ptr); // parameter is passed by value

    printf("after foo: %d\n", *ptr);

    baz(&ptr); // with double pointer the value can be changed
    printf("after baz: %d\n", *ptr);

    char *cptr = NULL;
    bar(cptr);
    printf("after bar: %s\n", cptr);
    free(cptr); // should segfault


    char *cptr2 = NULL;
    biz(&cptr2);
    printf("after biz: %s\n", cptr2);
    free(cptr2); // should segfault


    return 0;
}
