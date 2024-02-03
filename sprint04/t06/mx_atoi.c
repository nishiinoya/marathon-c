#include <stdbool.h>

static bool mx_isspace(char c) {
    return (c == ' ' || c == '\t' ||
            c == '\n' || c == '\v' ||
            c == '\r' || c == '\f');
}

int mx_atoi(const char *str) {
    int n = 0;
    int sign = 1;

    while (mx_isspace(*str)) {
        ++str;
    }
    for (; *str == '-' || *str == '+'; ++str) {
        if (*str == '-') {
            sign *= -1;
        }
    }

    while (*str >= 48 && *str <= 57) {
        n = n * 10 + (*str++ - 48);
    }
    return n * sign;
}
