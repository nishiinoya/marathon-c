#include <stdbool.h>

double mx_pow(double n, unsigned int pow);

bool mx_is_narcissistic(int num) {
    int i = 0;
    int sum = 0;
    int num_1 = num;
    while (num_1 != 0) {
        num_1 /= 10;
        i++;
    }
    num_1 = num;
    while (num_1 > 0) {
        sum += mx_pow((num_1 % 10), i);
        num_1 /= 10;
    }
    return sum == num;
}
