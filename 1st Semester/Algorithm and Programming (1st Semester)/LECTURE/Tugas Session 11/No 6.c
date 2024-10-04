#include <stdio.h>

int main(){
	int x,y;// declare x and y as integer
	for(x=1; x<=3; x++){//execute statements inside as long as x<=3 and the starting value of x is 1 
						//hence it will execeute statements inside three times
		int x=5;// set x to 5 to be printed out and for y to follow in the next repetition
		printf("x=%d ",x++);//prints out x=5 and increment by 1
		for(y=0;y<x; y++){// execute statements inside as long as y<x and starting value of y is 0 where as x is 6 
						//so it will print out x=20 6 times
			int x=20; // set x to 20 to be printed out later
			printf("x=%d ",x++);// prints out x=20 and increment by 1 
		}						
		printf("\n");// prints new line
	}
	return 0;
}
/*
x=5 x=20 x=20 x=20 x=20 x=20 x=20
x=5 x=20 x=20 x=20 x=20 x=20 x=20
x=5 x=20 x=20 x=20 x=20 x=20 x=20
-its a nested for which prints out x=5 3 times and x=20 18(3*6) times
-for(x=1; x<=3; x++) execute statement inside for 3 times as x is set to 1 and the condtion is x<=3 hence 3 times
the statement inside of for(x=1; x<=3; x++) code: 
1)int x=5 
2)printf("x=%d ",x++)
3)another for loop which is for(y=0;y<x; y++)
4)printf("\n")


-for(y=0;y<x; y++) execute statement inside for 6 times as y is set to 0 and the condition is y<x(which is 6 since x = 5 is increment by 1,hence 6)
the statement inside of for(y=0;y<x; y++):
1)int x=20 
2)printf("x=%d ",x++)

-since for(y=0;y<x; y++) is inside for(x=1; x<=3; x++),the statement inside of for(y=0;y<x; y++) is executed 18 times (3*6)

*/
