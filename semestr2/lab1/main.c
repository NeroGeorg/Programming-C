#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 100

struct student{

    char name[64];
    int math;
    int phy; 
    int cs;
    int total;

};

struct student addStudent(char* name_s, int math_s,  int phy_s, int cs_s){
    
    struct student new_student;         

    strcpy(new_student.name, name_s);
    new_student.math = math_s;
    new_student.phy = phy_s;
    new_student.cs = cs_s;
    new_student.total = math_s + phy_s + cs_s;

    return new_student;    
}

void printStudentInfo(struct student new_student){

    printf("Имя: %s | Матем: %d | Физика: %d | Информатика: %d | Всего: %d \n" , new_student.name, new_student.math, new_student.phy, new_student.cs, new_student.total);

}

void InsertSort(struct student *new_student){
    clock_t start = clock();
    for(int i = 1; i < N; i++){
        
        struct student key = new_student[i];
        int j = i - 1;

        while ( j >= 0 && new_student[j].total < key.total){
            new_student[j+1] = new_student[j];
            j --;
        }

        new_student[j+1] = key;
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Время выполнения: %f секунд\n", time_spent);
}

void CountingSort(struct student new_student[N]) {
    clock_t start = clock();
    struct student student_output[N];

    int max = new_student[0].total;
    for (int i = 1; i < N; i++) {
        if (new_student[i].total > max) 
            max = new_student[i].total;}
    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;}
    for (int i = 0; i < N; i++) {
        count[new_student[i].total]++;}
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];}
    for (int i = N - 1; i >= 0; i--) {
        student_output[count[new_student[i].total] - 1] = new_student[i];
        count[new_student[i].total]--;}
    for (int i = 0; i < N; i++) {       
        new_student[i] = student_output[N - 1 - i];
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Время выполнения: %f секунд\n", time_spent);
}

// quicksort
void swap(struct student *a, struct student *b) {
    struct student t = *a;
    *a = *b;
    *b = t;
}

int partition(struct student new_student[], int low, int high) {

    int pivot = new_student[high].total;

    int i = low - 1;  

    for (int j = low; j <= high - 1; j++) {         
        if (new_student[j].total < pivot) {  
            i++;    
            swap(&new_student[i], &new_student[j]);
        }
    }

    swap(&new_student[i + 1], &new_student[high]);
    return (i + 1);  
}


void QuickSort(struct student new_student[], int low, int high) {
    if (low < high) {
        int pi = partition(new_student, low, high);
        
        QuickSort(new_student, low, pi - 1);
        QuickSort(new_student, pi + 1, high);
    }
}


int main(){
    srand(time(0));
    
    printf("Модель процессора:\n");
    system("grep 'model name' /proc/cpuinfo | uniq");
    printf("\nЧастота процессора:\n");
    system("grep 'cpu MHz' /proc/cpuinfo | uniq");
    printf("\n");

    struct student Students[N];

    for(int i = 0; i < N;  i++){
        char name[64];
        snprintf(name, 64, "Student%d", i+1);
        Students[i] = addStudent(name, rand()%101, rand()%101, rand()%101);
        printStudentInfo(Students[i]);
    }

    printf("\nInsertSort:\n\n");
    
    InsertSort(Students);
    for(int i = 0; i < N;  i++){
        printStudentInfo(Students[i]);
    }
    

    printf("\nCountingSort:\n\n");
    
    CountingSort(Students);
    for(int i = 0; i < N;  i++){
        printStudentInfo(Students[i]);
    }

    printf("\nQuickSort:\n\n");

    clock_t start = clock();
    QuickSort(Students, 0, N-1);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Время выполнения QuickSort: %f секунд\n", time_spent);

}
