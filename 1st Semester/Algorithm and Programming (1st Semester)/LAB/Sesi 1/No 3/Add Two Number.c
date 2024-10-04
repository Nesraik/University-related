#include <stdio.h>
#include <stdlib.h>

int main() {
	int A, B, Result;
	printf("Enter first integer\n");
	scanf("%d",&A);
	printf("Enter second integer\n");
	scanf("%d",&B);
	getchar();
	Result = A + B;
	printf("Sum is %d\n", Result);
	getchar();
	return 0;
}
