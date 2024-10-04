#include <bits/stdc++.h>

int MinimumPerimeter(int Number){
	int SqrNum = sqrt(Number);
	int PowSqrNum = SqrNum * SqrNum;
	int perimeter;
	if(PowSqrNum == Number ){
		return SqrNum* 4;
		}
		else{
			int row = Number/SqrNum;
			perimeter = 2 * (SqrNum + row);
			
			//Count Perimeter for Leftover Blocks
			if(Number % SqrNum != 0){
				return perimeter +=2;
			}
			return perimeter;
		}
}

int main(){
	int NumOfBlocks;
	scanf("%d",&NumOfBlocks);
	int answer = MinimumPerimeter(NumOfBlocks);
	printf("%d\n",answer);
}
