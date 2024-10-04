#include <stdio.h>
int main() {
	int x,y;
	for(x=1;x<=3;x++)
		for(y=3;y>=1;y--)
			printf("%d %d ",x,y);		
	return 0;
}
/* The output of the code above is:
1 3 1 2 1 1 2 3 2 2 2 1 3 3 3 2 3 1 
*/
int main() {
	int x,y;
	for(x=1;x<=3;x++);
		for(y=3;y>=1;y--)
			printf("%d %d ",x,y);
		
	return 0;
}
/*The output of the code above is
4 3 4 2 4 1 
*/
