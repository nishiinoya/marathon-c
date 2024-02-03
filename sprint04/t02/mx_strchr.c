#include <stdio.h>
#include <string.h>

char *mx_strchr(const char *s, int c) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return (char *)s + i;
        }
    }
    return NULL;
}

void test_strchr(const char *str, int c) {
    char *result_mx = mx_strchr(str, c);
    char *result_std = strchr(str, c);

    printf("String: \"%s\"\n", str);
    printf("Character to find: '%c'\n", c);
    printf("mx_strchr result: %p\n", (void *)result_mx);
    printf("strchr result: %p\n", (void *)result_std);

    if (result_mx == result_std) {
        printf("Results match!\n");
    } else {
        printf("Results do not match.\n");
    }

    printf("\n");
}

int main() {
    // Test cases
    test_strchr("hello", 'e');
    test_strchr("world", 'l');
    test_strchr("programming", 'z'); // Character not in the string
    test_strchr("", 'a');            // Empty string

    return 0;
}
