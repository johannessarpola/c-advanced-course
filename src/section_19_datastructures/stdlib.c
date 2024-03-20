#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int comp_int (const void*, const void*);

void onExit()
{
    printf("exiting now, ok!\n");
}

void secondOnExit()
{
    printf("me too, ok!\n");
}
/**
 * examples of stdlib
 * - atexit
 * - file ops
 * - rand
 * - abort
 * - qsort
 */
int main(int argc, char *argv[])
{
    // at exit runs on exit, can be many, like 32 or so
    atexit(onExit);
    atexit(secondOnExit); // this will fire first, works as a LIFO

    int n = rand();
    printf("rand: %d\n", n);

    float zeroToOne = (float)rand() / RAND_MAX;
    printf("rand zeroToOne: %.2f\n", zeroToOne);

    FILE *file;
    if ((file = fopen("./afile.txt", "r")) == NULL)
    {
        perror("failed to open file");
        exit(EXIT_FAILURE);
    }

    char buf[10];
    while (fgets(buf, sizeof(buf), file) != NULL)
    {
        printf("%s", buf);
    }
    printf("\n");
    fclose(file);


    // qsort()
    int arr[] = {1, 4, 3, 6, 5, 9 };
    int length_of_arr = sizeof(arr) / sizeof(int);
    qsort(arr, length_of_arr, sizeof(int), comp_int);
    for( int i = 0; i < length_of_arr; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // abort()
    if (argc >= 2 && strcmp(argv[1], "-abort") == 0)
    {
        printf("aborting, atexit not called!\n");
        abort(); // can be called to cause SIGABRT

    }

    return 0;
}

int comp_int(const void * p1, const void *p2 ) {
    const int nbr1 = *(const int *) p1;
    const int nbr2 = *(const int *) p2;
    return nbr1 < nbr2;
}