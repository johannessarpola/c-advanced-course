//
// Created by johan on 22/08/2023.
//
#include "stdio.h"
int factorial(int);
void up_and_down(int);
int main() {

    int f = factorial(10);
    printf("factorial is: %d\n", f);

    up_and_down(1);
    return 0;
}

int factorial(int n) {
    // if 0 return 1
    if(n== 0) return 1;
    return (n * factorial(n - 1));
}

void up_and_down(int n) {
    printf("* level: %d ptr: %p\n", n, &n);
    if( n < 4) {
        up_and_down(n + 1);
    }

    printf("- LEVEL %d ptr: %p\n", n, &n);
}