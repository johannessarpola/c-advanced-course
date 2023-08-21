//
// Created by johan on 21/08/2023.
//
#include "stdio.h"

int main() {
    int ch = 0;
    while((ch = getchar()) != EOF) {
        putchar(ch);
    }
    // returns EOF back to stdin
    ungetc(ch, stdin);

    printf("\n");

    return 0;
}