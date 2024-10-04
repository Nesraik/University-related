#include <stdio.h>


int main()
{
	int dice,dicemax,sum = 0,order;
	scanf("%d",&dicemax);
	for(dice=1;dice<=dicemax;dice++){
		scanf("%d",&order);
		sum+=order;
	if(sum == 12){
		sum = 28;
	}else if(sum == 30){
		sum = 10;
	}else if(sum ==35){
		sum = 7;
	}else if(sum >=40){
		sum-=40;
	}
}		
	printf("%d\n",sum);
    return 0;
}
