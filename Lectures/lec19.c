// Linked Lists

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct LL {
    node *head;
    int size;
} LL;

void create_node(node **p_n, int data) {
    *p_n = (node *)malloc(sizeof(node));
    (*p_n)->next = NULL;
    (*p_n)->data = data;
}

void create_LL_from_data(LL **p_LL, int *data_arr, int size) {
    (*p_LL) = (LL *)malloc(sizeof(LL));
    (*p_LL)->size = 0;
    node *cur = NULL;

    for (int i = 0; i < size; i++) {
        node *n;
        create_node(&n, data_arr[i]);
        if (cur == NULL) {
            (*p_LL)->head = n;
        }
        else {
            cur->next = n;
        }
        cur = n;
        (*p_LL)->size++;
    }
}

void LL_append(LL *my_list, int new_elem) {
    node *cur = my_list->head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    node *n;
    create_node(&n, new_elem);
    cur->next = n;
    my_list->size++;
}

int LL_get_non_rec(LL *my_list, int index) {
    node *cur = my_list->head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    return cur->data;
}

int node_get_at_i(node *cur, int index) {
    if (index == 0) return cur->data;
    return node_get_at_i(cur->next, index-1);
}

int LL_get_rec(LL *my_list, int index) {
    return node_get_at_i(my_list->head, index);
}