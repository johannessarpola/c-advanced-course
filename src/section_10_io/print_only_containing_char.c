//
// Created by johan on 21/08/2023.
//
#include "stdio.h"
int has_ch(char ch, const char * line);
int main(int argc, char *argv[]) {
    char ch;
    char* file_name;
    FILE* fp = NULL;

    if (argc != 3)  {
        printf("Usage: %s character filename\n", argv[0]);
        return 1;
    }

    ch = argv[1][0];
    file_name = argv[2];

    fp = fopen(file_name, "r");
    if(fp == NULL) {
        printf("Could not open file %s", file_name);
        return 1;
    }

    size_t len = 255;
    char buffer[len];
    const char* buffer_ptr = buffer;

    while(fgets(buffer, (int) len, fp)) {
        if(has_ch(ch, buffer)) {
            printf("%s", buffer); // Could write to file as well
        }
    }

    fclose(fp);
    return 0;
}

// check if line has char
int has_ch(char ch, const char * line) {
    while(*line)
        if(ch == *line++)
            return 1;
    return 0;
}