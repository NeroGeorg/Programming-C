#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//функция вывод массива 
void print_matrix(int n, int m, int **matrix){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            printf(" %d", matrix[i][j]);
            }
            printf("\n");
        }
}

int number = 0;
//рандомные числа массива0
void rand_matrix(int n, int m, int **matrix){
    printf("Рандомная матрица:\n");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            matrix[i][j] = rand() % 9 + 1;
        }
    }
}

//ввод массива вручную
void input_matrix(int n, int m, int **matrix){
    int number;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            printf("[%d][%d]: ", i, j);
            do{
                if (scanf("%d", &number) != 1){
                    printf("Ошибка! Это не число!\n");
                    // очистка буффера ввода
                    while (getchar() != '\n');
                    j--;
                }
                else {
                    matrix[i][j] = number;
                    break;
                }
            }while(number == 1);
        }
    }
}

int main(){

    srand(time(NULL));

    printf("Размер массива:");
    do{
        printf(">");
        if (scanf("%d", &number) != 1){
            printf("Ошибка! Это не число!\n");
            // очистка буффера ввода
            while (getchar() != '\n');
        }
        else if (number <= 0){
            printf("Число должно быть > 0\n");
        }
        else break;
    }while(number <= 0);

    //задаём динамический двумерный массив
        
    int **m = (int **)malloc(number * sizeof(int *));
    for (int i = 0; i < number; i++){
        m[i] = (int *)malloc(number * sizeof(int));
    }
   
    bool flag = false;
    bool askflag = false;
    char c;

    // рандом или вручную
    while(flag == false){
    if (askflag == false){
        printf("Рандом/вручную [y/n]:");
        askflag = true;
    }
    scanf(" %c", &c);
    if(c == 'y'){
        rand_matrix(number, number, m);
        flag = true;}
    else if (c == 'n') {
        input_matrix(number, number, m);
        flag = true;}
    }
    //вывод матрицы
    print_matrix(number, number, m);
    
    int cnt = 0;
    int mltpy = 1;
    int mltpy_min = __INT_MAX__;
    int index = 1;
    int index_j = 1;
    //поиск строки с элментами по модулю < 8
    for (int i = 0; i<number; i++){
        cnt = 0;
        mltpy = 1;
        for(int j = 0; j<number; j++){
            if (m[i][j] < 8){
                cnt++;
                mltpy *= m[i][j];
            }
            if (cnt == number) {
                printf("В этой строке числа < 8:[%d] Произведение этой строки: [%d]\n", i+1, mltpy);
                if (mltpy < mltpy_min){
                    mltpy_min = mltpy;
                    index = i;
                }
            }
        }
    }
    //поиск минимального произведения
    printf("Строка с минимальным произведением: [%d] Минимальное произведение: {%d}\n", index+1, mltpy_min);

    //вариант 26 сформировать массив B из элементов массива А
    int **b = (int **)malloc(number * sizeof(int *));

    for (int i = 0; i < number; i++){
        b[i] = (int *)malloc(number * sizeof(int));
    }

    printf("Матрица B:\n");
    for(int i = 0; i<number; i++){
        for(int j = 0; j<number; j++){
            if (i > j) b[i][j] = m[i][j];
            if (number - i - 1 > j) b[i][j] = m[i][j];
        }
    }

    int c_matrix = m[number/2][number/2];
    int c_mltpy = 1;
    int b_min = __INT_MAX__;

    for(int i = 0; i<number; i++){
        for(int j = 0; j<number; j++){
            if (b[i][j] > c_matrix) c_mltpy*=b[i][j];
            if(b[i][j] != 0){
            if(b[i][j] < b_min){
                b_min = b[i][j];
                index = i;
                index_j = j;
                }
            }
        }
    }

    printf("Произведение всех элементов которые больше %d: {%d}\n", c_matrix, c_mltpy);
    printf("Координаты минимального элемента: [%d][%d]\n", index+1, index_j+1);
    printf("Минимальный элемент: {%d}\n", b_min);
    print_matrix(number, number, b);

    //очищаем
    for (int i = 0; i < number; i++){
        free(m[i]);
        free(b[i]);
    }
    
    m = NULL;
    b = NULL;
}
