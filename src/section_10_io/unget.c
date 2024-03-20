//
// Created by johan on 21/08/2023.
//
#include "stdio.h"
#include "ctype.h"

int main() {
    char ch = 0;
    while(isspace( ch = (char) getchar()));
    // Pyts char back to stdin
    ungetc(ch, stdin);

    printf("put back char: %c\n", getchar());

    return 0;
}