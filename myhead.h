#ifndef MYHEAD_H
#define MYHEAD_H

// Your code goes here
typedef struct  {
    char studentID[50];
    char name[50];
    char department[50];
    int grade;
} Student ;

void generateRandomData(Student students[], int count);
void printfStudent(char printname[],Student* student1, int studentCount);
void sortStudentbyDepartment(Student* student, int studentCount);
void sortStudentbyName(Student* student, int studentCount);
void sortStudentbyStudentID(Student* student, int studentCount);
void sortStudentbygrade(Student* student, int studentCount);
int compareStudentID(const void* a, const void* b);
int comparegrade(const void* a, const void* b);
int compareDepartment(const void* a, const void* b);
int compareName(const void* a, const void* b);
#endif // MYHEAD_H
