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
    float homework, quiz, midterm, final, other, total; 
} StudentRecord;

#define homeworkWeight 0.2
#define quizWeight 0.1
#define midtermWeight 0.3
#define finalWeight 0.3
#define otherWeight 0.1

//讀取學生資料
int readStudentRecordFormCSV(char* filename, StudentRecord* student1, int studentCount);
//印出學生資料
void printfStudentRecord(char printname[],StudentRecord* student1, int studentCount);
//產生隨機資料
void generateRandomData(Student students[], int count);
//印出學生資料
void printfStudent(char printname[],Student* student1, int studentCount);
//以科系排序
void sortStudentbyDepartment(Student* student, int studentCount);
//以姓名排序
void sortStudentbyName(Student* student, int studentCount);
//以學生ID排序
void sortStudentbyStudentID(Student* student, int studentCount);
//以年級排序    
void sortStudentbygrade(Student* student, int studentCount);
//排序StudentRecord根據學生成績
void sortStudentRecord(StudentRecord* student, int studentCount, const char* sortType);
//比較學生ID
int compareStudentID(const void* a, const void* b);
//比較年級
int comparegrade(const void* a, const void* b);
//比較科系
int compareDepartment(const void* a, const void* b);
//比較姓名
int compareName(const void* a, const void* b);
//比較作業
int compareHomework(const void* a, const void* b);
//比較平時測驗
int compareQuiz(const void* a, const void* b);
//比較期中測驗
int compareMidterm(const void* a, const void* b);
//比較期末報告
int compareFinal(const void* a, const void* b);
//比較其他
int compareOther(const void* a, const void* b);
//比較總分
int compareTotal(const void* a, const void* b);
#endif // MYHEAD_H
