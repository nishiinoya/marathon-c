void mx_printchar(char c);
void horizontal_line(int horz_len);
void upper_side(int diag_len, int horz_len);
void corner(int vert_len, int horz_len, int diag_len);
void print_spaces(int len);

void mx_cube(int n) {
    const int horz_len = 2 * n;
    const int diag_len = n / 2;
    const int vert_len = n;
    if (n <= 1)
        return;
    print_spaces(n / 2 + 1);
    horizontal_line(horz_len);
    mx_printchar('\n');
    upper_side(diag_len, horz_len);
    horizontal_line(horz_len);
    for (int j = 0; j < diag_len; j++) {
        mx_printchar(' ');
    }
    mx_printchar('|');
    mx_printchar('\n');
    corner(vert_len, horz_len, diag_len);
    horizontal_line(horz_len);
    mx_printchar('\n');
}

void horizontal_line(int horz_len) {
    mx_printchar('+');
    for (int i = 0; i < horz_len; i++) {
        mx_printchar('-');
    }
    mx_printchar('+');
}
void upper_side(int diag_len, int horz_len) {
    for (int i = 0; i < diag_len; i++) {
        print_spaces(diag_len - i);
        mx_printchar('/');
        print_spaces(horz_len);
        mx_printchar('/');
        print_spaces(i);
        mx_printchar('|');
        mx_printchar('\n');
    }
}

void corner(int vert_len, int horz_len, int diag_len) {
    for (int row = 0; row < vert_len; row++) {
        mx_printchar('|');
        print_spaces(horz_len);
        mx_printchar('|');
        int corner_i = vert_len - diag_len - 1;
        if (row < corner_i) {
            print_spaces(diag_len);
            mx_printchar('|');
        } else if (row == corner_i) {
            print_spaces(diag_len);
            mx_printchar('+');
        } else {
            int start_i = horz_len + 1;
            int end_i = start_i + vert_len - row - 1;
            for (int i = start_i; i < end_i; i++) {
                mx_printchar(' ');
            }
            mx_printchar('/');
        }
        mx_printchar('\n');
    }
}

void print_spaces(int len) {
    for (int j = 0; j < len; j++) {
        mx_printchar(' ');
    }
}
