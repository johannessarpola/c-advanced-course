#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int index = 10;  // Using an invalid index
    printf("Value at index %d: %d\n", index, arr[index]);  // Accessing an invalid index

    return 0;
}
