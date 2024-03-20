#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG_ON
int Debug = 2;
#define DEBUG(level, fmt, ...) \
    if(Debug >= level) \
         fprintf(stderr, fmt, __VA_ARGS__);
#else
    #define DEBUG(level, fmt, ...)
#endif

int process(int i, int j) {
    int val = 0;
    DEBUG(2, "process(%i,%i)\n", i, j);

    val = i * j;
    DEBUG(2, "return - %d\n", val);
    return val; 
}
int main(int argc, char*argv[]) {
    DEBUG(4, "useless %i\n", 1);

    int arg1 = 0, arg2 = 0;
    if(argc > 1)
        arg1 = atoi(argv[1]);
    if(argc == 3)
        arg2 = atoi(argv[2]);
    
    DEBUG(1, "args: %i, %i\n", arg1, arg2);
    if(arg1 > 0 && arg2 > 0) {
        printf("%d\n", process(arg1, arg2));
    }

    return 0;
}