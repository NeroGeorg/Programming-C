#include <stdio.h>
#include <math.h>

void main(){

int year;
int res;
printf("Year:");
scanf("%d", &year);
printf("Year=%d\n", year);
	if(year%400==0){
		printf("Year %d visokosniy\n ", year);
	}else if(year%100==0){
		printf("Year %d ne visokosniy\n", year);
	}else if(year%4==0){
		printf("Year %d visokosniy\n", year);
	}
	else{
		printf("Year %d ne visokosniy\n", year);
	}
}
