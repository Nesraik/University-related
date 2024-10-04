#include <stdio.h>

int main(){
	int num[10];
	int maxvalue;
	int minvalue;
	float sum;
	int a;
	printf("Enter 10 integers: ");
		for(a=0;a<=9;a++){
			scanf("%d",&num[a]);
		}
	getchar();
	maxvalue=num[0];
	
		for (a=1;a<=9;a=a+1){
			if(maxvalue< num[a]){
			maxvalue=num[a];
			}
		}
		
	minvalue=num[0];
		for (a=1;a<=9;a=a+1){
			if(minvalue> num[a]){
			minvalue=num[a];
			}
		}
	sum = num[0];
	
		for (a=1;a<=9;a=a+1){
			sum = sum + num[a];
		}
	printf("Max Value = %d\n",maxvalue);
	
	printf("Min Value = %d\n",minvalue);
	
	printf("Average Value = %.2f\n",sum/10);
	getchar();
	return 0;
}
