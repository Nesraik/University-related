#include <stdio.h>
 // a)
int main(){
	int mark;
	char grade;
	scanf("%d",&mark);
	if(mark>=85) 
		grade = 'A';
	if(mark>=75) 
		grade = 'B';
	printf("%c",grade);
	return 0;
}
/*
The output of the code above if the input = 90 is 'B';
*/
// b)
int main(){
	int mark;
	char grade;
	scanf("%d",&mark);
	if(mark>=85) 
		grade = 'A';
	else if(mark>=75) 
		grade = 'B';
	else{
	}
	printf("%c",grade);
	return 0;
}
/*
The output of the code above if the input = 90 is 'A';
*/
/*
Block of codes a is similar but actually different from block of code b
- Both if code inside block of codes a is not connected.
When the input is 90, it fulfill both condition of both if.
the first if code's condition is fulfilled.
(mark>=85,input is 90), the grade is set to 'A'.
since both ifs are not connected it doesnt stop here.
it continues to the second if which is 
mark>=75 since input 90 fulfill this condition, the grade that was set to 'A' is set to 'B'.
Hence, the final output is 'B'.

- Both if code inside block of codes B is connected because the use of "else if".
Even though inputs (90) fulfill condition of both if (mark>=85) and if(mark>=75),
it stops checking after the first if condition is fulfilled and set the grade to 'A'.
Hence, the final output is 'A'.  
*/










