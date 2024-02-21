#include "list.h"

void mx_pop_index(t_list **list, int index) {
    if (*list == NULL) {
        return;
    }

    if (index <= 0) {
        mx_pop_front(list);
        return;
    }

    t_list *temp = *list;
    for (int i = 0; i < index - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        t_list *node_rm = temp->next;
        temp->next = node_rm->next;
        free(node_rm);
    } else {
        mx_pop_back(list);
    }
}
