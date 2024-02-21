#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 2){
        mx_printerr("usage: ./read_file [file_path]\n");
        return -1;
    }
    int file_open = open(argv[1], O_RDONLY);
    if (file_open < 0) {
        mx_printerr("error\n");
        return -1;
    }

    char c;

    while (read(file_open, &c, 1) > 0) {

        mx_printchar(c);
    }

    close(file_open);

    return 0;
}
