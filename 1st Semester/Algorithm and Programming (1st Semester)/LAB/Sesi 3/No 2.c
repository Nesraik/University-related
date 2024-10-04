#include <stdio.h>

int main(){
// can use scanf("%d",&n); to ask for input
// or set n to a specific value e.g 1,2,3
// set variable n to a data type e.g int,float,double
	switch (n){
		case 1:
			printf("The number is 1\n");
			//should use break; here so that when the value of n matches with case 1 it will only do (printf("The number is 1\n");)
		case 2:
			printf("The number is 2\n");
			break; // since there wasnt any break; code at the end of case 1, when the condition matches with case1, the statement in case2 is also executed 
					 //alongside with case1.	
		default:
			printf("The number is not 1 or 2\n");
			break;	
	}
	return 0;// add return 0; to end the program after executing all the statement.
}
/*
-There should be a break code(break;) at the end of case 1 hence when the condition of first case (case1)  is reached,
it will only print the text "The number is 1"(printf("The number is 1\n");) and stops within case1;
-The way the program works is that it checks whether the value of n matches with the cases inside of switch (n) and if it matches,
it will immediately does the instruction/statement within that specific case. It either needs to ask for user the value for n or
decide ourselves because it needs the value of n to check the condition inside the switch cases.
-The variable n should also be declared be it integer or float data type.
*/
