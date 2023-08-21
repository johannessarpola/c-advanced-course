//
// Created by johan on 21/08/2023.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define BUF_SIZE 32
int main() {
    char *buffer = NULL;

    size_t buffer_size = BUF_SIZE;
    size_t read_count;

    buffer = (char*) malloc(BUF_SIZE * sizeof(char));


    if(buffer == NULL) {
        printf("too big!");
        return 1;
    }

    printf("type something:\n");
    read_count = getline(&buffer, &buffer_size, stdin);
    printf("buffer: %s\n", buffer);
    printf("number read: %zu\n", read_count);
    free(buffer);
    puts("done!"); // can't use fmt with this but appends \n
    return 0;
}