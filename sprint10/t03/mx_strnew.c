#include "file_to_str.h"

char *mx_strnew(const int size) {
    if (size < 1) {
        return NULL;
    }
    char *create = (char *)malloc(size + 1);

    if (create == NULL)
        return NULL;

    for (int i = 0; i < size; i++) {
        create[i] = '\0';
    }

    return create;
}
