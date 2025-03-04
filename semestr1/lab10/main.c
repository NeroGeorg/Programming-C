#include "functions.h"

int main() { 

  int n;
  printf("Введите длину массива:");
  scanf("%d", &n);

  srand(time(0));

  int *a = (int *)malloc(n * sizeof(int *));
  int *b = (int *)malloc(n * sizeof(int *));
  int *c = (int *)malloc(n * sizeof(int *));

  //random value of arrays
  struct complex c1;  

  for (int i = 0; i<n; i++){
    rand_complex(n, &c1);
    a[i] = c1.re; 
    b[i] = c1.im; 
  }

  for (int i = 0; i<n; i++){
      c[i] = a[i] + b[i]; 
  }

  //arrays output
  printf("Реальная часть:\n");
  print_array(n, a);
  printf("Мнимая часть:\n");
  print_array(n, b);
  printf("Массив комплексных чисел:\n");
  print_array(n, c);

  int max = 0;
  int min = c[0];
  for(int i =0; i<n; i++){
    if(c[i] > max) max = c[i];
    if(c[i] < min) min = c[i];
  }

  printf("Максимальное число массива С: %d \n", max);
  printf("Минимальное число массива C: %d \n", min);

  //очищаем
    free(a);
    free(b);
    free(c);
    
    a = NULL;
    b = NULL;
    c = NULL;

}