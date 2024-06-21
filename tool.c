#include <stdio.h>
#include "myhead.h"
#include <time.h>
#include <stdlib.h>

//科系,學號,年級,姓名,作業20,平時測驗10,期中測驗30,期末報告30,其他(出席及平時表現)10,原始成績
int readStudentRecordFormCSV(char* filename, StudentRecord* student1, int studentCount) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found\n");
        return 0;
    }
    char buffer[1024];
    //skip the first line
    fgets(buffer, 1024, file);
    int i = 0;
    while (fgets(buffer, 1024, file) && i < studentCount) {
            sscanf(buffer, "%[^,],%[^,],%d,%[^,],%f,%f,%f,%f,%f,%f", student1[i].student.department, student1[i].student.studentID, &student1[i].student.grade, student1[i].student.name, &student1[i].homework, &student1[i].quiz, &student1[i].midterm, &student1[i].final, &student1[i].other);
            student1[i].total = student1[i].homework * homeworkWeight + student1[i].quiz * quizWeight + student1[i].midterm * midtermWeight + student1[i].final * finalWeight + student1[i].other * otherWeight;
        i++;
    }
    fclose(file);
    return i;
}


void printfStudent(char printname[],Student* student1, int studentCount) {
    printf("\n\n%s\nDepartment\tName\t\tStudentID\tGrade\n", printname);
    printf("------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s\t%s\t    %s\t    %d\n", student1[i].department, student1[i].name, student1[i].studentID, student1[i].grade);
    }
}

void printfStudentRecord(char printname[],StudentRecord* student1, int studentCount) {
    printf("\n\n%s\n%-15s %-11s %-15s %-8s %-12s %-9s %-10s %-10s %-10s %-10s\n", printname, "Department", "Name", "StudentID", "Grade", "Homework", "Quiz", "Midterm", "Final", "Other", "Total");
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-15s %11s %14s %11d %11.1f %8.1f %12.1f %8.1f %10.1f %10.1f\n", student1[i].student.department, student1[i].student.name, student1[i].student.studentID, student1[i].student.grade, student1[i].homework, student1[i].quiz, student1[i].midterm, student1[i].final, student1[i].other, student1[i].total);
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

//學生各項成績平均
void average_records(StudentRecord* student1, int studentCount) {
    float sumHomework = 0, sumQuiz = 0, sumMidterm = 0, sumFinal = 0, sumOther = 0, sumTotal = 0;
    for (int i = 0; i < studentCount; i++) {
        sumHomework += student1[i].homework;
        sumQuiz += student1[i].quiz;
        sumMidterm += student1[i].midterm;
        sumFinal += student1[i].final;
        sumOther += student1[i].other;
        sumTotal += student1[i].total;
    }
    printf("\n\n%s\n%-12s %-9s %-10s %-10s %-10s %-10s\n", "average records", "Homework", "Quiz", "Midterm", "Final", "Other", "Total");
    printf("-------------------------------------------------------------\n");
    printf("%8.1f %8.1f %12.1f %8.1f %10.1f %10.1f\n", sumHomework/studentCount, sumQuiz/studentCount, sumMidterm/studentCount, sumFinal/studentCount, sumOther/studentCount, sumTotal/studentCount);
    
}