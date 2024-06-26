#include <stdbool.h>

void mx_sort(int *arr, int size, bool (*f)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (f(arr[i], arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
