#include <stdlib.h>

char *mx_strcpy(char *dst, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

char *mx_strnew(const int size) {
    char *str = (char *)malloc(size + 1);
    if (str == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        str[i] = '\0';
    }
    str[size] = '\0';

    return str;
}

int mx_strlen(const char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

char *mx_strdup(const char *str) {
    int size_str = mx_strlen(str);
    char *dup = mx_strnew(size_str + 1);

    if (dup == NULL) {
        return NULL; 
    }

    return mx_strcpy(dup, str);
}
