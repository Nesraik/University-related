#include <stdio.h>
#include <stdlib.h>

int main() {
	int A, B, x, y, z;
	scanf("%d %d", &A, &B);
	getchar();
	y = (B - A) + 1;
	z = A + B;
	x = y * z/2;
	printf("%d\n", x);
	getchar();
	return 0;
}
