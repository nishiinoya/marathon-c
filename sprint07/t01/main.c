#include <stdio.h>
#include <stdlib.h>

// Function prototypes
char *mx_strcpy(char *dst, const char *src);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strdup(const char *str);

int main(void) {
    const char *originalString = "Hello, World!";

    // Test mx_strlen
    int length = mx_strlen(originalString);
    printf("Length of the string: %d\n", length);

    // Test mx_strnew
    int size = 15;
    char *newString = mx_strnew(size);
    printf("New string after mx_strnew: %s\n", newString);

    // Test mx_strdup
    char *duplicateString = mx_strdup(originalString);
    if (duplicateString != NULL) {
        printf("Original string: %s\n", originalString);
        printf("Duplicated string: %s\n", duplicateString);

        // Test mx_strcpy
        char destination[20];
        mx_strcpy(destination, originalString);
        printf("Copied string using mx_strcpy: %s\n", destination);

        // Clean up memory
        free(duplicateString);
    } else {
        printf("Memory allocation for duplicate string failed.\n");
    }

    return 0;
}
