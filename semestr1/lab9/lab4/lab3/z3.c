#include <stdio.h> 

int main(){


	int s,i,n;
	printf("Введите степень:");
	scanf("%d", &n);

	for(s=1,i=0;i<n;i++) s=s*2;
	printf("2^%d = %d \n", n, s);
}
