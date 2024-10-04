#include <stdio.h>
int powernum(unsigned long long int number,unsigned long long int power, int modval){
	unsigned long long int result = 1;
	number=number%modval;
	while(power>0){
		if(power&1){
			result = (result*number)%modval;
		}
		power = power>>1;
		number=(number*number)%modval;
	}
	return result;
}
int main(){
	int number,number2,number3;
	int caselimit;
	scanf("%d %d",&number,&number2,&number3);
	int modval=1000000007;
	int pow1 = powernum(number,number3,modval);
	printf("%d",pow1);
	
	return 0;
}
