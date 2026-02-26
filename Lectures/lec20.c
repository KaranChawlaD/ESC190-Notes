#include <stdio.h>
#include <stdlib.h>

typedef struct C{
    int a;
} C;

C *create_C(int a) {
    C *c = (C *)malloc(sizeof(C));
    c->a = a;
    return c;
}

void add6(C *c) {
    c->a += 6;
}

int main() {
    C *c = create_C(42);
    add6(c);
    printf("%d\n", c->a);
}