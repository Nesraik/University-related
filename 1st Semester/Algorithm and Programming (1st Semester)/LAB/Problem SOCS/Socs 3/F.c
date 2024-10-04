#include <stdio.h>

int main(){

	int size,row,column,newcolumn,casenumber,caselimit;
	scanf("%d",&caselimit);
	for(casenumber=0;casenumber<caselimit;casenumber++){
	scanf("%d",&size);
	int matrix1[size][size];
	int matrix2[size][size];
	int matrix3[size][size];
	int multi[size][size];
	int multi2[size][size];
	for(row=0;row<size;row++){
		for(column=0;column<size;column++){
			scanf("%d",&matrix1[row][column]);
		}
	}
	for(row=0;row<size;row++){
		for(column=0;column<size;column++){
			scanf("%d",&matrix2[row][column]);
		}
	}
	for(row=0;row<size;row++){
		for(column=0;column<size;column++){
			scanf("%d",&matrix3[row][column]);
		}
	}
	for(row=0;row<size;row++){
		for(column=0;column<size;column++){
			multi[row][column]=0;
			for(newcolumn=0;newcolumn<size;newcolumn++){
				multi[row][column]+=matrix1[row][newcolumn]*matrix2[newcolumn][column];
			}
		}
	}
	for(row=0;row<size;row++){
		for(column=0;column<size;column++){
			multi2[row][column]=0;
			for(newcolumn=0;newcolumn<size;newcolumn++){
				multi2[row][column]+=multi[row][newcolumn]*matrix3[newcolumn][column];
			}
		}
	}
	printf("Case #%d:\n",casenumber+1);
	for(row=0;row<size;row++){
		for(column=0;column<size;column++){
			printf("%d",multi2[row][column]);
			if(column == size-1){
                    printf("\n");
                }else{
                    printf(" ");
		}
	}	
}	
}
	return 0;
}
