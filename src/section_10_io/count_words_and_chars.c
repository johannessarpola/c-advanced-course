//
// Created by johan on 21/08/2023.
//
#include "stdio.h"

int main(int argc, char *argv[]) {

    FILE* fp = stdin;
    if(argc > 1) {
        const char* file_name = argv[1];

        fp = fopen(file_name, "r");
        if(fp == NULL) {
            return 1;
        }

        printf("Counting from file %s\n", file_name);
    }
    else {
        printf("Counting from stdin\n");
    }

    int words = 0, chars = 0;
    char ch = '\0';
    while((ch = fgetc(fp)) != EOF) {
        if(ch == ' '  || ch  == '\n' || ch == '\r') {
            words++;
        }
        else {
            chars++;
        }
    }

    printf("There were %d words\n", words);
    printf("There were %d characters\n", chars);

    return 0;
}