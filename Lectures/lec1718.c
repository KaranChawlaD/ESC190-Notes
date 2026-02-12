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
        while(line[i] != '\0' && line[i] != ' ' && line[i] != '\n') {
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

void read_in_all_data(char *filename, student **p_all_students, int *p_n_students) {
    int n_students = 0;
    FILE *fp = fopen(filename, "r");
    char cur_line[10000];
    while(!feof(fp)) {
        fgets(cur_line, 10000-1, fp);
        n_students ++;
    }
    fclose(fp);
    printf("%d\n", n_students);
    student *all_students = (student *)malloc(sizeof(student) * n_students);
    int i = 0;
    fp = fopen(filename, "r");
    for (i = 0; i < n_students; i++) {
        fgets(cur_line, 10000-1, fp);
        all_students[i] = read_in_line(cur_line);
    }
    // for (i = 0; i < n_students; i++) {
    //     printf("%s: %f\n", all_students[i].number, all_students[i].average);
    // }
    *p_all_students = all_students;
    *p_n_students = n_students;
}

void print_best_performers(student *all_students, int n_students) {
    double cur_max = -1;
    int i;
    for (i = 0; i < n_students; i ++) {
        if (all_students[i].average > cur_max) {
            cur_max = all_students[i].average;
        }
    }
    for (i = 0; i < n_students; i ++) {
        if (all_students[i].average == cur_max) {
            printf("WINNER: %s\n", all_students[i].number);
        }
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

int main() {
    student *all_students;
    int n_students;
    read_in_all_data("lec17.txt", &all_students, &n_students);
    print_best_performers(all_students, n_students);
    // char line[] = "9874512541 12 13 14 15 16\n";
    // student s = read_in_line(line);
    // printf("%s: %f", s.number, s.average);
}

int main1()
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