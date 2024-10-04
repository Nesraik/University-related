#include <iostream>


int main(){
	int caselimit;
	scanf("%d",&caselimit);
	int Number[caselimit];
	
	for(int casenumber=0;casenumber<caselimit;casenumber++){
		scanf("%d",&Number[casenumber]);
	}
	for(int i=0;i<caselimit;i++){
		int count=2;
		int done =0;
			for(int j=2;j<Number[i];j++){
				if(Number[i]%j==0){
					count++;
				}
				if(count>3){
						printf("NO\n");
						done=1;
						break;
				}
			}
			if(done==0){
				if(count==3){
					printf("YES\n");
					}else{
					printf("NO\n");
					}
				}
			}	
}
