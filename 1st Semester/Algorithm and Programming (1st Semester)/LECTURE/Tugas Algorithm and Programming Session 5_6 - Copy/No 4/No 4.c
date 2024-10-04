#include "stdio.h"
void main() {
	int y = 33, x =45;
	y = y && x; printf("%d\n",y);
	y = y & x; printf("%d\n",y);
	y = 33 , x = 45;
	y = y & x; printf("%d\n",y);
	y = y && x; printf("%d\n",y);
}
/*
y = 1
y = 1
y = 33
y = 1
*/
