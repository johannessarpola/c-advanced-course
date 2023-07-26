#include <stdio.h>

typedef int Counter;
typedef int* i_ptr;

int main() {
    Counter counter = 1;
    i_ptr ip = &counter;
    counter++;
    printf("counter is %d\n", counter);
    printf("pointer points to %d with address %p\n", *ip, (void*)ip);
    return 0;
}