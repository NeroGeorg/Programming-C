#include "functions.h"

struct complex;

void rand_complex(int n , struct complex *c){
  for(int i = 0; i < n; i++){
    c->re = (rand() % 201 - 100); 
    c->im = (rand() % 201 - 100);
  }
}

void print_array(int n, int *array){
  for(int i =0; i<n; i++){
    printf("| %d ", array[i]);  
  }
  printf("\n");
}