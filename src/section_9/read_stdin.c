//
// Created by johan on 18/08/2023.
//
#include <stdio.h>

/*
 * succint way to read stdin
 */
#define MAX_LEN 100
int main() {
    printf("enter some text:\n");
    char s[MAX_LEN];
    char* s_w_ptr = s;
    while((*s_w_ptr++ = (char) getchar()) != '\n');

    printf("input: %s\n", s);
    return 0;
}