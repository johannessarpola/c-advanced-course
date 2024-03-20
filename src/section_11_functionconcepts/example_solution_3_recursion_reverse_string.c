#include<stdio.h>

char * reverse(char * str);

int main()
{
    char str[100];
    char *rev = NULL;

    printf("Enter the string: ");
    scanf("%s", str);

    printf("The original string is: %s\n", str);

    rev = reverse(str);

    printf("The reversed string is: %s\n", rev);

    return 0;
}

char * reverse(char *str) {
    static int i = 0; // initialized once, incremented further into recursion
    static char rev[100]; // initialized once, updated with recursion char by char

    if (*str) {
        reverse(str + 1); // recursion starts here so it will get evaluated first
        rev[i++] = *str; // then this will cascade (levels recursion.c)
    }

    return rev;
}

