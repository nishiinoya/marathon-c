void mx_arr_rotate(int *arr, int size, int shift) {
    if (size <= 1 || shift == 0) {
        return;
    }
    int res_arr[size];
    shift %= size;
    if (shift < 0) {
        shift += size;
    }
    for (int i = 0; i < size; i++) {
        res_arr[(i + shift) % size] = arr[i];
    }
    for (int i = 0; i < size; i++) {
        arr[i] = res_arr[i];
    }
}
