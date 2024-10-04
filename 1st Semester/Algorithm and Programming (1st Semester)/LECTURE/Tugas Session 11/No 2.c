#include <stdio.h>
void hanoi(int n, char *left_rod, char *right_rod, char *middle_rod){
	if(n==1){
		printf("Move plate %d from %s pillar to the %s pillar\n",n,left_rod,right_rod);
		return;
	}
	hanoi(n-1,left_rod,middle_rod,right_rod);
	printf("Move plate %d from %s pillar to the %s pillar\n",n,left_rod,right_rod);
	hanoi(n-1,middle_rod,right_rod,left_rod);
}
int main(){
	int n;
	n=4;
	hanoi(n,"left","right","middle");
	return 0;
}
