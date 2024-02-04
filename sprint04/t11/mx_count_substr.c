char *mx_strstr(const char *s1, const char *s2);

int mx_count_substr(const char *str, const char *sub) {
    int counter = 0;
    const char *copy = str;
    for (; (copy = mx_strstr(copy, sub)) && *copy != '\0'; counter++) {
        copy++;
    }
    return counter;
}
