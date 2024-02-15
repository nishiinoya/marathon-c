#include <stdlib.h>

char *mx_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    char *dup = (char *)malloc(len + 1);

    if (dup == NULL) {
        return NULL;
    }

    for (int i = 0; i <= len; i++) {
        dup[i] = str[i];
    }

    return dup;
}
