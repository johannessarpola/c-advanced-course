#include <stdio.h>


int main() {
    char ch = '\0';
    int i = 3;
    while ((ch = (char) getc(stdin))) {
        printf("%c", ch);
        i--;
        if(i == 0) break;
    }

    return 0;
}