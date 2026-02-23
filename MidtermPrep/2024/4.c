#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char student_number[11];
    double average;
} student;

int count_students(char *filename) {
    FILE *fp = fopen(filename, "r");
    int count = 0;

    while (!feof(fp)) {
        char line[300]; 
        fgets(line, 299, fp);
        count ++;
    }

    fclose(fp);

    return count;
}

void read_in_file(char *filename) {
    int num_students = count_students(filename);
    
    student *student_block = (student *)malloc(sizeof(student) * num_students);
    FILE *fp = fopen(filename, "r");

    for (int i = 0; i < num_students; i++) {
        char c;
        int digit = 0;
        while ((c = fgetc(fp)) != ' ') {
            student_block[i].student_number[digit] = c;
            digit ++;
        }

        int count = 0;
        int sum = 0;
        int mark = 0;
        while ((c = fgetc(fp) != '\n' || c != EOF)) {
            if (c != ' ') {
                mark = mark * 10 + (c - '0');
            }
            else {
                sum += mark;
                count ++;
                mark = 0;
            }
        }
        student_block[i].average = (double) sum/count;
    }

    for (int i = 0; i < num_students; i++) {
        printf("%s %.2f\n", student_block[i].student_number, student_block[i].average);
    }
}

int main() {
    read_in_file("C:\\Users\\user\\Documents\\UofT\\ESC190\\Midterm Prep\\2024\\4.txt");
}