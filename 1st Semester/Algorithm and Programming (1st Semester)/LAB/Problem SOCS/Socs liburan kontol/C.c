#include <stdio.h>

int main(){
	long long int numin,size;
	int found;
	scanf("%ld",&size);
	int num[size];
	for(int i=0;i<size;i++){
		scanf("%ld",&num[i]);
		}
	scanf("%llu",&numin);
	for(int i=0;i<size;i++){
		if(numin>=num[i]){
			found+=1;
		}
		numin=numin-num[i];
		if(numin<0){
			numin=0;
		}
	}
	printf("%d",found);
	return 0;
}
