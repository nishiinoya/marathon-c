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

#define MAX_AGENT_COUNT 1000
typedef struct s_agent {
    char *name;
    int power;
    int strength;
}
t_agent;
bool mx_isdigit(int c) ;
int mx_strcmp(const char *s1, const char *s2);
int mx_strncmp(const char *s1, const char *s2, int n);
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
char *mx_file_to_str(const char *filename);
char *mx_strncpy(char *dst, const char *src, int len) ;
int mx_atoi(const char *str);
t_agent *mx_create_agent(char *name, int power, int strength);
#endif
