#include <stdio.h>

int main() {
	int e=555;
	int w=59;
	int l=1004, d=8;
	printf("|%d|\n", e);
	printf("|%5d|\n", e);
	printf("|%-5d|\n", e);
	printf("\n");
	printf("Words:%d\n",w);
	printf("Letters:%d\n",l);
	printf("Digits:%d\n", d);
	float a=0.1, b=0.2;
	printf("a= %f\n", a);
	printf("b= %f\n", b);
	printf("a + b = %.10f\n", a+b);
}
