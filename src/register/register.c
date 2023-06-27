#include <stdio.h>

int main() {
    // X is stored in a register, not RAM, does not have memory address (can't use &)
    register int x;
    for (x = 0; x <= 15; x++)
    {
        printf("%d\n", x);
        /* code */
    }
    return 1;
}