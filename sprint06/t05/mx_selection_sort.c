int mx_strlen(const char *s);
int mx_strcmp(const char *s1, const char *s2);

int mx_selection_sort(char **arr, int size) {
    int min;
    int swaps = 0;

    for (int i = 0; i < size - 1; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            if (mx_strlen(arr[j]) < mx_strlen(arr[min]) ||
                (mx_strlen(arr[j]) == mx_strlen(arr[min])
                && mx_strcmp(arr[j], arr[min]) < 0)) {
                min = j;
            }
        }
        if (min != i) {
            char *temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            swaps++;
        }
    }
    return swaps;
}
