int mx_sum_digits(int num) {
    int sum = 0;

    if (num < 0) {
        num = -num;
    }

    for (; num > 0; num /= 10) {
        sum += num % 10;
    }

    return sum;
}
