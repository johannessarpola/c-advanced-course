//
// Created by johan on 21/08/2023.
//
//
// Created by johan on 21/08/2023.
//
#include "stdio.h"
#include "ctype.h"
#include "string.h"

#define MAX_F 100
int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Please provide file\n");
        return 1;
    }
    const char* file_name = argv[1];

    FILE* fp = fopen(file_name, "r");

    if (fp == NULL) {
        return 1;
    }

    char out_file_name[MAX_F];
    char* ext = strchr(file_name, '.');

    if(ext != NULL ) {
        int pos = ext - file_name;

        strncpy(out_file_name, file_name, pos);
        out_file_name[pos] = '\0';

        strcat(out_file_name, "_out");
        strcat(out_file_name, ext);

    } else {
        strcpy(out_file_name, file_name);
        strcat(out_file_name, "_out");
    }

    FILE* out_fp = fopen(out_file_name, "w");
    if (out_fp == NULL) {
        return 1;
    }
    char c = '\0';
    while((c = fgetc(fp)) != EOF) {
        fputc(toupper(c), out_fp);
    }

    return 0;
}