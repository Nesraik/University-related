#include <stdio.h>
union hexadecimal{
	unsigned int number : 32;
};

int main(){
	int num;
	union hexadecimal hexa;
	printf("Enter an Integer: ");
	scanf("%d",&num);
	hexa.number=num;
	printf("0x%x",hexa.number);
	return 0;
}
