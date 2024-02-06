#include <stdio.h>

int mx_atoi(const char *s);
void mx_printchar(char c);
void mx_printint(int n);

void dec_to_binary(int n) {
    for (int i = 31; i >= 0; i--) {
        int k = n >> i; 
        if (k & 1)
            mx_printint(1);
        else
            mx_printint(0);
    }
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        int num = mx_atoi(argv[i]);
        dec_to_binary(num);
        mx_printchar('\n');
    }

    return 0;
}
