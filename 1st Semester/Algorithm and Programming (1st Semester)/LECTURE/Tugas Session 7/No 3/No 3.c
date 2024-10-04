#include <stdio.h>
#include <stdlib.h>

int main() {
	if(n>0)
		if(a > b)
			z = a;
		else
			z = b;	
	return 0;
}
/*
-The else code is paired with the if(a > b) code since that if code describe whether a > b is true or false.
If it is true, then it will execute (z = a;) code below the if(a > b)code and if it is false, it will then
execute the statement within the else code which is (z = b;).
-To improve the readability of the code,
Curley brackets need to be used after the first if code (if(n>0)), the second if code (if(a > b)) and the else code.
The curley bracket will show which block of statement is in the if/else code, hence improving the readability of the code
You can also add some whitespaces (space,tab) to further improve the readability.
*/
