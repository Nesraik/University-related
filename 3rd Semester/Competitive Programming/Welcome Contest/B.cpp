#include <stdio.h>
using namespace std;

int main(){
	int caselimit,casenumber;
	scanf("%d",&caselimit);
	//char AnswerAllCase [caselimit][20];
	
	for(casenumber=1;casenumber<=caselimit;casenumber++){
	int Number,LowerLimit=0;
	scanf("%d",&Number);
	
	int StringNumber = 2 * Number -1;
	char BinaryString[StringNumber];
	scanf("%s",BinaryString);
	
	char Answer[Number];
    char BinaryStringSliced[20][20];
	int UpperLimit=Number;
	
	for(int i=0;i<Number;){
		for(int j=0;j<UpperLimit;j++){
			BinaryStringSliced[i][j] = BinaryString[LowerLimit];
			LowerLimit++;
		}
		UpperLimit++;
		i++;
		LowerLimit=i;
	}
	
	int count0=0,count1=0;
	
	for(int i=0;i<Number;i++){
		for(int j=0;j<Number;j++){
			if(BinaryStringSliced[i][j]=='0'){
				count0++;
			}else{
				count1++;
			}
		}
		if(count1>count0){
			Answer[i]='1';
		}else{
			Answer[i]='0';
		}
		count0=0;
		count1=0;
	}
	printf("%s\n",Answer);
	//strcpy(AnswerAllCase[casenumber],Answer);
	}
	/*for(casenumber =1;casenumber<=caselimit;casenumber++){
		printf("%s\n",AnswerAllCase[casenumber]);
	}*/	
}




