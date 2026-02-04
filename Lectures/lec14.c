#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lec13-mystr.h"
// #include "lec13-mystr.c" don't do this

int main()
{
    mystr *s1;
    mystr *s2;
    create_string(&s1, "Hi");
    create_string(&s2, "Calculus");
    // printf("%s\n", s1->buffer);
    mystr *s3 = append_strings(s1, s2);
    printf("%s\n", s3->buffer);
    s3->buffer[0] = 'h'; // python doesn't allow this!
    printf("%s\n", s3->buffer);
    
    mystr *s4 = s3;
    s4->buffer[0] = 'H';
    printf("%s\n", s3->buffer);
    printf("%s\n", s4->buffer);

    destroy_string(s1);
    destroy_string(s2);
    destroy_string(s3);
    printf("Done");
}