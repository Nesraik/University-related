#include <stdio.h>
#include <string.h>

int main(){
	char name[100];
	int casenumber,caselimit,order,orderlimit,count,count2;
	scanf("%d",&caselimit);
	for(casenumber=1;casenumber<=caselimit;casenumber++){
	scanf("%d",&orderlimit);
	char bibi = 'B';
	char lili = 'L';
	count = 0;
	count2 = 0;
	for(order=0;order<=orderlimit;order++){
		scanf("%c",&name[order]);
	}	
	for(order=0;order<=orderlimit;order++){
	if(name[order]==lili){
			count = count + 1;
		}
	if(name[order]==bibi){
			count2= count2 + 1;
		}
	}
	if(count>count2){
		printf("Lili\n");
	}if(count2>count){
		printf("Bibi\n");
	}if(count==count2){
		printf("None\n");
	}
}
	return 0;
}
