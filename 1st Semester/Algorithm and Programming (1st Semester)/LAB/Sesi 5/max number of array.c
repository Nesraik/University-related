#include <stdio.h>

int main(){
	int num[5];
	int maxvalue;
	int a;
	printf("Enter 5 integers: ");
		for(a=0;a<5;a++){
			scanf("%d",&num[a]);
		}
	getchar();
	maxvalue=num[0];
	
		for (a=1;a<=5;a=a+1){
			if(maxvalue< num[a]){
			maxvalue=num[a];
			}
		}
		
	printf("Max Value = %d\n",maxvalue);
	return 0;
}
