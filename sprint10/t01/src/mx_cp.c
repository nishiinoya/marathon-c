#include "../inc/header.h"
int main(int argc, char *argv[]) {
    if (argc != 3) {
        mx_printerr("usage: ./mx_cp [source_file] [destination_file]\n");
        return -1;
    }
    int file_open1 = open(argv[1], O_RDONLY);
    if (errno != 0) {
        mx_printerr("mx_cp: ");
        mx_printerr(argv[1]);
        mx_printerr(": ");
        mx_printerr(strerror(errno));
        mx_printerr("\n");
        return -1;
    }
    int file_open2 = open(argv[2], O_CREAT | O_EXCL | O_WRONLY, S_IRUSR | S_IWUSR);
    char c;
    while (read(file_open1, &c, 1) > 0) {
        write(file_open2, &c, 1);
    }
    close(file_open1);
    close(file_open2);
    return 0;
}
