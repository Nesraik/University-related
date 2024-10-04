#include <stdio.h>
int main() {
	int n;
	for(; ;){
		printf("\n Enter Integer: "); scanf("%d",&n);
		if((n%2) == 0) continue;
		else if((n%3)==0) break;
		printf("\n\t Bottom of loop.");		
	}
	printf("\n\t Outside of loop.");

	return 0;
}
/*
 Enter Integer: 7

         Bottom of loop.
 Enter Integer: 4

 Enter Integer: 9

         Outside of loop.
         
7 = prints out "Bottom of loop."
4 = prints out nothing
9 = prints out "Outside of loop."
*/
