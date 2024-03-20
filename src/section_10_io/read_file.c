#include <stdio.h>


int main() {
    char ch = '\0';
    FILE* fp;

    if((fp = fopen("file.txt", "r"))) {
        while((ch = (char) getc(fp)) != EOF) {
            printf("%c", ch);
        }
    }

    return 0;
}