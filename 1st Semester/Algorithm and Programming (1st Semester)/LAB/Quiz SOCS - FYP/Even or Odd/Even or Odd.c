#include <stdio.h>
#include <stdlib.h>


int main() {
	int A;
	scanf("%d", &A);
	getchar();
	if(A % 2 == 0){
		printf("EVEN\n");
	}else{
		printf("ODD\n");
	}
	getchar();
	return 0;
}
