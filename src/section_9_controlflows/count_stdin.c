//
// Created by johan on 18/08/2023.
//
#include <stdio.h>

/*
 * succint way to count stdin chars
 */
#define MAX_LEN 100
int main() {
    printf("enter some text:\n");
    int count;
    for(count = 0; getchar() != '\n'; count++);
    printf("count: %d\n", count);
    return 0;
}