#include <stdlib.h>
#include <stdio.h>

typedef struct my_struct
{
    int a;
    int b;
} my_struct;

typedef struct student {
    char number[11];
    double average;
} student;

student read_in_line(char *line) {
    student s;

    // read in student #
    int i = 0;
    for (i = 0; i < 10; i++) {
        s.number[i] = line[i];
    }
    s.number[10] = '\0';
    i = 11;
    double cur_grade = 0;
    double cur_sum = 0;
    int count = 0;
    while(line[i] != '\0') {
        cur_grade = 0;
        while(line[i] != '\0' && line[i] != ' ') {
            cur_grade = 10 * cur_grade + (line[i] - '0');
            i ++;
        }
        cur_sum += cur_grade;
        count ++;
        i++;
    }
    s.average = cur_sum/count;
    return s;
}

void read_in_all_data(char *filename) {
    int n_students;
    FILE *fp = fopen(filename, "r");
    char cur_line[10000];
    while(!feof(fp)) {
        fgets(fp, cur_line, 10000);
        n_students ++;
    }
}

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int my_struct_cmp(const void *s1, const void *s2)
{
    my_struct *struct_s1 = (my_struct *)s1;
    my_struct *struct_s2 = (my_struct *)s2;
    return struct_s1->b - struct_s2->b;
}

int my_struct_cmp_lexicographic(const void *s1, const void *s2)
{
    my_struct *struct_s1 = (my_struct *)s1;
    my_struct *struct_s2 = (my_struct *)s2;
    if (struct_s1->a < struct_s2->a) {
        return -1;
    }else if (struct_s1->a == struct_s2->a) {
        return struct_s1->b - struct_s2->b;
    }
    else {
        return 1;
    }
}

int main()
{
    int arr[4] = {5, 2, 3, 10};
    qsort(arr, 4, sizeof(int), cmpfunc);

    for (int i = 0; i < 4; i++) {
        printf("%d\n", arr[i]);
    }

    my_struct ss[] = {{3, 4}, {1, 2}, {5, 0}, {3, 1}};
    // qsort(ss, 3, sizeof(my_struct), my_struct_cmp);
    qsort(ss, 4, sizeof(my_struct), my_struct_cmp_lexicographic);
    for (int i = 0; i < 4; i++) {
        printf("{%d %d}\n", ss[i].a, ss[i].b);
    }
}