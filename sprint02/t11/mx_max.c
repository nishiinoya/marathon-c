int mx_max(int a, int b, int c) {
    int max_num = a;
    if (b > max_num) {
        max_num = b;
    }
    if (c > max_num) {
        max_num = c;
    }
    return max_num;
}
