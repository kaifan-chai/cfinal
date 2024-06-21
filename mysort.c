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
//compareHomework
int compareHomework(const void* a, const void* b) {
    StudentRecord* studentA = (StudentRecord*)a;
    StudentRecord* studentB = (StudentRecord*)b;
    return (studentA->homework - studentB->homework)*sorttype;
}
//compareQuiz
int compareQuiz(const void* a, const void* b) {
    StudentRecord* studentA = (StudentRecord*)a;
    StudentRecord* studentB = (StudentRecord*)b;
    return (studentA->quiz - studentB->quiz)*sorttype;
}
//compareMidterm
int compareMidterm(const void* a, const void* b) {
    StudentRecord* studentA = (StudentRecord*)a;
    StudentRecord* studentB = (StudentRecord*)b;
    return (studentA->midterm - studentB->midterm)*sorttype;
}
//compareFinal
int compareFinal(const void* a, const void* b) {
    StudentRecord* studentA = (StudentRecord*)a;
    StudentRecord* studentB = (StudentRecord*)b;
    return (studentA->final - studentB->final)*sorttype;
}
//compareOther
int compareOther(const void* a, const void* b) {
    StudentRecord* studentA = (StudentRecord*)a;
    StudentRecord* studentB = (StudentRecord*)b;
    return (studentA->other - studentB->other)*sorttype;
}
//compareTotal
int compareTotal(const void* a, const void* b) {
    StudentRecord* studentA = (StudentRecord*)a;
    StudentRecord* studentB = (StudentRecord*)b;
    return (studentA->total - studentB->total)*sorttype;
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

void sortStudentRecord(StudentRecord* student, int studentCount, const char* sortType) {
    if (strcmp(sortType, "homework") == 0) {
        qsort(student, studentCount, sizeof(StudentRecord), compareHomework);
    } else if (strcmp(sortType, "quiz") == 0) {
        qsort(student, studentCount, sizeof(StudentRecord), compareQuiz);
    } else if (strcmp(sortType, "midterm") == 0) {
        qsort(student, studentCount, sizeof(StudentRecord), compareMidterm);
    } else if (strcmp(sortType, "final") == 0) {
        qsort(student, studentCount, sizeof(StudentRecord), compareFinal);
    } else if (strcmp(sortType, "other") == 0) {
        qsort(student, studentCount, sizeof(StudentRecord), compareOther);
    } else if (strcmp(sortType, "total") == 0) {
        qsort(student, studentCount, sizeof(StudentRecord), compareTotal);
    }
}
