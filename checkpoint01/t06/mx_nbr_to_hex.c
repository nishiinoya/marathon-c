#include <stdio.h>
#include <stdlib.h>

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr == 0) {
        char *result = (char *)malloc(2);
        if (result == NULL) {
            return NULL;
        }
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    int len = 0;
    unsigned long temp = nbr;
    while (temp != 0) {
        temp /= 16;
        len++;
    }

    char *result = (char *)malloc(len + 1);
    if (result == NULL) {
        return NULL; 
    }

    for (int i = len - 1; i >= 0; i--) {
        int remainder = nbr % 16;
        if (remainder < 10) {
            result[i] = remainder + '0';
        } else {
            result[i] = remainder - 10 + 'a';
        }
        nbr /= 16;
    }

    result[len] = '\0';

    return result;
}
