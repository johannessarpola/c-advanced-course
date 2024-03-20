//
// Created by johan on 18/08/2023.
//
#include <stdio.h>

/*
 * succint way to copy and reverse arrays
 */
int main() {
    printf("start>\n");
    char look_for = 'x';
    char a[] = "find the x";
    char* a_rd = a;

    int idx = 0;
    for(;a[idx] != look_for; idx++);

    printf("found> %c(from_arr: %c) at %d of '%s'\n", look_for, a[idx], idx, a);
    return 0;
}