#include <stdio.h>
void divide(float x, int y, float *z){
	if(y==0) return; // this "return" will breaks out of if(y==0)code and return 0 as a result if the condition of (if(y==0)) is fulfilled
	*z=x/y;	
}
float div(float x, int y){
	if(y!=0) return (x/y); // this "return" will return/give back the result of x/y
}
void main(){
	float f,a=12.75; int b=5;
	divide(a,b,&f);
	printf("%f divided by %d = %f\n",a,b,f);
	b=3;
	f=div(a,b);
	printf("%f divided by %d = %f\n",a,b,f);
}

