void mx_printchar(char c);

void print_splitter(char splitter[2]) {
    for (int i = 0; splitter[i]; i++) {
        mx_printchar(splitter[i]);
    }
}
void right_side(int c, int i, char splitter[2]) {
    for (int a = 0; a <= c - 1; a++) {
        if (a == i - 1) {
            mx_printchar('\\');
        } else {
            print_splitter(splitter);
        }
    }
}
void print_bottom(int lenght) {
    mx_printchar('/');
    for (int i = 0; i < 2 * lenght - 1; i++) {
        mx_printchar('_');
    }
    mx_printchar('\\');
    mx_printchar('|');
    mx_printchar('\n');
}

void mx_pyramid(int n) {
    int c = 0;
    int spaces = 0;
    int lenght = n - 1;

    if (n < 2 || n % 2 != 0) {
        return;
    } else {
        for (int i = 0; i < lenght; i++) {
            char splitter[] = " ";
            for (int b = 0; b < lenght - i; b++) {
                mx_printchar(' ');
            }
            for (c = 0; c <= i; c++) {
                if (c == 0)
                    mx_printchar('/');
                else {
                    print_splitter(splitter);
                }
            }
            if (i == 0) {
                mx_printchar('\\'); // top
                mx_printchar('\n');
                continue;
            }
            right_side(c, i, splitter);
            if (i - 1 < lenght / 2) {
                spaces = 0;
                for (int x = 0; x < i - 1; x++) {
                    spaces++;
                    if (i != 0)
                        mx_printchar(' ');
                }
                mx_printchar('\\'); // storona sprava
            } else {
                for (int y = 0; y < spaces; y++) {
                    print_splitter(splitter);
                }
                mx_printchar('|');
                spaces--;
            }
            mx_printchar('\n');
        }
        print_bottom(lenght);
        return;
    }
}
