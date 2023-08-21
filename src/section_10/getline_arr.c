//
// Created by johan on 21/08/2023.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define BUF_SIZE 32
int main() {
    char buffer[BUF_SIZE];
    char* buffer_ptr = buffer;

    size_t buffer_size = BUF_SIZE;
    size_t read_count;

    printf("type something:\n");
    read_count = getline(&buffer_ptr, &buffer_size, stdin);
    printf("buffer: %s\n", buffer);
    printf("number read: %zu\n", read_count);
    puts("done!"); // can't use fmt with this but appends \n
    return 0;
}