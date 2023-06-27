#include <stdio.h>

int main() {
    // Register can only be used in local scope and not in global scope
    // X is stored in a register, not RAM, does not have memory address (can't use &)
    register int x;
    for (x = 0; x <= 15; x++)
    {
        printf("%d\n", x);
    }

    // Register can store pointer
    int y = 99;
    register int *ptr_y = &y;
    printf("%p: %d\n", ptr_y, *ptr_y);

    return 0;
}