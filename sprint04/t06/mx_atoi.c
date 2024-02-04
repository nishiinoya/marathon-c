#include <stdbool.h>

bool mx_isspace(char c);
bool mx_isdigit(int c);

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

    while (mx_isdigit(*str)) {
        n = n * 10 + (*str++ - 48);
    }
    return n * sign;
}
