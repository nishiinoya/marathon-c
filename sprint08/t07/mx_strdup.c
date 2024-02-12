#include "create_new_agents.h"

char *mx_strcpy(char *, const char *);
int mx_strlen(const char *str);
char *mx_strnew(const int size);
char *mx_strdup(const char *str) {
    int size_str = mx_strlen(str);
    char *dup = mx_strnew(size_str + 1);

    if (dup == NULL) {
        return NULL; 
    }

    return mx_strcpy(dup, str);
}
