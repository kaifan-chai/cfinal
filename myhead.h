#ifndef MYHEAD_H
#define MYHEAD_H

// Your code goes here
typedef struct  {
    char studentID[50];
    char name[50];
    char department[50];
    int grade;
} Student ;
//科系,學號,年級,姓名,作業,平時測驗,期中測驗,期末報告,其他(出席及平時表現),原始成績

typedef struct {
    Student student; 
    float homework;
    int quiz, midterm, final, other, total; 
} StudentRecord;

//印出學生資料

int readStudentRecordFormCSV(char* filename, StudentRecord* student1, int studentCount);

void printfStudentRecord(char printname[],StudentRecord* student1, int studentCount);
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
