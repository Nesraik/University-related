#include <stdio.h>

void swap(char A, char B){
	char C;
	C = A; A = B; C = B;
}
void main(){
	char X,Y;
	X = 'S'; Y = 'D';
	swap(&X,&Y);
	printf("X = %c Y = %c",X,Y);
}
// Repair
/*
void swap(char *A, char *B){ -> convert A and B variable into a pointer (*A) and (*B) so that it could point to the address of X and Y
	char C;
	C = *A; *A = *B; *B = C;-> since A and B become pointer (*A) and (*B), the rest follows
}							-> when assigning things, its usually left variable that is assigned to right variable hence *B = C
void main(){
	char X,Y;
	X = 'S'; Y = 'D';
	swap(&X,&Y); -> Should add & before X and Y, to tell the address of X and Y so that A and B can point to its address
	printf("X = %c Y = %c",X,Y);
}
*/
