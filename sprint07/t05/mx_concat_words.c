#include <stdlib.h>
void mx_strdel(char **str);
char *mx_strcat(char *s1, const char *s2);
char *mx_strdup(const char *str);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);
char *mx_concat_words(char **words) {
    if (words == NULL) {
        return NULL;}
    int spaces = 0;
    int length = 0;
    for (int i = 0; words[i] != NULL; i++) {
        spaces++;
    }
    if(spaces > 1) {
        length = spaces - 1;
    }
    char *result = mx_strnew(length);
    if (result == NULL)
        return NULL;
    for (int i = 0; words[i] != NULL; i++) {
        mx_strcat(result, words[i]);
        if (words[i + 1] != NULL) {
            mx_strcat(result, " ");
        }
    }
    return result;
}
