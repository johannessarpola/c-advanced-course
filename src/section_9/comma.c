//
// Created by johan on 18/08/2023.
//
#include "stdio.h"

int func2() {
    printf("func2\n");
    return 5;
}
int func1() {
    printf("func1\n");
    return 2;
}
int main() {

    // value will be 5 as they're in parenthesis
    int fs = (func1(), func2());
    printf("fs: %d\n", fs);

    // now the value will be func1() so 2
    int fs2 = func1(), func2();
    printf("fs2: %d\n", fs2);

    // you can use comma to make more fancy for loops for example
    for (int i = 0, j = i; i < 10; j += i * i, i++) {
        printf("i: %i j: %d\n", i, j);
    }

    int x, y, z;
    // comma starts evaluating from left to right and ends up resolving
    // as  x: 25 y: 10 z: 20
    x = (y=10, (z = y*2) + 5);
    printf("x: %i y: %d z: %d\n", x,y,z);
}