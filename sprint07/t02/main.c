#include <stdio.h>
#include <stdlib.h>

char *mx_strcat(char *s1, const char *s2);
char *mx_strdup(const char *str);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strjoin(char const *s1, char const *s2);

int main(void) {
    const char *string1 = "Hello, ";
    const char *string2 = "World!";

    // Test mx_strlen
    printf("Length of string1: %d\n", mx_strlen(string1));
    printf("Length of string2: %d\n", mx_strlen(string2));

    // Test mx_strnew
    int size = 15;
    char *newString = mx_strnew(size);
    printf("New string after mx_strnew: %s\n", newString);

    // Test mx_strdup
    const char *originalString = "Test String";
    char *duplicateString = mx_strdup(originalString);
    if (duplicateString != NULL) {
        printf("Original string: %s\n", originalString);
        printf("Duplicated string: %s\n", duplicateString);

        // Test mx_strjoin
        char *joinedString = mx_strjoin(string1, string2);
        if (joinedString != NULL) {
            printf("Joined string: %s\n", joinedString);

            // Clean up memory
            free(joinedString);
        } else {
            printf("Memory allocation for joined string failed.\n");
        }

        // Clean up memory
        free(duplicateString);
    } else {
        printf("Memory allocation for duplicate string failed.\n");
    }

    return 0;
}
