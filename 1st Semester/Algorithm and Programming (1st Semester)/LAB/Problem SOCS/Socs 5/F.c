#include <stdio.h>

int main(){
	int result,size,num[1000];
	int caselimit;
	scanf("%d",&caselimit);
	for(int casenumber=1;casenumber<=caselimit;casenumber++){
	scanf("%d",&size);
	for(int i=0;i<size;i++){
		scanf("%d",&num[i]);
	}
	result=0;
	for(int i=0;i<size;i++){
		result+=num[i];
	}
	printf("Case #%d: %d\n",casenumber,result);
}
	
	
	return 0;
}
