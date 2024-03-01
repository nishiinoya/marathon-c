#ifndef LIST_H
#define LIST_H

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;
void mx_printerr(const char *s);
void mx_printint(int n);
t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_back(t_list **list);
void mx_pop_front(t_list **list);
int mx_list_size(t_list *list);
void mx_push_index(t_list **list, void *data, int index);
void mx_pop_index(t_list **list, int index);
void mx_clear_list(t_list **list);
void mx_foreach_list(t_list *list, void (*f)(t_list *node));
t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b));
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcpy(char *dst, const char *src);
void mx_printstr(const char *s);
void mx_printchar(char c);
int mx_strlen(const char *s);
int mx_atoi(const char *str);
void add_func(char *argv[]);
void print_func(char *argv[]);
void remove_func(char *argv[]);

#endif
