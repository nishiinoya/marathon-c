#include "duplicate.h"

t_intarr *mx_del_dup_sarr(t_intarr *src) {
    if (src == NULL || src->arr == NULL || src->size <= 0) {
        return NULL;
    }

    for (int i = 0; i < src->size; i++) {
        for (int n = i + 1; n < src->size; n++) {
            if (src->arr[i] == src->arr[n]) {
                for (int j = n; j < src->size - 1; j++) {
                    src->arr[j] = src->arr[j + 1];
                }
                src->size--;
                if (src->arr[i] == src->arr[n]) {
                    n--;
                }
            }
        }
    }

    int *result_arr = mx_copy_int_arr(src->arr, src->size);

    t_intarr *result_struct = (t_intarr *)malloc(sizeof(t_intarr));
    if (result_struct == NULL) {
        free(result_arr);
        return NULL;
    }

    result_struct->arr = result_arr;
    result_struct->size = src->size;

    return result_struct;
}
