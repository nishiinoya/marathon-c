#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool mx_isspace(char c);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
void mx_strdel(char **str);
char *mx_strtrim(const char *str);
char *mx_del_extra_whitespaces(const char *str);

int main(void) {
    const char *inputString = "\fMy name...is\r Neo\t\n";

    char *formattedString = mx_del_extra_whitespaces(inputString);

    if (formattedString != NULL) {
        printf("Original string: \"%s\"\n", inputString);
        printf("Formatted string: \"%s\"\n", formattedString);

        // Clean up memory
        free(formattedString);
    } else {
        printf("Memory allocation for formatted string failed or input string is empty.\n");
    }

    return 0;
}
