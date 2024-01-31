#include "mx_pow.c"
#include <math.h>
#include <stdio.h>

double mx_pow(double n, unsigned int pow);

int main() {
    printf("mx_pow: %f\n", mx_pow(2.5, 3));
    printf("pow: %f\n", pow(2.5, 3));
    return 0;
}
