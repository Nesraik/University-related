#include <stdio.h>

int f1(int a,int b){
	int c,d;
	c = 2*a*b;
	d = 4*a*b;
	return c;
	return d;
}

int main(){
	int n1,n2,n3,n4;
	scanf("%d %d",&n1,&n2);
    getchar();
	n3 = f1(n1,n2);
	n4 = f1(n1,n2);
	printf("%d %d",n3,n4);
	return 0;
	
}
/*
Input
3 4

Output 
24 24
*/
