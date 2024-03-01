#include "../inc/header.h"

int main(int argc, char *argv[]) {
    char c;
    if (argc == 1) {
        while (read(0, &c, 1)) {
            write(1, &c, 1);
        }
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);
        if (errno != 0) {
            mx_printerr("mx_cat: ");
            mx_printerr(argv[1]);
            mx_printerr(": ");
            mx_printerr(strerror(errno));
            mx_printerr("\n");
            exit(-1);
        }
        while (read(fd, &c, 1) > 0) {
            write(1, &c, 1);
        }
        close(fd);
    }
    return 0;
}
