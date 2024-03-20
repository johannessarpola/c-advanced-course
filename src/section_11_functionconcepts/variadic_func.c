//
// Created by johan on 22/08/2023.
//
#include "stdarg.h"
#include "stdio.h"

double average(double a, double b, ...);
double sum(int num_args, ...);
int main() {

    double d = sum(5, 2.5, 10.0, 2.5, 5.0, 1.25);
    printf("sum is: %.2f\n", d);

    double avg = average(5.0, 5.0, 10.0, 30.0, 2.5, 0.0);
    printf("avg is: %.2f\n", avg);

    return 0;
}

// define num arguments on how many to sum
double sum(int num_args, ...) {
    va_list ap;
    va_start(ap, num_args);

    double v = 0;
    for (int i = 0; i < num_args; ++i) {
        v+= va_arg(ap, double);
    }

    va_end(ap);
    return v;
}

// counts until 0.0 is found, 0.0 = sentinel value
double average(double a, double b, ...) {
    va_list ap;
    va_start(ap, b);

    int count = 2;
    double sum = a + b, value = 0.0;

    while((value = va_arg(ap, double)) != 0.0) {
        sum += value;
        ++count;
    }

    va_end(ap);
    return sum/count;
}