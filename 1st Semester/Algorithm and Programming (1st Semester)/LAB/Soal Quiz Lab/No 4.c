#include <stdio.h>

int main(){
	int sum1,sum2,size1,size2,siswa;
	float avgipa,avgipafirst,avgips,avgipsfirst;
	scanf("%d %d",&size1,&size2);
	int ipa[size1],ips[size2];
	for(int i=0;i<size1;i++){
		scanf("%d",&ipa[i]);
	}
	sum1=0;
	for(int i=0;i<size1;i++){
		sum1+=ipa[i];
	}
	for(int i=0;i<size2;i++){
		scanf("%d",&ips[i]);
	}
	sum2=0;
	for(int i=0;i<size2;i++){
		sum2+=ips[i];
	}
	avgipafirst = sum1/size1;
	avgipsfirst = sum2/size2;
	if(avgipafirst>avgipsfirst){
	for(int i=0;i<size1;i++){
		sum1=sum1-ipa[i];
		avgipa=sum1/(size1-1);
		sum2=sum2+ipa[i];
		avgips=sum2/(size1+1);
		if(avgipa>avgipafirst && avgips>avgipsfirst){
			siswa++;
		}
	}
}
	printf("%d",siswa);
	return 0;
}
