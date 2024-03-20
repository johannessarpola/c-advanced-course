#include <stdio.h>
#include <stdlib.h>

// declare a new function pointer type
// makes print_callback alias for void f(int) function call
typedef void (*print_callback)(int);

int add(int a, int b, print_callback print);
int subtract(int a, int b);
void console_print(int value);
void file_print(int value);
void read_file();

#define FILE_NAME "/tmp/out.txt"

int main() {

        // print the output to console
    add(10, 20, console_print);

    // print the output to a file
    add(10, 40, file_print);

    // store func as a variable, intintfunc now means a pointer to 'int func(int,int)'
    int(*intintfunc)(int, int) = subtract;
    printf("%d\n", intintfunc(11, 12));

    read_file();
    return 0;
}

void read_file() {
    char ch = '\0';
    FILE* fp;

    if((fp = fopen(FILE_NAME, "r"))) {
        while((ch = (char) getc(fp)) != EOF) {
            printf("%c", ch);
        }
    }
    printf("\n");
}

int subtract(int a, int b) {
    return a - b;
}

int add(int a, int b, void (*print_callback)(int))
{
    int sum = a + b;
    print_callback(sum);
    return sum;
}

void console_print(int value)
{
    printf("%d\n", value);
}

void file_print(int value)
{
    FILE *fp = fopen(FILE_NAME, "w");
    fprintf(fp, "%d", value);
    fclose(fp);
}