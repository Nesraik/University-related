#include <stdio.h>
#include <string.h>
int main(){
	int i,j,number,number2,size,length,caselimit,casenumber;
	char num[10000],numcontainer;
	scanf("%d",&caselimit);
	for(casenumber=1;casenumber<=caselimit;casenumber++){
	scanf("%d %s",&size,num);
	length=strlen(num);
	numcontainer=0;
	for(j=0;j<size;j++){
		scanf("%d %d",&number,&number2);
			while(number<=number2)
			numcontainer=num[number-1];
			num[number-1]=num[number2-1];
			num[number2-1]=numcontainer;
			number++;
			number2--;
		}
	}
	printf("Case #%d: %s\n",casenumber,num);

return 0;
}
