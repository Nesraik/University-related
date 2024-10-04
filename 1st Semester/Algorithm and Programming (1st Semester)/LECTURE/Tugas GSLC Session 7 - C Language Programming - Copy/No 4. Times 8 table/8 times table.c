#include <stdio.h>
#include <stdlib.h>

int main() {
	int num = 8;
	int result;
	int x;
	printf("Times 8 table \n");
	for(x=1;x<=10;x++){
		result = x * num;
		printf("%d x %d = %d", x, num, result);
		printf("\n");
	}
	getchar();
	return 0;
}
