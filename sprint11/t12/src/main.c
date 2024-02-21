#include "../inc/list.h"

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 5) {
        mx_printerr("usage: ./playlist [file] [command] [args]\n");
        exit(0);
    }
    if (mx_strcmp(argv[2], "add") == 0 && argc == 5) {
        int file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
        if (file < 0) {
            mx_printerr("ERROR\n");
            exit(0);
        }
        char *temp = argv[3];
        while (*temp) {
            write(file, temp++, 1);
        }
        write(file, " - ", 3);

        temp = argv[4];
        while (*temp) {
            write(file, temp++, 1);
        }
        write(file, "\n", 1);

        if (close(file) < 0) {
            mx_printerr("ERROR\n");
            exit(0);
        }
    } else if (mx_strcmp(argv[2], "print") == 0 && argc == 3) {
        int file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
        if (file < 0) {
            mx_printerr("ERROR\n");
            exit(0);
        }
    }
}