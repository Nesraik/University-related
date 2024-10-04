#include <stdio.h>
int scan(int num2[10]){
	int i;
	printf("Enter 10 integers: ");
	for(i=0;i<10;i++){
		scanf("%d",&num2[i]);
	}
}
int print(int num2[10],int maxvalue, int minvalue){
	int i;
	printf("The number you've inputted: ");
	for(i=0;i<10;i++){
		printf("%d ",num2[i]);
	}printf("\n");
	printf("Max Value: %d\n",maxvalue);
	printf("Min Value: %d\n",minvalue);
}	
int maxvalue(int num2[10]){
	int i,maxvalue;
	maxvalue = num2[0];
	for(i=0;i<10;i++){
		if(num2[i]>maxvalue){
			maxvalue = num2[i];
		}else{
			maxvalue = maxvalue;
		}
	}
	return maxvalue;
}
int minvalue(int num2[10]){
	int i,minvalue;
	minvalue = num2[0];
	for(i=0;i<10;i++){
		if(num2[i]<minvalue){
			minvalue = num2[i];
		}else{
			minvalue = minvalue;
		}
	}
	return minvalue;
}
int main(){
	int num[10];
	scan(num);
	int max= maxvalue(num);
	int min= minvalue(num);
	print(num,max,min);
	return 0;
}
