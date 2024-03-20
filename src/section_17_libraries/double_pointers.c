#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    int *p1 = NULL;
    int **p2 = NULL;

    p1 = &a;
    p2 = &p1;

    printf("%p\n", p1);
    printf("%p\n", p2);

    printf("%d\n", *p1);
    printf("%d\n", **p2);

    return 0;
}
