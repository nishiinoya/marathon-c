#include   <stdbool.h>
//#include "mx_is_prime.c"
#include <stdio.h>

bool mx_is_prime(int num);

int main(void) {
    printf("Is 41 prime? %s\n", mx_is_prime(-80) ? "Yes" : "No");
    return 0;
}
bool mx_is_prime(int num) {
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
