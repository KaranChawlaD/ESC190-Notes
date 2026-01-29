#include <stdio.h>

typedef struct student {
    char *name; //instead of char name[1000]
    int age;
} student;

void change_name1(student *p_s1) {
    p_s1->name = "Bob";
}

int main() {
    char *name = "Karan";
    name = "Bob"; //allowed
    // strcpy(name, "Bobby"); //not allowed
    
    student s1;
    s1.name = "bob"; //allowed
    // strcpy(s1.name, "bob"); //not allowed
    return 0;
}