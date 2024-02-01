#include <unistd.h>

void mx_printint(int n) {
    if (n == 0)
        write(1, "0", 1);

    if (n < 0) {
        write(1, "-", 1);
        n = -n;
    }
    if (n == -2147483648) {
        write(1, "2147483648", 11);
        return;
    }
    int n_1 = n;
    int size = 0;
    while (n_1 != 0) {
        n_1 /= 10;
        size++;
    }

    int array[size];
    int i = 0;
    while (n != 0) {
        array[i] = n % 10;
        n /= 10;
        i++;
    }

    int j = i - 1;
    while (j >= 0) {
        int temp = array[j] + 48;
        write(1, &temp, 1);
        j--;
    }
}
