#include <stdbool.h>
int mx_atoi(const char *str);
void mx_printchar(char c);
void mx_printint(int c);

bool is_valid_element(const char *str) {
    // Check if the element is valid
    while (*str) {
        if ((*str < '0' || *str > '9') && *str != '+' && *str != '-')
            return false;
        str++;
    }
    return true;
}
int main(int argc, char *argv[]) {
    int sum = 0; 
    for (int i = 1; i < argc; i++) {
        if (is_valid_element(argv[i])) {
            sum += mx_atoi(argv[i]);
        }
    }
    mx_printint(sum);
    mx_printchar('\n');
    return 0;
}
