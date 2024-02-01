void mx_printchar(char c);
void horizontal_line(int horz_lgth);
void upper_side(int diag_lgth, int horz_lgth);
void print_front(int horz_lgth);
void lower_side(int row, int horz_lgth, int vert_lgth);

void mx_cube(int n) {
    const int horz_lgth = 2 * n;
    const int diag_lgth = n / 2;
    const int vert_lgth = n;
    if (n <= 1) return;
    for (int i = 0; i < n / 2 + 1; i++) {
        mx_printchar(' ');
    }
    horizontal_line(horz_lgth);
    mx_printchar('\n');
    upper_side(diag_lgth, horz_lgth);
    horizontal_line(horz_lgth);
    for (int j = 0; j < diag_lgth; j++) {
        mx_printchar(' ');
    }
    mx_printchar('|');
    mx_printchar('\n');
    for (int row = 0; row < vert_lgth; row++) {
        print_front(horz_lgth);
        int corner_i = vert_lgth - diag_lgth - 1;
        if (row < corner_i) {
            for (int j = 0; j < diag_lgth; j++) {
                mx_printchar(' ');
            }
            mx_printchar('|');
        } else if (row == corner_i) {
            for (int j = 0; j < diag_lgth; j++) {
                mx_printchar(' ');
            }
            mx_printchar('+');
        } else {
            lower_side(row, horz_lgth, vert_lgth);
        }
        mx_printchar('\n');
    }
    horizontal_line(horz_lgth);
    mx_printchar('\n');
}

void horizontal_line(int horz_lgth) {
    mx_printchar('+');
    for (int i = 0; i < horz_lgth; i++) {
        mx_printchar('-');
    }
    mx_printchar('+');
}

void print_front(int horz_lgth) {
    mx_printchar('|');
    for (int j = 0; j < horz_lgth; j++) {
        mx_printchar(' ');
    }
    mx_printchar('|');
}

void lower_side(int row, int horz_lgth, int vert_lgth) {
    int start_i = horz_lgth + 1;
    int end_i = start_i + vert_lgth - row - 1;
    for (int i = start_i; i < end_i; i++) {
        mx_printchar(' ');
    }
    mx_printchar('/');
}
void upper_side(int diag_lgth, int horz_lgth) {
    for (int i = 0; i < diag_lgth; i++) {
        for (int j = 0; j < diag_lgth - i; j++) {
            mx_printchar(' ');
        }
        mx_printchar('/');
        for (int j = 0; j < horz_lgth; j++) {
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
