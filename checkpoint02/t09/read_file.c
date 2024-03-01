#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void mx_printerr(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    write(2, s, len);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./read_file [file_path]\n");
        return -1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        mx_printerr("error\n");
        return -1;
    }
    char element;
    while (read(fd, &element, 1) != 0) {
        write(1, &element, 1);
    }
    if (close(fd) < 0) {
        mx_printerr("error\n");
        return -1;
    }
    return 0;
}
