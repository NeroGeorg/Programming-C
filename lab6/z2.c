#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void rand_array(int n, int array[n]){
  for(int i = 0; i<n; i++){
    array[i] = rand() % 10 + 1;
  }
}

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
  printf("Введите длину массива:");
  scanf("%d", &n);

  //initialize time for random digits
  srand(time(0));

  //delacre arrays
  int A[n];
  int B[n];
  int C[n/2];
  C[0]=0;

  //random value of arrays
  rand_array(n, A);
  rand_array(n, B);

  // A[i]+B[j]
  for(i = 2; i < n; i+=2){
    C[i/2] = A[i];
    printf("C[i/2] = %d \n", A[i]);
    if(i-1 < n){
      C[i/2] += B[i-1];
      printf("C[i/2] += %d \n", B[i-1]);
    }
    // четные
    
    // if(i % 2 == 0){
    //   C[i] = A[i];
    // }
    // //нечетные
    // else{
    //   C[i] = A[i];
    // }

    // нечётные

    // if(B[i] % 2 == 0 && A[i] % 2 != 0 | i == 0){
    //   printf("NoЧётные A:%d + четная B:%d \n", A[i], B[i]);
    //   C[i] = A[i] + B[i];
    // }

  }

  int max = 0;
  for(int i =2; i<n; i+=2){
    if(A[i] > max) max=A[i];
  }

  int cnt = 0;
  for(int i =2; i<n; i+=2){
    if(B[i] < 0) cnt++;
  }

  double avg = 0;
  int sum = 0;
  for(i=0; i<(n/2); i++){
    if(C[i] > 0) sum += C[i];
  }
  avg = sum / (n/2);

  printf("Количество мнимых частей < 0 в массиве B: %d \n", cnt);
  printf("Максимальная реальная часть комплексных чисел массива А: %d \n", max);
  printf("После avg=%.2f \n", avg);

  //arrays output
  print_array(n, A);
  print_array(n, B);
  print_array(n/2, C);

}