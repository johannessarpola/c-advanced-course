#include <stdio.h>
#include <stdlib.h>

int process(int i, int j) {
    int val = 0;
    #ifdef DEBUG
        fprintf(stderr, "process(%i,%i)\n", i, j);
    #endif

    val = i * j;
    #ifdef DEBUG
        fprintf(stderr, "return - %d\n", val);
    #endif
    return val; 
}
int main(int argc, char*argv[]) {

    int arg1 = 0, arg2 = 0;
    if(argc > 1)
        arg1 = atoi(argv[1]);
    if(argc == 3)
        arg2 = atoi(argv[2]);
    
    if(arg1 > 0 && arg2 > 0) {
        printf("%d\n", process(arg1, arg2));
    }

    return 0;
}