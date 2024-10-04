#include <stdio.h>

int main() {
	int x = 11;
	printf("Odd Number from 11 to 188\n");
	do {
		printf(" %d ",x);
		x=x+2;
	}while(x<=188);
	getchar();
	return 0;
}
