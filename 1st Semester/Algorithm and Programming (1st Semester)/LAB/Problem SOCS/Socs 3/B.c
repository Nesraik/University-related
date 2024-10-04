#include <stdio.h>

int main(){
	int casenumber,caselimit;
	int gojo,bipay;
	scanf("%d",&caselimit);
	for(casenumber=1;casenumber<=caselimit;casenumber++){
		scanf("%d %d",&gojo,&bipay);
		if(gojo>bipay){
			printf("Case #%d: Go-Jo\n",casenumber);
		}else{
			printf("Case #%d: Bi-Pay\n",casenumber);
		}
	}
	
	
	
	return 0;
}
