#include <unistd.h>

int main(int argc, char *argv[]) {
    int len = 0;

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            len = 0;
            for (; argv[i][len] != '\0'; len++) {
                write(1, &argv[i][len], 1);
            }
            write(1, "\n", 1);
        }
    }

    return 0;
}
