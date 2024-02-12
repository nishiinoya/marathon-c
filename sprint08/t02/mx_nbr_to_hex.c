#include "nbr_to_hex.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr == 0) {
        return mx_strnew(1);
    }

    int len = 0;
    unsigned long temp = nbr;
    while (temp != 0) {
        temp /= 16;
        len++;
    }

    char *result = mx_strnew(len);
    if (result == NULL) {
        return NULL;
    }

    for (int i = len - 1; i >= 0; i--) {
        int ost = nbr % 16;
        if (ost < 10) {
            result[i] = ost + '0';
        } else {
            result[i] = ost - 10 + 'a';
        }
        nbr /= 16;
    }

    return result;
}
