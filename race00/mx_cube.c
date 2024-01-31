#include "mx_printchar.c"

void mx_printchar(char c);

void horizontal_line(int n, int size_line) {
    mx_printchar('+');
    for (int i = 0; i < size_line; i++) {
        mx_printchar('-');
    }
    mx_printchar('+');
}
void shift_spaces(int n, int shift){
    for (int i = 0; i < shift; i++) {
        mx_printchar(' ');
    }
}
void print_slash(int n, int size_slash) {
    for (int j = 0; j < size_slash - i; j++) {
        mx_printchar(' ');
    }
    mx_printchar('/');
    for (int j = 0; j < 2 * n; j++) {
        mx_printchar(' ');
    }
    mx_printchar('/');
}


int main() {
    int n = 4;
    int shift = n / 2 + 1;
    int size_line = 2 * n;
    int size_slash = n / 2;

    if (n <= 1) {
        return -1;
    }
    shift_spaces(n, shift);
    horizontal_line(n, size_line);
    mx_printchar('\n');
    print_slash(n, size_slash);
}