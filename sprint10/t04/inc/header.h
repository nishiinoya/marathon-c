#ifndef HEADER_H
#define HEADER_H

#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
char *mx_strcpy(char *dst, const char *src);
void mx_printint(int n);
void mx_printchar(char c);
void mx_printerr(const char *s);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strcat(char *s1, const char *s2);
void mx_printstr(const char *s);
int mx_count_words(const char *str);
bool mx_isspace(char c);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strdup(const char *str);

#endif
