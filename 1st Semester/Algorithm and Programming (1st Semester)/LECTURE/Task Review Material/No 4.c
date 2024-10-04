#include <stdio.h>

int main(){
	int A;
	int B,C,D,E;
	B=13,C=11,D=42,E=0;
		
	A = B && E // The value of A is 0
	A = B & C // The value of A is 9
	A = C || D // The value of A is 1
	A = B | D // The value of A is 47
	A =  B > 2 // The value of A is 1
	A = B >> 2 // The value of A is 3
	A = C < 3 // The value of A is 0
	A = C << 3 // The value of A is 88
	A = B = C // The value of A is 11
	A = B == C // The value of A is 0
}
