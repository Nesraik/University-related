#include <stdio.h>
int main() {
	float a,b,c,d,P,Q,R,S,W,X,Y,Z;
	float E,T,F;
	scanf("%f %f %f %f",&a, &b, &c, &d);
	a = a * 2;
	b = (b/2)*4;
	c = (c/3)*6;
	d = (d/4)*4;
	E = a + b + c + d;
	printf("%.2f\n",E);
	scanf("%f %f %f %f",&P, &Q, &R, &S);
	P = P * 2;
	Q = (Q/2)*4;
	R = (R/3)*6;
	S = (S/4)*4;
	T = P + Q + R + S;
	printf("%.2f\n",T);
	scanf("%f %f %f %f",&W, &X, &Y, &Z);
	W = W * 2;
	X = (X/2)*4;
	Y = (Y/3)*6;
	Z = (Z/4)*4;
	F = W + X + Y + Z;
	printf("%.2f\n",F);
	return 0;
}
