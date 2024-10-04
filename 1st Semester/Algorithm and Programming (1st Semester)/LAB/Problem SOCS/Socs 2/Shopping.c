#include <stdio.h>

int main(){
	double A,B,C,D;
	double P,Q,R,S;
	double W,X,Y,Z;
	scanf("%lf %lf",&A,&P);
	scanf("%lf %lf",&B,&Q);
	scanf("%lf %lf",&C,&R);
	scanf("%lf %lf",&D,&S);
	W = 100/(100-A)*P;
	X =100/(100-B)*Q;
	Y = 100/(100-C)*R;
	Z = 100/(100-D)*S;
	printf("$%.2lf\n",W);
	printf("$%.2lf\n",X);
	printf("$%.2lf\n",Y);
	printf("$%.2lf\n",Z);
	
	
	
	return 0;
}
