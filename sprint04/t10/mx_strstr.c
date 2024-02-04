int mx_strncmp(const char *s1, const char *s2, int n);
int mx_strlen(const char *s);
char *mx_strchr(const char *s, int c);

char *mx_strstr(const char *s1, const char *s2) {
    int s1_len = mx_strlen(s1);
    int s2_len = mx_strlen(s2);

    if (s2_len > s1_len) {
        return 0;
    }

    for (int i = 0; i <= s1_len - s2_len; i++) {
        char *ptr = mx_strchr(s1 + i, s2[0]);
        if (ptr != 0) {
            if (mx_strncmp(ptr, s2, s2_len) == 0) {
                return ptr; 
            }
        }
    }

    return 0; 
}
