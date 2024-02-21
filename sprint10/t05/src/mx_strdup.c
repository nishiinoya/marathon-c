#include "../inc/header.h"

char *mx_strdup(const char *str) {
    int size_str = mx_strlen(str);
    char *dup = mx_strnew(size_str + 1);

    if (dup == NULL) {
        return NULL; 
    }

    return mx_strcpy(dup, str);
}
