int mx_strlen(const char *s);

int mx_insertion_sort(char **arr, int size) {
    int j;
    int shifts = 0;
    char *current;

    for (int i = 1; i < size; i++) {
        current = arr[i];
        j = i - 1;
        while (j >= 0 && mx_strlen(arr[j]) > mx_strlen(current)) {
            arr[j + 1] = arr[j];
            j = j - 1;
            shifts++;
        }

        arr[j + 1] = current;
    }

    return shifts;
}
