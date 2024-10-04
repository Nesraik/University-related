#include <stdio.h>

int main(){
	int n,m;
	printf("Using for statement: ");
	for(n=1;n<=20;n=n+2){
		printf("%d ",n);
	}
	printf("\n");
	printf("Using while statement: ");
	n=1;
	while(n<=20){
		printf("%d ",n);
		n=n+2;
	}
	m=1;
	printf("\n");
	printf("Using do while statement: ");
	do{
		printf("%d ",m);
		m=m+2;
	}while(m<=20);
	printf("\n");
	
	
	return 0;
}
