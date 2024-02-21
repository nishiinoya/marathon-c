#ifndef FILE_TO_STR_H
#define FILE_TO_STR_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *mx_strcat(char *s1, const char *s2);
char *mx_strdup(const char *str);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strcpy(char *dst, const char *src);

#endif
