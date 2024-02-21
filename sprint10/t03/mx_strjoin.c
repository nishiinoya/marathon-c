#include "file_to_str.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if(s1 == NULL) {
        return mx_strdup(s2);
    }
    if (s1 == NULL) {
        return mx_strdup(s1);
    }
    if (s1 == NULL && s2 == NULL) {
        return NULL;
    }
    int size_res = mx_strlen(s1) + mx_strlen(s2);
    char *result = mx_strnew(size_res);
    result = mx_strcat(result, s1);
    result = mx_strcat(result, s2);
    return result;
}
