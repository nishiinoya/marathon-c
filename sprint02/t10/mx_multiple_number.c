#include <stdbool.h>

bool mx_multiple_number(int n, int mult) {
    if (n == 0) {
        return false;
    }
    return mult % n == 0;
}

