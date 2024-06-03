#include <stdio.h>
#include "myhead.h"
#include <time.h>
#include <stdlib.h>

void printfStudent(char printname[10],Student* student1, int studentCount) {
    printf("\n\n%s\nDepartment\tName\t\tStudentID\tGrade\n", printname);
    printf("------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s\t%s\t    %s\t    %d\n", student1[i].department, student1[i].name, student1[i].studentID, student1[i].grade);
    }
}

void generateRandomData(Student students[], int count) {
        srand(time(NULL)); // Seed the random number generator

        for (int i = 0; i < count; i++) {
            sprintf(students[i].studentID, "%05d", rand()%1000+1); // Generate a random student ID between 1 and 1000
            sprintf(students[i].name, "Student %d", i+1); // Generate a student name
            sprintf(students[i].department, "Department %d", rand() % 20+1); // Generate a department name
            students[i].grade = rand() % 4+1; // Generate a random grade between 0 and 100
        }
}