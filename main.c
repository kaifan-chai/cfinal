#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//自己的標頭檔
#include "myhead.h"
#define studentCount 100




int main() {
    StudentRecord student1[studentCount];
    int StudentNum = readStudentRecordFormCSV("recerds.csv", student1, studentCount);
    printfStudentRecord("測試", student1,  StudentNum);
    
    
    
    /* 6/10前的程式碼
    Student student1[studentCount];
    generateRandomData(student1, studentCount);
    //原始資料
    printfStudent("原始資料", student1,  studentCount);
    // 以系級排序
    sortStudentbyDepartment(student1, studentCount);
    printfStudent("以系級排序", student1,  studentCount);
    // 以姓名排序
    sortStudentbyName(student1, studentCount);
    printfStudent("以姓名排序", student1,  studentCount);
    //以學生ID排序
    sortStudentbyStudentID(student1, studentCount);
    printfStudent("以學生ID排序", student1,  studentCount);
    //以年級排序
    sortStudentbygrade(student1, studentCount);
    printfStudent("以年級排序", student1,  studentCount);*/
    system("pause");  
    return 0;   
}



