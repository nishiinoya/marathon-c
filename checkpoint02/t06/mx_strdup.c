#include <stdio.h>
#include <stdlib.h>
char *mx_strcpy(char *dst, const char *src) {
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    dst[i] = '\0';
    return dst;
}

char *mx_strnew(const int size) {
    if (size < 0) {
        return NULL;
    }
    char *str = (char *)malloc((size + 1) * sizeof(char));
    if (str == NULL) {
        return NULL;
    }
    for (int i = 0; i <= size; i++) {
        str[i] = '\0';
    }
    return str;
}

char *mx_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    char *temp = mx_strnew(len);
    return mx_strcpy(temp, str);
}
