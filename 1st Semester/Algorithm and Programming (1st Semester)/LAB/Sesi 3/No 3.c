#include <stdio.h>

int main(){
	float score;
	printf("Enter Your Score: ");
	scanf("%f",&score);
	getchar();
	if(score>=90 && score <=100){
		printf("Your grade is A.");
	}else if(score>=80 && score <90){
		printf("Your grade is B.");
	}else if(score>=70 && score <80){
		printf("Your grade is C.");
	}else if(score>=60 && score <70){
		printf("Your grade is D.");
	}else{
		printf("Your grade is E.");
	}
	getchar();
	return 0;
}
