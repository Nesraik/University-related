#include <stdio.h>
#include <stdlib.h>
int main() {
	char id[11];
	char name[101];
	char Class;
	int num;
	scanf("%s\n",id);
	scanf("%[^\n]\n",name);
	scanf("%c %d",&Class, &num);
	getchar();
	printf("Id    : %s\n",id);
	printf("Name  : %s\n",name);
	printf("Class : %c\n",Class);
	printf("Num   : %d\n",num);
	return 0;
}
