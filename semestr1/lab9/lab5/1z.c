#include <stdio.h>
#include <locale.h>

void main(){
  setlocale(LC_ALL, "ru_RU.UTF-8");
  int n;
  int hex = 0x0f;
  printf("Input:");
  scanf("%d", &n);

  if ((n & hex) == 0){
      printf("Число %d кратно 16\n", n);
  }
  else{
    printf("Число %d некратно 16\n", n);
  }
  printf("End!");
  scanf("%d", &n);
}