char *mx_strncpy(char *dst, const char *src, int len) {
    int i;
    if (len < 0) {
        return 0;
    }
    for (i = 0; i < len; i++) {
        if (src[i] != '\0') {
            dst[i] = src[i];
        } else {
            dst[i] = '\0';
        }
    }

    return dst;
}
