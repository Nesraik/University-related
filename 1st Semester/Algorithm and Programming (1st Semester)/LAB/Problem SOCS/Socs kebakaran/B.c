#include <stdio.h>

int SumArray(int num[],int index0, int size){
	if(index0>=size){
		return 0;
	}
	return(num[index0]+SumArray(num,index0+1,size));
}

int main(){
	int size,caselimit;
	scanf("%d",&caselimit);
	for(int casenumber=1;casenumber<=caselimit;casenumber++){
	scanf("%d",&size);
	int num[size];
	for(int i=0;i<size;i++){
		scanf("%d",&num[i]);
	}
	int Sum = SumArray(num,0,size);
	printf("Case #%d: %d\n",casenumber,Sum);
}
	return 0;
}
