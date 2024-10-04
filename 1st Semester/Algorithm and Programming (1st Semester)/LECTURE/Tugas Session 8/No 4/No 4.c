#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,j;
	for(i=0, j=1; i<8; i++, j++) printf("%d + %d = %d\n", i, j, i+j);
/*	The output of the code above:
	0 + 1 = 1
	1 + 2 = 3
	2 + 3 = 5
	3 + 4 = 7
	4 + 5 = 9
	5 + 6 = 11
	6 + 7 = 13
	7 + 8 = 15 
*/
	for(i=0, j=1; i<8; ++i, ++j); printf("%d + %d = %d\n", i, j, i+j);
/*  The output of the code above:
	8 + 9 = 17	
*/	
	return 0;
}
/* 	
-The code (for(i=0, j=1; i<8; i++, j++) printf("%d + %d = %d\n", i, j, i+j);) will
print out "0 + 1 = 1" as the first output of the loop since variable i (which represents the first number) is declared as 0
, variable j (which represents the second number) is declared as 1
and the third number is the sum of the variable i (first number) and variable j (second number) (0+1=1). 
The second output will be "1 + 2 = 3" as the value of i and j is increased by 1 (i++, j++). The third output will be "2 + 3 = 5' and so on.
It will keep looping as long as the value of i is less than 8 (i<8).
and if the value reach 7 (less than 8), the program will stop printing ("%d + %d = %d\n", i, j, i+j) and the final output of the loop
will be "7 + 8 = 15". as i is 7 (less than 8), j is 8 and 15 is the result of 7+8

-The code (for(i=0, j=1; i<8; ++i, ++j); printf("%d + %d = %d\n", i, j, i+j);) will only prints out "8 + 9 = 17" which is 
the final output of (for(i=0, j=1; i<8; ++i, ++j)) Loop increment by 1 ("7 + 8 = 15" to "8 + 9 = 17" because of ++i and ++j code)

-The difference of the code (for(i=0, j=1; i<8; i++, j++) printf("%d + %d = %d\n", i, j, i+j);) and 
(for(i=0, j=1; i<8; ++i, ++j); printf("%d + %d = %d\n", i, j, i+j); lies in the use of semicolon.
The first code has no semicolon before the printf code while the other has a semicolon placed before the printf code.
Semicolon works as seperator between (for(i=0, j=1; i<8; ++i, ++j) and (printf("%d + %d = %d\n, i, j, i+j))
It stops the loop of printing ("%d + %d = %d\n, i, j, i+j) over and over, 
hence it will only print out the value of (i+1) and (j+1) from the final output of (for(i=0, j=1; i<8; ++i, ++j) loop.
Instead of printing "7 + 8 = 15"(which is the final output of the loop), it prints out "8 + 9 = 17".
This happens because there are two codes such as (++i) and (++j) that increases the value by 1.
The presence of semicolon before the printf code cause the program to assume that it only wants the final output of the loop
and increases the value by 1 (++i, ++j).
Instead of printing the whole output of looping ("0 + 1 = 1" "1 + 2 = 3" "2 + 3 = 5" and so on), it only prints out the added version
of the final output ("8 + 9 = 17" because of (++i and ++j))

-The second difference of both code would be the position of the increment sign (++).
The code ((for(i=0, j=1; i<8; i++, j++) printf("%d + %d = %d\n", i, j, i+j);) used an increment sign after the variable i and j
while the other code (for(i=0, j=1; i<8; ++i, ++j); printf("%d + %d = %d\n", i, j, i+j) used it before the variable i and j
The code ((for(i=0, j=1; i<8; i++, j++) printf("%d + %d = %d\n", i, j, i+j);) used it as "post-increment" while the other code
(for(i=0, j=1; i<8; ++i, ++j); printf("%d + %d = %d\n", i, j, i+j) used it as "pre-increment".
In some cases, post-increment operator and pre-increment operator would produce a different output but in this program, 
it didnot make any difference as both code used the printf code after "post-increment" and 
"pre-increment"operator is applied to i and j variable (i++, j++ = post-increment, ++i, ++j = pre-increment)
*/

