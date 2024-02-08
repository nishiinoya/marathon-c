int mx_strcmp(const char *s1, const char *s2);

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int beg = 0;
    int end = size - 1;

    while (beg <= end) {
        int mid = (beg + end) / 2;
        int comparison = mx_strcmp(arr[mid], s);

        if (comparison == 0) {
            (*count)++;
            return mid;
        } else if (comparison < 0) {
            beg = mid + 1;
            (*count)++;
        } else {
            end = mid - 1;
            (*count)++;
        }
    }
    *count = 0; 
    return -1;
}
