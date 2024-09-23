#include <stdio.h>
#include <math.h>

void main(){

float x,y;
printf("Input x:");
scanf("%f", &x);
printf("Input y:");
scanf("%f", &y);
//printf("x= %f, y= %f", x, y);

if ( x >= -1 && x <= 1 && y >= 0 && y <= -x+1)
	{
	printf("Точка попадает в облать\n");
	}

else if(x >= -2 && x <= 1 && y >= -2 && y <= 0)
	{
	printf("Точка попадает в область\n");
	}

else	
	{
	printf("Точка не попадает в область\n");
	}

}
