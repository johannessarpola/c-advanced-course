#include <stdio.h>

union Mixed {
    char c;
    float f;
    int i;
};

union number {
    int x;
    double y;
};

// You can access only one member at a same time
int main() 
{
    union Mixed x;
    x.c = 'c';

    printf("Char %c\n", x.c);
    printf("Int %d\n", x.i);
    printf("Float %.2f\n", x.f);

    // new val
    x.i = 99999;
    printf("Char %c\n", x.c);
    printf("Int %d\n", x.i); 
    printf("Float %.2f\n", x.f);  

        // new val
    x.f = 123.123;
    printf("Char %c\n", x.c);
    printf("Int %d\n", x.i); 
    printf("Float %.2f\n", x.f);  

    union number value = { 15 };
    printf("Numb %d || %.2f\n", value.x, value.y);

    union number value2 = { 11.23 };
    printf("Numb %d || %.2f\n", value2.x, value2.y);

    return 0;
}