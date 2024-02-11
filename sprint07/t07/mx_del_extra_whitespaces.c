#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool mx_isspace(char c);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
void mx_strdel(char **str);
char *mx_strtrim(const char *str);
char *mx_strncpy(char *dst, const char *src, int len);

char *mx_del_extra_whitespaces(const char *str) {
    char *temp = mx_strtrim(str);

    int len = mx_strlen(temp);
    if (len == 0) {
        return temp;
    }

    char *result = mx_strnew(len + 1);
    if (result == NULL) {
        return NULL;
    }

    int j = 0;
    bool space_flg = true;

    for (int i = 0; i < len; i++) {
        if (!mx_isspace(temp[i])) {
            result[j] = temp[i];
            j++;
            space_flg = false;
        } else {
            if (!space_flg) {
                result[j] = ' ';
                j++;
                space_flg = true;
            }
        }
    }

    result[j] = '\0';

    mx_strdel(&temp);

    return result;
}
