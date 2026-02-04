#include "lec13-mystr.h"
#include <stdlib.h>
#include <string.h>

void create_string(mystr **p_s, const char *init) {
    (*p_s) = (mystr *)malloc(sizeof(mystr));
    (*p_s)->buffer = (char *)malloc(strlen(init)+1);
    (*p_s)->buffer_sz = strlen(init)+1;
    strcpy((*p_s)->buffer, init);
    (*p_s)->length = strlen(init);
}

mystr *append_strings(mystr *s1, mystr *s2) {
    mystr *res;
    char *buffer = (char *)malloc(s1->length + s2->length + 1);
    strcpy(buffer, s1->buffer);
    strcat(buffer, s2->buffer);
    create_string(&res, buffer);
    free(buffer);
    return res;
}

void destroy_string(mystr *s1) {
    free(s1->buffer);
    free(s1);
}