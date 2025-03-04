#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void print_array(int n, int array[n]){
  for(int i =0; i<n; i++){
    printf("| %d ", array[i]);
  }
  printf("\n");
}

int main() {
  setlocale(LC_ALL, "ru_RU.UTF-8");
  
  int n;
  int i;
  int max = 0;
  double avg = 0;
  double after_avg = 0;
  printf("Введите длину массива:");
  scanf("%d", &n);
  int A[n];

  for(i=0; i<n; i++){
    printf("A[%d] = ", i);
    scanf("%d", &A[i]);
  }

  // max elemnt
  for(i=0; i<n; i++){
    if(A[i] > max) max=A[i];
  }

  //counting avg
  for(i=0; i<n; i++){
    if(A[i] > 0) avg += A[i];
  }

  printf("До удаления avg=%.2f \n", avg / n);

  //delete simple digit////////////////////////
  int cnt = 0;

    for(i = 2; i <= max; i++){
      if(max % 2 == 0 | max % 3 == 0 | max % i == 0) cnt++;
      // printf("cnt= %d \n", cnt);
    }

    if(cnt > 2) printf("Непростое число max = %d! Отмена!\n", max);
      else {
        printf("Число max: %d простое! Удаляю числа равные max!\n", max);
        for (i=0; i<n; i++){
          if(max == A[i]) A[i] = 0;
        }
      }

  //counting after_avg
  for(i=0; i<n; i++){
    if(A[i] > 0) after_avg += A[i];
  }

  printf("После avg=%.2f \n", after_avg / n);
  
  printf("max=%d \n", max);

  print_array(n, A);

  printf("Отсортированный массив по убыванию:\n");

  int tmp;
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n-i-1; j++){

    //Написать по убыванию модулей
    if (abs(A[j]) < (abs(A[j+1]))){
      tmp = A[j];
      (A[j] = A[j+1]);
      A[j+1] = tmp;
    }
   }
  }
  print_array(n, A);
  printf("\n");

}