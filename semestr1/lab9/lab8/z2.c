#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//функция вывод массива 
void print_matrix(int n, int m, int matrix[n][m]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m+1; j++){
            printf(" %d", matrix[i][j]);
            }
            printf("\n");
        }
}

int number;

//функция заполнения случайными числами
void rand_matrix(int n, int m, int matrix[n][m]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m+1; j++){
            matrix[i][j] = rand() % 8 + 1;
        }
    }
}

int main(){

    srand(time(NULL));

    printf("Введите размер массива:");
    scanf("%d", &number);
    int m[number][number];

    // заполняем массив рандомныеми числами от 1 9
    rand_matrix(number, number, m);

    //вывод матрицы
    print_matrix(number, number, m);

    //вычисляем определитель
    float det = 0, detx = 0, dety = 0, detz = 0, x = 0, y = 0, z = 0;
    if (number == 2){
        det = (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
        detx = (m[0][2] * m[1][1]) - (m[1][2] * m[0][1]);
        //printf("%d * %d  - %d * %d\n", m[0][2],m[1][1], m[1][2],m[0][1]);
        dety = (m[0][0] * m[1][2]) - (m[1][0] * m[0][2]);
        //printf("%d * %d  - %d * %d\n", m[0][0],m[1][2], m[1][0],m[0][2]);
        printf("Определитель = %.2f\n", det);
        printf("Определитель x = %.2f\n", detx);
        printf("Определитель y = %.2f\n", dety);
        if(det != 0 && detx != 0 && dety != 0){
            x = detx/det;
            y = dety/det;
            printf("x = %.2f, y = %.2f\n", x, y);
        }
        else{ 
            printf("Один из определителей равен нулю!");
        }
    }
    if (number == 3){
        det = ((m[0][0] * m[1][1] * m[2][2]) + (m[2][0] * m[0][1] * m[1][2]) + (m[0][2] * m[1][0] * m[2][1])) - (m[2][0] * m[1][1] * m[0][2]) - (m[1][0] * m[0][1] * m[2][2]) - (m[0][0] * m[2][1] * m[1][2]);
        detx = ((m[0][3] * m[1][1] * m[2][2]) + (m[2][3] * m[0][1] * m[1][2]) + (m[0][2] * m[1][3] * m[2][1])) - (m[2][3] * m[1][1] * m[0][2]) - (m[1][3] * m[0][1] * m[2][2]) - (m[0][3] * m[2][1] * m[1][2]);
        dety = ((m[0][0] * m[1][3] * m[2][2]) + (m[2][0] * m[0][3] * m[1][2]) + (m[0][2] * m[1][0] * m[2][3])) - (m[2][0] * m[1][3] * m[0][2]) - (m[1][0] * m[0][3] * m[2][2]) - (m[0][0] * m[2][3] * m[1][2]);
        detz = ((m[0][0] * m[1][1] * m[2][3]) + (m[2][0] * m[0][1] * m[1][3]) + (m[0][3] * m[1][0] * m[2][1])) - (m[2][0] * m[1][1] * m[0][3]) - (m[1][0] * m[0][1] * m[2][3]) - (m[0][0] * m[2][1] * m[1][3]);
        printf("Определитель = %.2f\n", det);
        printf("Определитель x = %.2f\n", detx);
        printf("Определитель y = %.2f\n", dety);
        printf("Определитель z = %.2f\n", detz);
        if(det != 0 && detx != 0 && dety != 0){
            x = detx/det;
            y = dety/det;
            z = detz/det;
            printf("x = %.2f, y = %.2f, z = %.2f\n", x, y, z);
        }
        else{ 
            printf("ОШИБКА! Один из определителей равен нулю!");
        }
    }
    
    //метод крмера на 5

    if (number == number){
        for(int i = 0; i<number; i++){
            
        }
    }
}
