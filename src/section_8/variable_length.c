#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NBR 1
#define MAX_NBR 50

int sum2d(int rows, int cols, int arr[rows][cols]) {
    int sum = 0;
    // Print the filled two-dimensional array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    size_t rows = 0;
    size_t cols = 0;
 
    printf("Enter the number of row:");
    scanf("%zd", &rows);

    printf("Enter the number of columns:");
    scanf("%zd", &cols);

    int values[rows][cols];
    // Seed the random number generator with the current time
    srand(time(NULL));

    int i, j;
    // Fill the array with random integers from 1 to 50
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            values[i][j] = getRandomNumber(MIN_NBR, MAX_NBR);
        }
    }
    
    int total = sum2d(rows, cols, values);
    // Print the filled two-dimensional array
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%3d ", values[i][j]);
        }
        printf("\n");
    }
    printf("total was %d\n and average %f", total, (float) total / (rows * cols));
    return 0;
}