#include <stdio.h>
void divide(float x, int y, float *z){
	if(y==0) /*return*/;// this "return" will return/giveback 0 if y is equals to 0. You can remove this and the program can still run properly
	*z=x/y;				// so long as y is not equals to 0. If y is indeed equals to 0, it will produce 1.#INF00 error which happens when
						// a number is divided by 0
						
}
float div(float x, int y){
	if(y!=0); /*return*/ (x/y);// this "return" cannot be removed as this "return" allows the function to return/give back the value of x/y  
}								// if its removed this float div function can not return the value of x/y
void main(){
	float f,a=12.75; int b=5;
	divide(a,b,&f);
	printf("%f divided by %d = %f\n",a,b,f);
	b=3;
	f=div(a,b);
	printf("%f divided by %d = %f\n",a,b,f);
}

