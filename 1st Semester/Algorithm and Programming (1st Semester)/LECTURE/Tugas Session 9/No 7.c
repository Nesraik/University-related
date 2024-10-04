#include <stdio.h>

int main(){
	char *name[]= {"Ali","Ani","Tono"};
	char name[][10]= {"Ali","Ani","Tono"};
	return 0;
}
/*
-(char *name[]) is an array of pointer which stores pointer inside.
-(char name[][10]) is a 2d array which stores some string of character inside.
*/
