int mx_popular_int(const int *arr, int size) {
    int popular_num = arr[0];
    int max_count = 0;
    for (int i = 0; i < size; i++) {
        int curr_num = arr[i];
        int curr_count = 1; 
        for (int j = i + 1; j < size - i; j++) {
            if (curr_num == arr[j + i]) {
                curr_count++;
            }
        }
        if (curr_count > max_count) {
            max_count = curr_count;
            popular_num = curr_num;
        }
    }
    return popular_num;
}
