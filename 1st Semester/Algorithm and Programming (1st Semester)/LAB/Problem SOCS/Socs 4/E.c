#include <stdio.h>
int main(){
	int num,caselimit,result;
	scanf("%d",&caselimit);
	for(int casenumber=1;casenumber<=caselimit;casenumber++){
	scanf("%d",&num);
	result=0;
	for(int divisor=2;num>1;divisor++){
		if(num%divisor==0){
			result+=divisor;
		}
		while(num%divisor==0){
			num/=divisor;
		}
	}
	printf("Case #%d: %d\n",casenumber,result);
}
	
	
	
	
	return 0;
}
