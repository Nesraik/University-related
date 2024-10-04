#include <stdio.h>

int main(){
	int size,caselimit;
	scanf("%d",&caselimit);
	for(int casenumber=1;casenumber<=caselimit;casenumber++){
	scanf("%d",&size);
	int mat[size][size];
	int result[size];
	int row,col;
	for(row=0;row<size;row++){
		for(col=0;col<size;col++){
			scanf("%d",&mat[row][col]);
		}
	}
	for(row=0;row<size;row++){
		result[row]=0;
		for(col=0;col<size;col++){
			result[row]+=mat[col][row];
		}
	}
	printf("Case #%d: ",casenumber);
	for(row=0;row<size;row++){
		if(row==0){
		printf("%d",result[row]);
		}else{
		printf(" %d",result[row]);
		}
	}printf("\n");
}
	return 0;
}
