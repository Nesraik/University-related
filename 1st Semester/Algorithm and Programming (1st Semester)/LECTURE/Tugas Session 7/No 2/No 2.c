#include <stdio.h>
#include <stdlib.h>
int main() {
	float x;
		printf("Enter Your IPK: ");
		scanf("%f",&x);
	getchar();
				if(x>=3.5 && x<=4.0){
					printf("Cumlaude");
				}
				if(x>=3.0 && x<3.5){
					printf("Outstanding");
				}
				if(x>=2.5 && x<3.0){
					printf("Very Good");
				}
				if(x>=2.0 && x<2.5){
					printf("Good");
				}
				if(x<2.0){
					printf("Poor");
				}
	getchar();
	return 0;
}
