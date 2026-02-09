#include "lec16.h"
#include <stdlib.h>
#include <stdio.h>

ArrayList *create_list(int *init, int init_sz) {
    ArrayList *L = (ArrayList *)malloc(sizeof(ArrayList));
    L->sz = init_sz;
    L->capacity = init_sz;
    L->buffer = (int *)malloc(sizeof(int) * L->capacity);
    int i;
    for (i = 0; i < init_sz; i++) {
        L->buffer[i] = init[i];
    }
    return L;
}

void append_list(ArrayList *L, int elem) {
    if (L->capacity == L->sz) {
        int new_capacity = 2 * L->capacity;
        L->buffer = (int *)realloc(L->buffer, sizeof(int) * new_capacity);
    }
    L->buffer[L->sz++] = elem;
}

void insert_list(ArrayList *L, int idx, int elem) {
    if (L->capacity == L->sz) {
        int new_capacity = 2 * L->capacity;
        L->buffer = (int *)realloc(L->buffer, sizeof(int) * new_capacity);
    }
    int i;
    for (i = L->sz; i > idx; i--) {
        L->buffer[i] = L->buffer[i-1];
    }
    L->buffer[idx] = elem;
    L->sz++;
}

void print_list(ArrayList *L) {
    int i;
    for (i=0; i < L->sz; i++) {
        printf("%d ", L->buffer[i]);
    }
    printf("\n");
}

void destroy_list(ArrayList *L) {
    free(L->buffer);
    free(L);
}

// typedef struct ArrayList {
//     int *buffer;
//     int sz;
//     int capacity;
// } ArrayList;



// void append_list(ArrayList *L, int elem);

// void insert_list(ArrayList *L, int idx, int elem);

// void print_list(ArrayList *L);