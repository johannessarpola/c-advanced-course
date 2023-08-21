#include <stdio.h>


int main() {
    int ch = '\0';
    // ctrl+d to EOF
    while ((ch = getchar()) != EOF) {
        printf("%c", ch);
    }

    return 0;
}