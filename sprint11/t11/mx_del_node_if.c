#include "list.h"

void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b)) {
    if (cmp == NULL || *list == NULL 
    || list == NULL || del_data == NULL) {
        return;
    }
    t_list *temp = *list;
    t_list *prev = NULL;
    while (temp != NULL) {
        if (cmp(temp->data, del_data)) {
           
            if (prev == NULL) {
                // first node
                *list = temp->next;
                free(temp);
                temp = *list;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            // next node
            prev = temp;
            temp = temp->next;
        }
    }
}
