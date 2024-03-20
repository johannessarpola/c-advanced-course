#define NDEBUG // disables runtime assertions if before #include <assert.h>

#include <stdio.h>
#include <assert.h>


int main() {
    int a = 2;
    int b = 3;
    assert(a == b);
    printf("third a is not b");
    return 0;
}