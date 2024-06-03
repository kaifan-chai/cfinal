#include <stdio.h>
#include "myhead.h"
#include <string.h>
#include <stdlib.h>

int compareStudentID(const void* a, const void* b) {
        Student* studentA = (Student*)a;
        Student* studentB = (Student*)b;
        return strcmp(studentA->studentID, studentB->studentID);
}

int comparegrade(const void* a, const void* b) {
        Student* studentA = (Student*)a;
        Student* studentB = (Student*)b;
        return studentA->grade - studentB->grade;
}

int compareDepartment(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    char* strA = studentA->department;
    int numberA = atoi(strA + 10);
    char* strB = studentB->department;
    int numberB = atoi(strB + 10);
    return numberA - numberB;
}

int compareName(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    char* strA = studentA->name;
    int numberA = atoi(strA + 7);
    char* strB = studentB->name;
    int numberB = atoi(strB + 7);
     return numberA - numberB;
}

void sortStudentbyDepartment(Student* student, int studentCount) {
    qsort(student, studentCount, sizeof(Student), compareDepartment);
}

void sortStudentbyName(Student* student, int studentCount) {
    qsort(student, studentCount, sizeof(Student), compareName);
}

void sortStudentbyStudentID(Student* student, int studentCount) {
    qsort(student, studentCount, sizeof(Student), compareStudentID);
}

void sortStudentbygrade(Student* student, int studentCount) {
    qsort(student, studentCount, sizeof(Student), comparegrade);
}