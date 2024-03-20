#include <stdio.h>
#include "string.h"


struct Point
{
    int x;
    int y;
};

void send(void *data, int n, int type);
void sendPoint(struct Point *point);
void sendCharArray(char *charArray, int n);

int main()
{
    int t = 10;
    float f = 0.123f;
    char c = 'c';

    // void ptr can store any kind of data but needs to be casted
    void *vptr = NULL;
    vptr = &t;

    // temporary cast
    printf("%d\n", *(int *)vptr);

    vptr = &f;
    printf("%.2f\n", *(float *)vptr);

    vptr = &c;
    printf("%c\n", *(char *)vptr);

    char *data = "text block";
    send(data, strlen(data), 1);

    struct Point point = {10, 20};
    send(&point, 1, 2);

    return 0;
}


void send(void *data, int n, int type)
{
    // for char array
    if (type == 1)
    {
        char *charArray = (char *)data;
        sendCharArray(charArray, n);
    }
    if (type == 2)
    {
        struct Point* point = (struct Point *) data;
        sendPoint(point); 
    }

    return;
}

void sendPoint(struct Point *point)
{
    printf("x: %d, y: %d", point->x, point->y);
}
void sendCharArray(char *charArray, int n)
{
    // Print each character in the array
    printf("Data: ");
    for (int i = 0; i < n; ++i)
    {
        printf("%c ", charArray[i]);
    }
    printf("\n");
}
