//
// Created by johan on 22/08/2023.
//
#include "stdarg.h"
#include "stdio.h"
#include "math.h"

double stddev(int num_args, ...);
int main() {

    double d = stddev(5, 2.5, 10.0, 2.5, 5.0, 1.25);
    printf("stddev is: %.2f\n", d);

    return 0;
}

double stddev(int num_args, ...) {
    va_list ap, ap_copy;
    va_start(ap, num_args);
    va_copy(ap_copy, ap);

    double sum = 0;
    for (int i = 0; i < num_args; ++i) {
        double num = va_arg(ap, double);
        sum += num;
    }

    double mean = sum / num_args;
    double sum_sq_diff = 0;

    for (int i = 0; i < num_args; ++i) {
        double num = va_arg(ap_copy, double);
        sum_sq_diff += (num - mean) * (num - mean);
    }

    va_end(ap);
    va_end(ap_copy);

    return sqrt(sum_sq_diff / num_args);
}