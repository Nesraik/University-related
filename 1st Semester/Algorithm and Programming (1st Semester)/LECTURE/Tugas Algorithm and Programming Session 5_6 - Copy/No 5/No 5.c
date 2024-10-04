#include <stdio.h>

void main() {
	int y, n=10;
	y = ++n;
	printf("y = %d\n",y);
}// y = 11
void main(){
	int n=10;
	n++;
	printf("n = %d\n",n);
}// n = 11
void main(){
	int y, n = 10;
	y=n++;
	printf("y=%d\n",y);		
}// y = 10
void main (){
	int n = 10;
	++n;
	printf("n = %d\n",n);		
}// n = 11

