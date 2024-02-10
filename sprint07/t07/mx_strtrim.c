#include <stdbool.h>
#include <stdlib.h>

bool mx_isspace(char c);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
void mx_strdel(char **str);
char *mx_strcpy(char *dst, const char *src);

char *mx_strtrim(const char *str) {
    if (str == NULL || *str == '\0') {
        return NULL;
    }

    int len = mx_strlen(str);
    int size_res = 0;

    for (int i = 0; i < len; i++) {
        if (!mx_isspace(str[i])) {
            size_res++;
        }
    }

    if (size_res == 0) {
        char *result = mx_strnew(0);
        return result;
    }

    char *result = mx_strnew(size_res);
    if (result == NULL) {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!mx_isspace(str[i])) {
            result[j] = str[i];
            j++;
        }
    }

    return result;
}
