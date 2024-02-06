#include <stdbool.h>

bool mx_isdigit(int c);
bool mx_isspace(char c);
int mx_atoi(const char *s);
void mx_printchar(char c);
void mx_printint(int n);
int mx_strlen(const char *s);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 0;
    }
    int start_val = mx_atoi(argv[1]);
    int end_val = mx_atoi(argv[2]);
    if (start_val > 9 || start_val < 1 || end_val > 9 || end_val < 1) {
        return 0;
    }
    if (start_val > end_val) {
        int temp = start_val;
        start_val = end_val;
        end_val = temp;
    }
    for (int i = start_val; i < end_val + 1; i++) {
        for (int j = start_val; j < end_val + 1; j++) {
            mx_printint(i * j);
            if (j < end_val)
                mx_printchar('\t');
        }
        mx_printchar('\n');
    }
    return 0;
}
