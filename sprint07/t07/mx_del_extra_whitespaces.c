#include <stdbool.h>
#include <stdlib.h>

bool mx_isspace(char c);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
void mx_strdel(char **str);
char *mx_strtrim(const char *str);

char *mx_del_extra_whitespaces(const char *str) {
    char *temp = mx_strtrim(str);

    int words = 0;
    for (int i = 0; i < mx_strlen(temp); i++) {
        if (!mx_isspace(temp[i])) {
            words++;
        }
    }

    char *res = mx_strnew(words);
    
    mx_strdel(&temp);
    return res;
}
