#include <stdio.h>

struct packed_struct {
    unsigned int: 3; // padding 3 bits
    unsigned int flag_1: 1;
    unsigned int flag_2: 1;
    unsigned int flag_3: 1;
    unsigned int type: 8;
    unsigned int index: 18;
};

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = 0; i < size; i++) {
        for (j = 0; j <= 7; j++) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

int main() {

    struct packed_struct something;
    something.flag_1 = 1;
    something.flag_2 = 1;
    something.flag_3 = 1;

    something.type = 2;
    printBits(sizeof(unsigned int), &something);

    return 0;
}