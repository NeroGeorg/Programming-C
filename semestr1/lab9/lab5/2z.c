#include <stdio.h>
#include <locale.h>

int main() {
  setlocale(LC_ALL, "ru_RU.UTF-8");
  unsigned int a = 0xaabbcc; // 000000000000000000000000000000000101
  unsigned char c;
  unsigned char b;
  unsigned int x;
  
  printf("Исходное значение a: %x\n", a);

  b = ((a >> 8) & 0xff);//bb
  c = (a & 0xff); //cc
  x = (a & 0xffff0000) | (c << 8) | b;

  printf("Измененное значение x: %x\n", x);

  printf("End!");
  scanf("%d", &a);
}