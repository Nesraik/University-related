#include "stdio.h"
void main() {
	float x;
	x = 7/2;
	printf("x=%f\n",x);
	x = 7.0/2;
	printf("x=%f\n",x);
	x = 7/2.0;
	printf("x=%f\n",x);
	x = 7.0/2.0;
	printf("x=%f\n",x);	
}
/*
x = 3.000000
x = 3.500000
x = 3.500000
x = 3.500000
*/
