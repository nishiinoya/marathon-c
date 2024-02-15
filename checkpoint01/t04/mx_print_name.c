#include <unistd.h>

void mx_printchar(char);
void mx_printint(int n);
void mx_printstr(const char *s);

int main(int argc, char *argv[]) {
    mx_printstr(argv[0]);
    mx_printchar('\n');
    mx_printint(argc);
    mx_printchar('\n');
    return 0;
}

void mx_printchar(char c) {
    write(1, &c, 1);
}

void mx_printstr(const char *s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    write(1, s, length);
}

void mx_printint(int n) {
    if (n == 0) {
        mx_printchar('0');
        return;
    }
    if (n < 0) {
        mx_printchar('-');
        n = -n;
    }

    int divisor = 1;
    while (n / divisor > 9) {
        divisor *= 10;
    }

    while (divisor > 0) {
        mx_printchar((n / divisor) + '0');
        n %= divisor;
        divisor /= 10;
    }
}
