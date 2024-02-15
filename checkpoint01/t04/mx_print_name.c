#include <unistd.h>

void mx_printchar(char c) {
    write(1, &c, 1);
}

void mx_printstr(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    write(1, s, len);
}

int main(int argc, char *argv[]) {
    mx_printstr(argv[0]);
    mx_printchar('\n');

    char sign = (argc < 0) ? '-' : '\0';

    if (sign != '\0') {
        mx_printchar(sign);
        argc = -argc; 
    }

    int divisor = 1;
    while (argc / divisor > 9) {
        divisor *= 10;
    }

    while (divisor > 0) {
        mx_printchar((argc / divisor) + '0');
        argc %= divisor;
        divisor /= 10;
    }
    mx_printchar('\n');

    return 0;
}
