#include <stdio.h>
#include <stdlib.h>
int main(){
	int matrix1[4][4];
	int matrix2[4][4];
	int a,b,c;
	int multi[4][4];
	printf("Enter the Element of First 4 x 4 Matrix.\n");
	for(a=0;a<4;a++){
		for(b=0;b<4;b++){
			scanf("%d",&matrix1[a][b]);
		}
	}
	printf("Enter the Element of Second 4 x 4 Matrix.\n");
	for(a=0;a<4;a++){
		for(b=0;b<4;b++){
			scanf("%d",&matrix2[a][b]);
		}
	}
	getchar();
	printf("This is the Multiplication of 2 Matrices\n");
	for (a = 0; a<4; a++)  
    {  
        for (b = 0; b <4; b++)  
        {multi[a][b]=0;
			for(c=0;c<4; c++){ 
            multi[a][b] += matrix1[a][c]*matrix2[c][b];
        }  
    }
}
	for(a=0;a<4;a++){
		for(b=0;b<4;b++){
			printf("%d ",multi[a][b]);
		}printf("\n");
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
110 109 108 57
170 167 164 91
216 211 206 91
171 170 169 78
*/
