#include <stdio.h>

int main(){
	int matrix[4][4],matrix2[4][4],multi[4][4];
	printf("Enter the elements of the first matrix:\n");
	for(int i= 0;i<4;i++){
		for(int j= 0;j<4;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	printf("Enter the elements of the second matrix:\n");
	for(int i= 0;i<4;i++){
		for(int j= 0;j<4;j++){
			scanf("%d",&matrix2[i][j]);
		}
	}
	for(int i= 0;i<4;i++){
		for(int j= 0;j<4;j++){
			multi[i][j]=0;
			for(int k=0;k<4;k++){
				multi [i][j]+=matrix[i][k]*matrix2[k][j];
			}
		}
	}
	printf("This is the result of multiplication between two matrices:\n");
	for(int i= 0;i<4;i++){
		for(int j= 0;j<4;j++){
			printf("%d ",multi[i][j]);
		}
		printf("\n");
	}	
	return 0;
}
/* 
Input:
(First Matrix)
5 7 8 2
3 6 4 5
2 7 1 4
1 3 9 6

(Second Matrix)
3 5 4 8
2 5 2 3
1 1 2 7
3 7 6 1

Output:
43 82 62 119
40 84 62 75
33 74 48 48
36 71 64 86

*/












