int mx_gcd(int a, int b) {
    if (a < 0) {
        a = -a;
    }

    if (b < 0) {
        b = -b;
    }

    if (b == 0) {
        return a;
    }

    return mx_gcd(b, a % b);
}
