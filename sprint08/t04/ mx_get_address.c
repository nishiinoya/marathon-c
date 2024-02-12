#include "get_address.h"

char *mx_get_address(void *p){
    if (p == NULL) {
        return NULL;
    }

    unsigned long add = (unsigned long)p;
    char *hex_address = mx_nbr_to_hex(add);
    int len = mx_strlen(hex_address);
    char *result = mx_strnew(len + 2);
    if (hex_address == NULL || result == NULL) {
        return NULL;
    }
    result[0] = '0';
    result[1] = 'x';
    mx_strcpy(result + 2, hex_address);

    return result;
}
