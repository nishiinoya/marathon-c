void mx_printchar(char c);
void horizontal_line(int HORIZONTAL_LENGTH);
void upper_side(int DIAGONAL_LENGTH, int HORIZONTAL_LENGTH);
void print_front(int HORIZONTAL_LENGTH);
void lower_side(int row, int HORIZONTAL_LENGTH, int VERTICAL_LENGTH);

void mx_cube(int n) {
    const int SHIFT_UPPER_BACK = n / 2 + 1;
    const int HORIZONTAL_LENGTH = 2 * n;
    const int DIAGONAL_LENGTH = n / 2;
    const int VERTICAL_LENGTH = n;

    if (n <= 1) {
        return;
    }

    for (int i = 0; i < SHIFT_UPPER_BACK; i++) {
        mx_printchar(' ');
    }
    horizontal_line(HORIZONTAL_LENGTH);
    mx_printchar('\n');
    upper_side(DIAGONAL_LENGTH, HORIZONTAL_LENGTH);
    horizontal_line(HORIZONTAL_LENGTH); // UPPER_FRONT HORIZONTAL
    for (int j = 0; j < DIAGONAL_LENGTH; j++) {
        mx_printchar(' ');
    }
    mx_printchar('|');
    mx_printchar('\n');

    for (int row = 0; row < VERTICAL_LENGTH; row++) {
        print_front(HORIZONTAL_LENGTH);

        int back_corner_idx = VERTICAL_LENGTH - DIAGONAL_LENGTH - 1;

        if (row < back_corner_idx) {
            for (int j = 0; j < DIAGONAL_LENGTH; j++) {
                mx_printchar(' ');
            }
            mx_printchar('|');
        } else if (row == back_corner_idx) {
            for (int j = 0; j < DIAGONAL_LENGTH; j++) {
                mx_printchar(' ');
            }
            mx_printchar('+');
        } else {
            lower_side(row, HORIZONTAL_LENGTH, VERTICAL_LENGTH);
        }
        mx_printchar('\n');
    }

    horizontal_line(HORIZONTAL_LENGTH);
    mx_printchar('\n');

    return;
}


void horizontal_line(int HORIZONTAL_LENGTH) {
    mx_printchar('+');
    for (int i = 0; i < HORIZONTAL_LENGTH; i++) {
        mx_printchar('-');
    }
    mx_printchar('+');
}

void print_front(int HORIZONTAL_LENGTH) {
    mx_printchar('|');
    for (int j = 0; j < HORIZONTAL_LENGTH; j++) {
        mx_printchar(' ');
    }
    mx_printchar('|');
}

void lower_side(int row, int HORIZONTAL_LENGTH, int VERTICAL_LENGTH) {
    int start_side_idx = HORIZONTAL_LENGTH + 1;
    int end_side_idx = start_side_idx + VERTICAL_LENGTH - row - 1;
    for (int i = start_side_idx; i < end_side_idx; i++) {
        mx_printchar(' ');
    }
    mx_printchar('/');
}
void upper_side(int DIAGONAL_LENGTH, int HORIZONTAL_LENGTH) {
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
}
