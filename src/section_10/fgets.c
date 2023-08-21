//
// Created by johan on 21/08/2023.
//
#include "stdio.h"
#include "string.h"

int main() {
    char buffer[255];
    int ch = '\0';
    char *p = NULL;

    // read buffer and add \0 to the end instead of \n
    if(fgets(buffer, sizeof(buffer), stdin)) {
        p = strchr(buffer, '\n');
        if(p) {
            *p = '\0';
        }
        else {
            // read the rest of stdin and dump it
            while(((ch = getchar()) != '\n') && !feof(stdin) && !ferror(stdin));
        }
    }
    else {
        // TODO Handle error
    }
    printf("buffer: %s\n", buffer);
    printf("done!\n");
    return 0;
}