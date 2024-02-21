#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 2){
        mx_printerr("usage: ./mx_cp [source_file] [destination_file]\n");
        return -1;
    }
    int check = open(argv[1], O_RDONLY);
    if (check < 0) {
        mx_printerr("mx_cp: ");
        mx_printerr(argv[1]);
        mx_printerr(": No such file or directory\n");
        return -1;
    }
    char buf;
    int result = open(argv[2], O_CREAT | O_EXCL | O_WRONLY, S_IRUSR | S_IWUSR);
    while (read(check, &buf, 1)) {
        write(result, &buf, 1);
    }
    close(check);
    close(result);
    return 0;
}
