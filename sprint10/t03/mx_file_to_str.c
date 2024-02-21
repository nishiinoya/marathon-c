#include "file_to_str.h"

char *mx_file_to_str(const char *filename) {
    if (filename == NULL) {
        return NULL;
    }
    int check = open(filename, O_RDONLY);
    if (check < 0) {
        return NULL;
    }
    int length = 0;
    char buf;
    while (read(check, &buf, 1)) {
        length++;
    }
    if (close(check) < 0) {
        return NULL;
    }
    check = open(filename, O_RDONLY);
    if (check < 0) {
        return NULL;
    }
    char *str = mx_strnew(length);
    for (int i = 0; read(check, &buf, 1); i++) {
        str[i] = buf;
    }
    if (close(check) < 0) {
        return NULL;
    }
    return str;
}
