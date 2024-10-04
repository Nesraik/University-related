#include <stdio.h>
char A[200][200];
int total;
int totalX = -1;
int totalY = -1;
void FloodFill(int B, int C){
	if(A[B][C] == '*'){
    total += 1;
  }
  if(A[B][C] == '#' || A[B][C] == ' ' || B < 0 || C < 0 || B >= totalX || C >= totalY){
    return;
  } else{
    A[B][C] = '#';
  }
	FloodFill(B + 1, C);
	FloodFill(B - 1, C);
	FloodFill(B, C + 1);
	FloodFill(B, C - 1);
}
int main(){
	//kasus
	int caselimit;
	scanf("%d",&caselimit);
	getchar();
	for(int casenumber = 1; casenumber <= caselimit; casenumber++){
    scanf("%d %d", &totalX, &totalY);
    getchar();
    int X1 = -1;
	int Y1 = -1;
    for(int j = 0; j < totalX; j++){
      scanf("%[^\n]", A[j]);
      getchar();
	  }
    for(int j = 0; j < totalX; j++){
      for(int k = 0; k < totalY; k++){
        if(A[j][k] == 'P'){
          X1 = j;
          Y1 = k;
        }
      }
    }
    total = 0;
    if(X1 != -1 && Y1 != -1)
      FloodFill(X1, Y1);
    printf("Case #%d: %d\n", casenumber, total);
    for(int j = 0; j < totalX; j++){
    	for(int k = 0; k < totalY; k++){
        	A[j][k] = ' ';
    	}
	}
    totalX = 0;
    totalY = 0;
  }
  return 0;
}
