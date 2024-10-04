#include <stdio.h>
#include <stdlib.h>
int main() {
	char name[100];
	scanf("%[^\n]",name);
	getchar();
	printf("Happy Birthday to %s.\n",name);
	getchar();
	return 0;
}
