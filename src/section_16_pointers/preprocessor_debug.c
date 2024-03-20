#include <stdio.h>

int main() {
    printf("Enter 3 numbers:\n");

    int i, j, k, nread;
    nread = scanf("%d %d %d", &i, &j, &k);

    #ifdef DEBUG
        fprintf(stderr, "Number read = %i\n", nread);
        fprintf(stderr, "i: %i, j: %i, k:%i\n", i, j, k);
    #endif

    printf("%d\n", i + j + k);
    return 0;
}