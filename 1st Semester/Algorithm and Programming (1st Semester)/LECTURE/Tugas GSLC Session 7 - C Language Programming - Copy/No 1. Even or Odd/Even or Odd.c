#include <stdio.h>
#include <stdlib.h>

int main() {
	int angka;
	printf("Enter the Number: ");
	scanf("%d", &angka );
	getchar();
	if(angka %2 == 0){
		printf("%d is an Even Number.", angka);
	}
	else{printf("%d is an Odd Number.", angka);
	}
	getchar();
	return 0;
}
