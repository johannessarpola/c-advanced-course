#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * examples of:
 * - conversions
 * - srand
 */

int main()
{

    char a[10] = "100";
    char b[10] = "100.23f";
    char c[30] = "100000000000000";
    int value = atoi(a);
    float valuef = atof(b);
    long valuel = atol(c);

    printf("value - %d\n", value);
    printf("value - %.2f\n", valuef);
    printf("value - %lu\n", valuel);

    char d[30] = "123.2312xyz", *end;
    double value2 = strtod(d, &end);
    printf("value - %lf\n", value2);
    printf("end - %s\n", end);

    char e[15] = "66.77 12.02", *end2;
    float first = strtof(e, &end2);
    float second = strtof(end, NULL);

    printf("%.2f, %.2f\n", first, second);

    char str[30] = "2030006767 This is the rest";
    char *ptr = NULL;
    long ret = 0;

    // base of the number can be added here
    ret = strtol(str, &ptr, 10);
    printf("the number %lu\n", ret);
    printf("the string %s\n", ptr);

    // seeding rand to time, could be whatever
    srand(time(0));
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d, ", rand());
    }
    printf("\n");
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d, ", rand() % 5 + 1);
    }
    printf("\n");

    return 0;
}