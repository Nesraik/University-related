#include <stdio.h>

int main (){
	int max, num1,num2,num3;
	max = 0;
	printf("Enter 3 Numbers: ");
	scanf("%d %d %d",&num1,&num2,&num3);
	getchar();
	//If
	if(max<=num1){
		max=num1;
	}
	if(max<=num2){
		max=num2;
	}if(max<=num3){
		max=num3;
	}
	//If else
	if(max<=num1){
		max=num1;
	}else{
		max=max;
	}
	if(max<=num2){
		max=num2;}
	else{
		max=max;
	}	
	if(max<=num3){
		max=num3;
	}else{
		max=max;
	}
	//Nested If
	if(max<=num1){
		max = num1;
		if(max<=num2){
			max = num2;
			if(max<=num3){
				max = num3;
			}
		}
	}
	printf("The largest number is %d\n",max);
	getchar();
	return 0;
}
