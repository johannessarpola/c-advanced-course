#include <stdio.h>
#include <assert.h>

int main() {
    int a = 2;
    int b = 3;
    assert(a == 2); // Assert is a macro
    printf("first: %d == 2", a);
    assert(b == 3);
    printf("second: %d == 3", b);

    assert(a == b);
    printf("third a is not b");
    return 0;
}