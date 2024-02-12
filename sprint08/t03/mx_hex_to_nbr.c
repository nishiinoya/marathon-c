#include "hex_to_nbr.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex == NULL || *hex == '\0') {
        return 0;
    }

    unsigned long base = 1;
    unsigned long result = 0;
    int size = 0;

    while (hex[size] != '\0') {
        size++;
    }

    for (int i = size - 1; i >= 0; i--) {
        if (mx_isdigit(hex[i])) {
            result += (hex[i] - '0') * base;
            base *= 16;
        } else if (mx_isupper(hex[i])) {
            result += (hex[i] - 'A' + 10) * base;
            base *= 16;
        } else if (mx_islower(hex[i])) {
            result += (hex[i] - 'a' + 10) * base;
            base *= 16;
        } else {
            return 0; 
        }
    }

    return result;
}
