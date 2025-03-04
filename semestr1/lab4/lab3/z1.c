#include <stdio.h>

int main(){

	int n, m, k;
	printf("Input:");
	scanf("%d", &n);
	for( m = 1, k = 0; m <= n; k++, m = m * 2 );
	printf("Число ближе к 2 в такой степени: %d\n", k-1);

}
