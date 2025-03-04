#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//функция вывод массива 
void print_matrix(int n, int m, int matrix[n][m]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            printf(" %d", matrix[i][j]);
            }
            printf("\n");
        }
}

int number;

void rand_matrix(int n, int m, int matrix[n][m]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            matrix[i][j] = rand() % 9 + 1;
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
    int det = 0;
    if (number == 2){
        det = (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
        printf("Определитель = %d\n", det);
    }
    if (number == 3){
        det = ((m[0][0] * m[1][1] * m[2][2]) + (m[2][0] * m[0][1] * m[1][2]) + (m[0][2] * m[1][0] * m[2][1])) - (m[2][0] * m[1][1] * m[0][2]) - (m[1][0] * m[0][1] * m[2][2]) - (m[0][0] * m[2][1] * m[1][2]);
        printf("Определитель = %d\n", det);
    }
    
    
}
