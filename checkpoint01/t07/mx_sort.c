#include <stdbool.h>

void mx_sort(int *arr, int size, bool (*f)(int, int)) {
    int temp;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (f(arr[j], arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
