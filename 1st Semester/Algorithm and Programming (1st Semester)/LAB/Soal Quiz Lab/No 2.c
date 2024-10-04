#include <stdio.h>
int checkprime(int num1){
	int primenumber;
	for(int i=2;i<num1;i++){
		if(num1%i==0){
			primenumber=primenumber+1;
			break;
		}
	}
	if(primenumber==1){
		printf("\n%d is not a prime number\n",num1);
	}else{
		printf("\n%d is a prime number\n",num1);
	}
}
int notprime(int num1){
	printf("%d is not a prime number\n",num1);
}
unsigned long long int factorial(int n){
	if(n==1){
		return 1;
	}else{
		return (n*(factorial(n-1)));
	}
}
int permutation(int num1, int num2){
	unsigned long long int permu;
	permu = factorial(num1)/factorial((num1-num2));
}
int combination(int num1, int num2){
	unsigned long long int combi;
	combi = factorial(num1)/(factorial(num2)*factorial((num1-num2)));
}
int main(){
	int permu;
	int num1,num2,numopsi;
	unsigned long long int permut,combin;
	printf("A program to check whether a positive integer is a prime number or not\n");
	printf("A program to also count permutation and combination\n");
	while(1){
	printf("\nChoose an instruction for the program to execute\n");
	printf("Input 1 to check for prime number\n");
	printf("Input 2 to find the result of permutatio\n");
	printf("Input 3 to find the result of combination\n");
	printf("Input -1 to end\n");
	scanf("%d",&numopsi);
	if(numopsi==1){
	printf("\nEnter a number: ");
	scanf("%d",&num1);
	if(num1==0 || num1==1){
		notprime(num1);
		continue;
	}
	checkprime(num1);
	}
	if(numopsi==2){
	printf("Enter two integers: ");
	scanf("%d",&num1);
	scanf("%d",&num2);
	permut=permutation(num1,num2);
	printf("\nThe result of %dP%d is %llu\n",num1,num2,permut);
}
	if(numopsi==3){
	printf("Enter two integers: ");
	scanf("%d",&num1);
	scanf("%d",&num2);
	combin=combination(num1,num2);
	printf("\nThe result of %dC%d is %llu\n",num1,num2,combin);
}	if(numopsi==-1){
	break;
}
}
	return 0;
}
