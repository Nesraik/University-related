#include <stdio.h>

int main(){
	int matrix1[4][4];
	int matrix2[4][4];
	int a,b;
	int sum[4][4];
	printf("Enter the Element of First 4 x 4 Matrix.\n");
	for(a=0;a<4;a++){
		for(b=0;b<4;b++){
			scanf("%d",&matrix1[a][b]);
		}
	}
	getchar();
	printf("Enter the Element of Second 4 x 4 Matrix.\n");
	for(a=0;a<4;a++){
		for(b=0;b<4;b++){
			scanf("%d",&matrix2[a][b]);
		}
	}
	getchar();
	printf("This is the sum of 2 matrices\n");
	for (a = 0; a<4; a++)  
    {  
        for (b = 0; b <4; b++)  
        {  
            sum[a][b] = matrix1[a][b] + matrix2[a][b];  
            printf("%d ", sum[a][b]);  
        }  
        printf("\n");
    }  
	getchar();
	return 0;
}
/*
Input from question:    
First Matrix
3 4 5 5                      
5 6 7 9                             
1 7 11 10                    
2 8 9 4   

Second Matrix                   
1 2 3 4
8 7 6 5          
9 10 11 2
6 5 4 3

Ouput:
4 6 8 9
13 13 13 14
10 17 22 12
8 13 13 7
*/




