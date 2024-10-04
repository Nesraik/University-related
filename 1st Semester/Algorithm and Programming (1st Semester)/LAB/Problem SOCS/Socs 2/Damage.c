#include <stdio.h>
int main() {
	int A , B,C;
	float D;
	scanf("%d %d %d",&A,&B,&C);
	A = A * 2/10;
	B = B * 3/10;
	C = C * 5/10;
	D = A + B +C;
	printf("%.2f",D);
	getchar();
	return 0;
}
