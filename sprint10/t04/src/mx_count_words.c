#include "../inc/header.h"

int mx_count_words(const char *str) {
    bool is_word = 0;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_isspace(str[i])) {
            is_word = false;
        } else if (!is_word) {
            is_word = true;
            count++;
        }
    }

    return count;
}
