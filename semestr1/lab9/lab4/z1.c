#include <stdio.h>

void main(){

	int n=0, t;
	printf("Input times:");
	scanf("%d", &t);
	printf("Input length:");
	scanf("%d", &n);

	for(int i = 0; i<t; i++){
	for(int i = 0; i<n; i++ ){
		printf("*");
	}
	printf("\n");

	for(int i=0; i<n-2; i++){
		printf("*");
		for(int j=0; j<n-2; j++){
			printf("-");
		}
		printf("*");
		printf("\n");
	}

	for(int i=0; i<n; i++){
	printf("*");
	}
	printf("\n");
	printf("\n");
	}
}
