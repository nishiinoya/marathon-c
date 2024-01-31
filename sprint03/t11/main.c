#include "mx_is_prime.c"
#include "mx_pow.c"
#include "mx_is_mersenne.c"
#include <stdbool.h>
#include <stdio.h>

bool mx_is_prime(int num);
double mx_pow(double n, unsigned int pow);
bool mx_is_mersenne(int n);
int main(void) {
    printf("Is 41 prime? %s\n", mx_is_mersenne(121) ? "Yes" : "No");
    return 0;
}
