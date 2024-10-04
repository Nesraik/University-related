#include <stdio.h>

int main() {
	long number, tmp, x=1;
	printf("\nInput number:"); scanf("%d", &number);
	tmp=number;
	while(number>= 1) x*=number--;
	printf("\n%1d ! = %1d",tmp, x);
	return 0;
}
/*
The program is design to factorialize a number that the user inputs, for example
if the input was 3, it will factorialize 3 and it will print out "3! = 6".
The way the program works is that it will input the number 3 and it will count down 
from 3 until it reaches 1 then the number that were count down which is 3 2 1
will all be multiplied and the result will be 6.
Finally, it will print out "3! = 6". 
*/
