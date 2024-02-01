#include <unistd.h>
void mx_printchar(char c);

void mx_only_printable(void) {
    for (char c = 126; c >= 32; --c) {
        write(1, &c, 1);
    }
    write(1, "\n", 1);
}

