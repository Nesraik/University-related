#include <stdio.h>
#include <stdlib.h>

int main() {
	int num;
	int result;
	int x;
	printf("Enter an Integer:  \n");
	scanf("%d",&num);
	getchar();
	printf("Times %d Table\n", num);
	for(x=1;x<=10;x++){
		result = x * num;
		printf("%d x %d = %d", x, num, result);
		printf("\n");
	}
	getchar();
	return 0;
}
