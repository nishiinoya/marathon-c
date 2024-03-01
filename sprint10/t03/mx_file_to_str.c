#include "file_to_str.h"

char *mx_file_to_str(const char *filename) {
    if (filename == NULL) {
        return NULL;
    }
    int file_op = open(filename, O_RDONLY);
    if (file_op < 0) {
        return NULL;
    }
    int len = 0;
    char buffer;
    while (read(file_op, &buffer, 1)) {
        len++;
    }
    if (close(file_op) < 0) {
        return NULL;
    }
    file_op = open(filename, O_RDONLY);
    if (file_op < 0) {
        return NULL;
    }
    char *file_str = mx_strnew(len);
    for (int i = 0; read(file_op, &buffer, 1); i++) {
        file_str[i] = buffer;
    }

    if (close(file_op) < 0) {
        return NULL;
    }
    return file_str;
}
