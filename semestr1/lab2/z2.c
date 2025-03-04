#include <stdio.h>

void main(){

	float temp;
	char tip;
	printf("Input:");
	scanf("%f %c", &temp, &tip);
	if (tip=='c' || tip== 'C'){
		float tempf =(temp*1.8+32);
		printf("%ff\n", tempf);
	}
	else if(tip == 'f' ||  tip== 'F'){
		float tempc =((temp-32)/1.8);
		printf("%fc\n", tempc);
	}
	else
	{
		printf("Error x_x\n");
	}

}
