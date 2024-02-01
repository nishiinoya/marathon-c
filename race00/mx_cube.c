void mx_printchar(char c);
void horizontal_line(int horz_lgth);
void upper_side(int diag_lgth, int horz_lgth);
void corner(int vert_lgth, int horz_lgth, int diag_lgth);
void print_spaces(int lgth);

void mx_cube(int n) {
    const int horz_lgth = 2 * n;
    const int diag_lgth = n / 2;
    const int vert_lgth = n;
    if (n <= 1)
        return;
    print_spaces(n / 2 + 1);
    horizontal_line(horz_lgth);
    mx_printchar('\n');
    upper_side(diag_lgth, horz_lgth);
    horizontal_line(horz_lgth);
    for (int j = 0; j < diag_lgth; j++) {
        mx_printchar(' ');
    }
    mx_printchar('|');
    mx_printchar('\n');
    corner(vert_lgth, horz_lgth, diag_lgth);
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
void upper_side(int diag_lgth, int horz_lgth) {
    for (int i = 0; i < diag_lgth; i++) {
        print_spaces(diag_lgth - i);
        mx_printchar('/');
        print_spaces(horz_lgth);
        mx_printchar('/');
        print_spaces(i);
        mx_printchar('|');
        mx_printchar('\n');
    }
}

void corner(int vert_lgth, int horz_lgth, int diag_lgth) {
    for (int row = 0; row < vert_lgth; row++) {
        mx_printchar('|');
        print_spaces(horz_lgth);
        mx_printchar('|');
        int corner_i = vert_lgth - diag_lgth - 1;
        if (row < corner_i) {
            print_spaces(diag_lgth);
            mx_printchar('|');
        } else if (row == corner_i) {
            print_spaces(diag_lgth);
            mx_printchar('+');
        } else {
            int start_i = horz_lgth + 1;
            int end_i = start_i + vert_lgth - row - 1;
            for (int i = start_i; i < end_i; i++) {
                mx_printchar(' ');
            }
            mx_printchar('/');
        }
        mx_printchar('\n');
    }
}

void print_spaces(int lgth) {
    for (int j = 0; j < lgth; j++) {
        mx_printchar(' ');
    }
}
