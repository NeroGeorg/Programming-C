#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct complex
  {
  float re;
  float im;
  };

void rand_complex(int n , struct complex *c);

void print_array(int n, int *array);