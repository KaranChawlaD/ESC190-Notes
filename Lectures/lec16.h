#if !defined(ARRAYLIST_H)
#define ARRAYLIST_H

typedef struct ArrayList {
    int *buffer;
    int sz;
    int capacity;
} ArrayList;

ArrayList *create_list(int *init, int init_sz);

void append_list(ArrayList *L, int elem);

void insert_list(ArrayList *L, int idx, int elem);

void print_list(ArrayList *L);

void destroy_list(ArrayList *L);

#endif