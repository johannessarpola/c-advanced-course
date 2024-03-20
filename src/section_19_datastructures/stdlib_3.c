#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/**
 * examples of
 * - system
 * - getenv
 * - memcpy
 * - memmove
 * - strdup (not available in all compilers)
 * - strndup (not available in all compilers)
 */
#define SIZE 10

void print_arr(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
};

int main()
{
    static_assert(sizeof(double) == 2 * sizeof(int), "double not twice the int");

    char cmd[50];
    strcpy(cmd, "ls -l");
    system(cmd);

    printf("\n");

    char *e = getenv("PWD");
    char *u = getenv("USER");
    char *non = getenv("ashdjsahdkjsahkjadhsa"); // returns null as it is not defined
    printf("pwd - %s\n", e);
    printf("user - %s\n", u);
    printf("non - %s\n", non);

    int values[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target[SIZE];

    printf("values: ");
    print_arr(values, SIZE);
    memcpy(target, values, SIZE * sizeof(int));
    printf("\ntarget (after memcpy): ");
    print_arr(target, SIZE);
    
    printf("moving overlapping ranges:\n");
    int newsize = 5;
    memmove(values + 2, values, newsize * sizeof(int));
    printf("moved elements 0-5 to 2-7");
    print_arr(values, SIZE);


    double doubles[SIZE / 2] = { 2.0, 2.0e5, 2.0e10, 2.0e20, 2.0e30 };
    printf("\nMovin doubels to int array with memcpy, 5 members to 10 int spots\n");
    memcpy(target, doubles, (SIZE / 2 ) * sizeof(double));
    print_arr(target, SIZE/2);
    printf("-----\n");
    print_arr(target + 5, SIZE/2);


    char *p1 = "johannes";
    char *p2;
    char *p3;

    p2 = strdup(p1);
    p3 = strndup(p1, 5);

    printf("duplicated %s to %s\n", p1, p2);
    printf("duplicated %s to %s with 5 limit\n", p1, p3);

    return 0;
}