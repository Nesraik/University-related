#include <stdio.h>
#include <stdlib.h>

int main() {
	int N,M,x;
	int count = 0;
	scanf("%d %d", &N, &M);
	getchar();
	if(N<M){
		for(x=N;x<=M;x++){
			printf("%d \n",x);
		}
	}else if(N==M && count<M){
		for(x=N;count<M;x++){
			count++;
			printf("%d \n", x);
		}	
	}else{
		for(x=N;count<M;x++){
			count++;
			printf("%d \n",x);
		}
	}
	getchar();
	return 0;
}
