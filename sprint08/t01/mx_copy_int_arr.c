#include "duplicate.h"

int *mx_copy_int_arr(const int *src, int size) {
    if (src == NULL || size < 0) {
        return NULL;
    }

    int *copy_src = (int *)malloc(size * 4);
    for (int i = 0; i < size; i++) {
        copy_src[i] = src[i];
    }
    return copy_src;
}
