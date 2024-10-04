#include <stdio.h>
#include <string.h>
int main(){
	int max,max2,size,container,counter,counterfound,caselimit,num[1000];
	scanf("%d",&caselimit);
	for(int casenumber=1;casenumber<=caselimit;casenumber++){
	container=0;
	counter= 0;
	counterfound=0;
	scanf("%d",&size);
	for(int i=0;i<size;i++){
		scanf("%d",&num[i]);
	}
	for(int a=0;a<size;a++){
		for(int b=a+1;b<size;b++){
			if(num[a]<num[b]){
			container=num[a];
			num[a]=num[b];
			num[b]=container;
			}
		}
	}
	for(int a=0;a<size;a++){
		if(counterfound==1){
			counterfound=0;
		}
		for(int b=a+1;b<size;b++){
			if(counterfound==1){
				break;
			}
			for(int c=b+1;c<size;c++ ){
				if(num[a]==num[b]+num[c]){
					counter++;
					counterfound=1;
					break;
				}
			}
		}
	}
	printf("Case #%d: %d\n",casenumber,counter);
}
	return 0;
}
