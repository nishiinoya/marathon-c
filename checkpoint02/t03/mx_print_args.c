#include <unistd.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        int len = 0;
        char *temp = argv[i];
        while (temp[len] != '\0') {
            len++;
        }
        write(1, argv[i], len);
        char c = '\n';
        write(1, &c, 1);
    }
        return 0;
}
