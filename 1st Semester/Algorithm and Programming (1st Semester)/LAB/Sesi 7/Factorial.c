#include <stdio.h>
unsigned long long int factorial(int n){
	if(n==1){
		return 1;
	}else{
		return n*(factorial(n-1));
	}
}
int main(){
	int n;
	unsigned long long int result;
	printf("This program will factorialize a number\n");
	printf("Enter a Number: ");
	scanf("%d %d",&n,&n);
	result = factorial(n);
	printf("%llu",result);
	return 0;
}
