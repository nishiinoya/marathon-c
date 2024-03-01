#include "../inc/list.h"

void remove_func(char *argv[]) {
    int file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
    if (file < 0) {
        mx_printerr("ERROR\n");
        exit(0);
    }
    int index = mx_atoi(argv[3]);
    int max_count = 0, symbols = 0, count = 0;
    char buffer;

    while (read(file, &buffer, 1)) {
        if (buffer == '\n')
            max_count++;
        if (index == max_count)
            continue;
        symbols++;
    }
    if (close(file) < 0) {
        mx_printerr("ERROR\n");
        exit(0);
    }
    if (index < 0 || index >= max_count) {
        mx_printerr("ERROR\n");
        exit(0);
    }
    char *arr = (char *)malloc(symbols);
    file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
    if (file < 0) {
        mx_printerr("ERROR\n");
        exit(0);
    }
    int i = 0;
    while (read(file, &buffer, 1)) {
        if (buffer == '\n')
            count++;
        if (index == count)
            continue;
        arr[i++] = buffer;
    }
    while (arr[i])
        arr[i++] = '\0';
    if (close(file) < 0) {
        mx_printerr("ERROR\n");
        exit(0);
    }
    if (remove(argv[1]) < 0) {
        mx_printerr("ERROR\n");
        exit(0);
    }
    file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
    if (index == 0)
        write(file, arr + 1, mx_strlen(arr + 1));
    else
        write(file, arr, mx_strlen(arr));
    if (close(file) < 0) {
        mx_printerr("ERROR\n");
        exit(0);
    }
    free(arr);
    arr = NULL;
}
void print_func(char *argv[]) {
    int file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
    if (file < 0) {
        mx_printerr("ERROR\n");
        exit(0);
    }
    int max_count = 0, count = 1;
    char buffer;

    while (read(file, &buffer, 1))
        if (buffer == '\n')
            max_count++;

    if (close(file) < 0) {
        mx_printerr("ERROR\n");
        exit(0);
    }
    file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
    if (file < 0) {
        mx_printerr("ERROR\n");
        exit(0);
    }

    mx_printstr("0. ");
    while (read(file, &buffer, 1)) {
        if (buffer == '\n' && count < max_count) {
            mx_printchar('\n');
            mx_printint(count++);
            mx_printstr(". ");
            continue;
        }
        write(1, &buffer, 1);
    }
    if (close(file) < 0) {
        mx_printerr("ERROR\n");
        exit(0);
    }
}
void add_func(char *argv[]) {
    int file = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
    char *temp = argv[3];
    if (file < 0) {
        mx_printerr("ERROR\n");
        exit(0);
    }

    while (*temp)
        write(file, temp++, 1);
    write(file, " - ", 3);

    temp = argv[4];
    while (*temp)
        write(file, temp++, 1);
    write(file, "\n", 1);

    if (close(file) < 0) {
        mx_printerr("ERROR\n");
        exit(0);
    }
}
