#include <stdio.h>

int digit (unsigned long long int n){
	int count;
	for(count=0;n!=0;){
		n=n/10;
		count++;		
	}
	return count;
}
int main(){
	int count,casenumber,caselimit;
	unsigned long long int n;
	scanf("%d",&caselimit);
	for(casenumber=1;casenumber<=caselimit;casenumber++){
	scanf("%llu",&n);
	printf("Case #%d: %d\n",casenumber,digit(n));
}
	return 0;
}
