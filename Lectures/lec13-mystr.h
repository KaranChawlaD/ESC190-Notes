#if !defined(MYSTR_H)
#define MYSTR_H

typedef struct mystr{
    char *buffer;
    int length;
    int buffer_sz;
} mystr;

void create_string(mystr **p_s, const char *init);

#endif