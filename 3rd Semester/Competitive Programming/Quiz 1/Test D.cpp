#include <iostream>
#include <math.h>

bool isprime(long long int k){
	long long int a = sqrt(k);
	for(long long int i=2;i<=a;i++){
		if(k%i==0)return false;
	}
	return true;
}

int main(){
	long long int t;
	long long int number;
	scanf("%lld",&number);
	
	if(isprime(number)==true){
		printf("%lld\n",number-1);
	}else{
		long long int sqrtNum = sqrt(number);
		if(number%sqrtNum==0){
			long long int b = number/sqrtNum;
			printf("%d\n",sqrtNum+b-2);
		}else{
			long long int num1 = sqrtNum*sqrtNum, num2= (sqrtNum+1)*(sqrtNum+1);
			long long int lowerlimit = abs(number - num1)<abs(number-num2)?sqrtNum:sqrtNum+1;
			long long int divisor;
			for(long long int i = lowerlimit-1; i>=1;i--){
				if(number%i==0){
					divisor = i;
					break;
				}
			}
			long long int divisor2=number/divisor;
			printf("%d\n",divisor2+divisor-2);
			}	
		}
	}
