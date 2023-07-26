#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NBR 1
#define MAX_NBR 50

struct s {
    int array_size;
    int array[]; // flexible array needs to be last in the struct
};

int sum(struct s *ptr) {
    int sum = 0;
    for (int i = 0; i < ptr->array_size; i++) {
        sum += ptr->array[i];
    }
    return sum;
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    size_t size = 0;
    struct s *ptr;

    printf("Enter the size:");
    scanf("%zd", &size);

    ptr = malloc(sizeof(struct s) + size * sizeof(int)); // The array as it is flexible will not count into sizeof()
                                                         // and that is why it needs to be added to memory alloc
    ptr->array_size = size;
    // Seed the random number generator with the current time
    srand(time(NULL));

    int i;
    // Fill the array with random integers from 1 to 50
    for (i = 0; i < size; i++) {
        ptr->array[i] = getRandomNumber(MIN_NBR, MAX_NBR);
        
    }
    
    int total = sum(ptr);
    // Print the filled two-dimensional array
    for (i = 0; i < size; i++) {
        printf("%d ", ptr->array[i]);   
    }
    printf("\n");
    printf("total was %d and average %f\n", total, (float) total / size);

    free(ptr);
    return 0;
}