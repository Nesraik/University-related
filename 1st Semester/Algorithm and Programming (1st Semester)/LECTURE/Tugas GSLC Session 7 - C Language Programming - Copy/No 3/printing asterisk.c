#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c;
	printf("Enter a Number: ");
	scanf("%d",&a);
	getchar();
	for(b=0;b<a;b++){
		for(c=0;c<a;c++)
	{printf("*");}
		printf("\n");
	}
	getchar();
	return 0;
}
