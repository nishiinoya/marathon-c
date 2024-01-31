#include "mx_printchar.c"
#define N 9
#define SHIFT_UPPER_BACK (N / 2 + 1)
#define HORIZONTAL_LENGTH (2 * N)
#define DIAGONAL_LENGTH (N / 2)
#define VERTICAL_LENGTH N

void mx_printchar(char c);

void horizontal_line(int n) {
    mx_printchar('+');
    for (int i = 0; i < HORIZONTAL_LENGTH; i++) {
        mx_printchar('-');
    }
    mx_printchar('+');
}

void print_front_side_row() {
    mx_printchar('|');
    for (int j = 0; j < HORIZONTAL_LENGTH; j++) {
        mx_printchar(' ');
    }
    mx_printchar('|');
}

void print_lowe_side(int row) {
    int start_side_idx = HORIZONTAL_LENGTH + 1; 
    int end_side_idx = start_side_idx + VERTICAL_LENGTH - row - 1;
    for (int i = start_side_idx; i < end_side_idx; i++) {
        mx_printchar(' ');
    }
    mx_printchar('/');
}

int main() {
    int n = N;

    if (n <= 1) {
        return -1;
    }

    for (int i = 0; i < SHIFT_UPPER_BACK; i++) {
        mx_printchar(' ');
    }
    horizontal_line(n);
    mx_printchar('\n');

    for (int i = 0; i < DIAGONAL_LENGTH; i++) {
        for (int j = 0; j < DIAGONAL_LENGTH - i; j++) {
            mx_printchar(' ');
        }
        mx_printchar('/');
        for (int j = 0; j < HORIZONTAL_LENGTH; j++) {
            mx_printchar(' ');
        }
        mx_printchar('/');

        for (int j = 0; j < i; j++) {
            mx_printchar(' ');
        }
        mx_printchar('|');
        mx_printchar('\n');
    }

    horizontal_line(n); // UPPER_FRONT HORIZONTAL
    for (int j = 0; j < DIAGONAL_LENGTH; j++) {
        mx_printchar(' ');
    }
    mx_printchar('|');
    mx_printchar('\n');

    for (int row = 0; row < VERTICAL_LENGTH; row++) {
        print_front_side_row();

        int back_corner_vertical_index = VERTICAL_LENGTH - DIAGONAL_LENGTH - 1;

        if (row < back_corner_vertical_index) {
            for (int j = 0; j < DIAGONAL_LENGTH; j++) {
                mx_printchar(' ');
            }
            mx_printchar('|');
        } else if (row == back_corner_vertical_index) {
            for (int j = 0; j < DIAGONAL_LENGTH; j++) {
                mx_printchar(' ');
            }
            mx_printchar('+');
        } else {
            print_lowe_side(row);
        }
        mx_printchar('\n');
    }

    horizontal_line(n);
    mx_printchar('\n');

    return 0;
}

