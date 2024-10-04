#include <stdio.h>
int GCF(int num1, int num2){
	int gcf;
	for(int i=1;i<=num1&&i<=num2;i++){
		if(num1%i==0 && num2%i==0){
			gcf=i;
		}
	}
	return gcf;
}
int LCM(int num1, int num2){
	int max,lcm;
	if(num1>num2){
		max=num1;
	}else{
		max=num2;
	}
	while(1){
		if(max%num1==0 && max%num2==0){
			lcm=max;
			break;
		}
		max++;
	}
	return max;
}

int main(){
	int num1,num2;
	printf("A program to find GCF and LCM of two integers\n");
	while(1){
	printf("Enter two integers(input -1 to end): \n");
	scanf("%d",&num1);
	if(num1==-1){
		break;
	}
	scanf("%d",&num2);
	printf("The GCF is %d\n",GCF(num1,num2));
	printf("The LCM is %d\n",LCM(num1,num2));
}
	return 0;
}
