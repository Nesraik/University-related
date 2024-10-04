#include <stdio.h>
#include <stdlib.h>
int main() {
	int A;
	int B=23, C=12, D=32, E=0;
	A = B && E;
	A = B & C;
	A = C || D;
	A = B | D;
	A = B > 2;
	A = B >> 2;
	A = C < 3;
	A = C << 3;
	A = B = C;
	A = B == C; 
	return 0;
}
/*
a) A = 0
b) A = 4
c) A = 1
d) A = 55
e) A = 1
f) A = 5
g) A = 0
h) A = 96
i) A = 12
j) A = 0
*/
