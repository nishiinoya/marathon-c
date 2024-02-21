#include "list.h"

void mx_push_index(t_list **list, void *data, int index) {
    if (index <= 0) {
        mx_push_front(list, data);
        return;
    }

    if (*list == NULL) {
        *list = mx_create_node(data);
        return;
    }

    int counter = 0;
    t_list *temp_count = *list;
    while (temp_count) {
        temp_count = temp_count->next;
        counter++;
    }

    if (index >= counter) {
        mx_push_back(list, data);
        return;
    }

    t_list *temp = *list;
    t_list *helper = NULL;
    for (int i = 0; i < index; i++) {
        helper = temp;
        temp = temp->next;
    }

    helper->next = mx_create_node(data);
    helper->next->next = temp;
}
