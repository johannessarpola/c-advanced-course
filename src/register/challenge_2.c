#include <stdio.h>
 


int sum(int num) {
    static int cur_sum = 0; // Keeps the value as it is static and is initialized only once
    cur_sum += num;
    return cur_sum;
}

int main() {
    printf("%d\n", sum(25));
    printf("%d\n", sum(15));
    printf("%d\n", sum(30));

    return 0;
}
