#include <stdio.h>
int binary(int number){
	int i,container[1000];
	for(i=0;number>0;i++){
		container[i]=number%2;
		number=number/2;
	}
	printf("Binary number: ");
	for(i=i-1;i>=0;i--){
		printf("%d",container[i]);
	}printf("\n");

}
int main(){
	int number,container[1000],i;
	printf("Enter a number: ");
	scanf("%d",&number);
	binary(number);
	printf("Octal number: %o\n",number);
	printf("Hexadecimal number: %x\n",number);
	return 0;
}
/*
input 
15870

Output
Binary number: 11110111111110
Octal number: 36776
Hexadecimal number: 3dfe
*/
