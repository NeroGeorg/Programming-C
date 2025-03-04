#include <stdio.h>

int main(){

	int s,n,a;
	printf("Input a:");
	scanf("%d", &a);

	for(s=0, n=2; n<a; n++){
		if(a%n==0) s++;
	}
	if(s==0) puts("Good");
	else{
		printf("Число делится на такое количество чисел: %d\n", s);}
}
