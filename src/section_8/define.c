#include <stdio.h>
#include <stddef.h>

#define ARRAY_SIZE 5
int main() {
    int numbers[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    printf("size of array is %d\n", ARRAY_SIZE);
    int *aptr = NULL;
    if(!NULL) {
        printf("null was false\n");
    }
    if(!aptr) {
       printf("null pointer was false\n"); 
    }

    printf("null was false\n");
    return 0;
}