#include <stdlib.h>

char *mx_strnew(const int size);
int mx_count_words(const char *str, char delimiter);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_strdel(char **str);

char **mx_strsplit(char const *s, char c) {
    if (s == NULL) {
        return NULL;
    }
    int words_count = mx_count_words(s, c);
    if (words_count <= 0) {
        return NULL;
    }

    char **arr = (char **)malloc(words_count + 1);

    if (arr == NULL) {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < words_count; i++) {
        int len = 0;
        int start = 0;

        while (s[j]) {
            if (s[j] != c) {
                len++;
                if (start == 0) {
                    start = j;
                }
            } else if (len && s[j] == c) {
                break;
            }
            j++;
        }

        char *word = mx_strnew(len);

        if (word == NULL) {
            for (int k = 0; k < i; k++) {
                mx_strdel(&arr[k]);
            }
            free(arr);
            return NULL;
        }

        mx_strncpy(word, &s[start], len);
        arr[i] = word;
    }

    arr[words_count] = NULL;
    return arr;
}
