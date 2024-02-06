int mx_factorial_iter(int n) {
    // factorial of 13+ is > max_int
    if (n < 0 || n > 12) {
        return 0;
    }
    int res = 1;
    for (int i = 1; i < n + 1; i++) {
        res *= i;
    }
    return res;
}
