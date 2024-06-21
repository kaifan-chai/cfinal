#include <stdio.h>
#include <string.h>
#include "myhead.h"
#define studentCount 100

void sortMenu(StudentRecord student1[], int StudentNum) {
    int choice;

    while(1) {
        printf("\nSort Menu:\n");
        printf("1. Sort by homework\n");
        printf("2. Sort by quiz\n");
        printf("3. Sort by midterm\n");
        printf("4. Sort by final\n");
        printf("5. Sort by other\n");
        printf("6. Sort by total\n");
        printf("7. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                sortStudentRecord(student1, StudentNum, "homework");
                printfStudentRecord("Sorted by homework", student1,  StudentNum);
                return;
            case 2:
                sortStudentRecord(student1, StudentNum, "quiz");
                printfStudentRecord("Sorted by quiz", student1,  StudentNum);
                return;
            case 3:
                sortStudentRecord(student1, StudentNum, "midterm");
                printfStudentRecord("Sorted by midterm", student1,  StudentNum);

                return;
            case 4:
                sortStudentRecord(student1, StudentNum, "final");
                printfStudentRecord("Sorted by final", student1,  StudentNum);
                return;
            case 5:
                sortStudentRecord(student1, StudentNum, "other");
                printfStudentRecord("Sorted by other", student1,  StudentNum);
                return;
            case 6:
                sortStudentRecord(student1, StudentNum, "total");
                printfStudentRecord("Sorted by total", student1,  StudentNum);
                return;
            case 7:
                return;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }
    }
}


void searchStudent(StudentRecord student1[], int StudentNum) {
    char studentID[50]; // Change the data type to a character array
    printf("Enter the student ID you want to search for: ");
    scanf("%s", studentID); // Remove the '&' operator before studentID
    for(int i = 0; i < StudentNum; i++) {
        if(strcmp(student1[i].student.studentID, studentID) == 0) {
            printf("Student found:\n");
            printfStudentRecord("Student record", &student1[i], 1);
            return;
        }
    }

    printf("Student not found.\n");
}

void mainMenu(StudentRecord student1[], int StudentNum) {
    int choice;

    while(1) {
        printf("\nMain Menu:\n");
        printf("1. Read records\n");
        printf("2. Print records\n");
        printf("3. Sort records\n");
        printf("4. Search student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                StudentNum = readStudentRecordFormCSV("recerds.csv", student1, studentCount);
                printf("Read %d records.\n", StudentNum);
                break;
            case 2:  
                if(strcmp(student1[0].student.name, "") == 0){
                    printf("Please read records first.\n");
                    break;  
                }else{
                    printfStudentRecord("Current records", student1,  StudentNum);
                    break;  
                }
                         
            case 3:
                sortMenu(student1, StudentNum);
                break;
            case 4:
                searchStudent(student1, StudentNum);
                break;
            case 5:
                return;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }
}

int main() {
    StudentRecord student1[studentCount]={0};
    mainMenu(student1, studentCount);
    return 0;
}