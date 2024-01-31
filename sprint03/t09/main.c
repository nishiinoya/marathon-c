#include "mx_is_narcissistic.c"
#include "mx_pow.c"
#include <stdbool.h>
#include <stdio.h>
double mx_pow(double n, unsigned int pow);
bool mx_is_narcissistic(int num);
int main(void) {
    printf("Is 153 narcissistic? %s\n", mx_is_narcissistic(-127) ? "Yes" : "No");
    printf("Is 1634 narcissistic? %s\n", mx_is_narcissistic(1634) ? "Yes" : "No");
    printf("Is 9474 narcissistic? %s\n", mx_is_narcissistic(9474) ? "Yes" : "No");
    printf("Is 12345 narcissistic? %s\n", mx_is_narcissistic(12345) ? "Yes" : "No");

    return 0;
}
