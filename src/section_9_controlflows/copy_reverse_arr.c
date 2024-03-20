//
// Created by johan on 18/08/2023.
//
#include <stdio.h>

/*
 * succint way to copy and reverse arrays
 */
int main() {
    printf("start>\n");
    char a[] = "another string";
    char* a_rd = a;
    size_t a_length = sizeof(a);

    char b[a_length];
    char* b_wrt = b + a_length - 2;

    char c[a_length];
    char* c_wrt = c;

    // copy array
    while((*c_wrt++ = *a_rd++) != '\0');

    // reset a_rd
    a_rd = a;

    // reverse string
    while((*b_wrt-- = *a_rd++) != '\0');

    printf("copied> %s copied as %s\n", a, c);
    printf("reversed> %s reversed as %s\n", a, b);
    return 0;
}