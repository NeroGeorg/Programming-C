#include <stdio.h> 

int main(){

	int n=0,a,s=0,k=0;
	printf("Input a:");
	scanf("%d", &a);

	for(n=a,s=0;n!=0;n=n/10){
	k=n%10;
	s=s+k;
	}
	printf("Сумма= %d\n", s);
}
