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

    for (int line = 0; line < n / 2 + 1 + n + 2; line++) {
        int shift = n / 2 + 1;

        if (line == 0 || line == n / 2 + 1 || line == n / 2 + n + 3) {
            for (int i = 0; i < shift; i++)
                mx_printchar(' ');
            horizontal_line(n);
        }

        if (line > 0 && line < n / 2 + 1) {
            int back_shift = 0;
            for (int j = 0; j < shift - 1; j++)
                mx_printchar(' ');
            mx_printchar('/');
            for (int j = 0; j < 2 * n; j++)
                mx_printchar(' ');
            mx_printchar('/');
            for (int j = 0; j < back_shift; j++)
                mx_printchar(' ');
            mx_printchar('|');
        }

        if (line > n / 2 + 1 && line < n / 2 + n + 2) {
            int back_shift = line - (n / 2 + 2);
            mx_printchar('|');
            for (int j = 0; j < 2 * n; j++)
                mx_printchar(' ');
            mx_printchar('|');
            for (int j = 0; j < back_shift; j++)
                mx_printchar(' ');

            if (line == n / 2 + n + 1) {
                mx_printchar('+');
            } else if (line > n / 2 + n + 1) {
                mx_printchar('/');
            } else {
                mx_printchar('|');
            }
        }

        shift--;
        mx_printchar('\n');
    }

    return 0;
}
