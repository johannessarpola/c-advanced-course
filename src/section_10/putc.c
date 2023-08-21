//
// Created by johan on 21/08/2023.
//
#include "stdio.h"

int main() {
    FILE* f = fopen("out.txt", "w");

    if( f == NULL) {
        perror("error error");
        return 1;
    } else {
        putc('a', f);
    }
    fclose(f);


    putc('b', stdout); // write directly to stdout
    fprintf(stdout, "\nlonger string");
    return 0;
}