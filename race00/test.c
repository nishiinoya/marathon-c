#include "mx_printchar.c"

void mx_printchar(char c);

void horizontal_line(int n) {
    mx_printchar('+');
    for (int i = 0; i < 2 * n; i++) {
        mx_printchar('-');
    }
    mx_printchar('+');
}

int main() {
    int n = 4;

    if (n <= 1) {
        return -1;
    }

    for (int i = 0; i < n / 2 + 1; i++) {
        mx_printchar(' ');
    }
    horizontal_line(n);
    mx_printchar('\n');

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2 - i; j++) {
            mx_printchar(' ');
        }
        mx_printchar('/');
        for (int j = 0; j < 2 * n; j++) {
            mx_printchar(' ');
        }
        mx_printchar('/');

        for (int j = 0; j < i; j++) {
            mx_printchar(' ');
        }
        mx_printchar('|');
        mx_printchar('\n');
    }

    horizontal_line(n);
    for (int j = 0; j < n / 2; j++) {
        mx_printchar(' ');
    }
    mx_printchar('|');
    mx_printchar('\n');

    for (int i = 0; i < n; i++) {
        mx_printchar('|');
        for (int j = 0; j < 2 * n; j++) {
            mx_printchar(' ');
        }
        mx_printchar('|');

        if (i == n / 2 - 1 ) {
            for (int j = 0; j < n / 2 ; j++) {
                mx_printchar(' ');
            }
            mx_printchar('+');
        } else if (i > n / 2 - 1) {
            int k = n / 2;
            for (int j = k - 1; j > i - k; j--) {
                mx_printchar(' ');
            }
            mx_printchar('/');
        } else {
            for (int j = 0; j < n / 2; j++) {
                mx_printchar(' ');
            }
            mx_printchar('|');
        }
        mx_printchar('\n');
    }

    horizontal_line(n);
    mx_printchar('\n');

    return 0;
}
