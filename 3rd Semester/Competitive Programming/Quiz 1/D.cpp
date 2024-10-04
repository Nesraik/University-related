#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
bool isown(ll k){
	if(k==1)return true;
	if(k==2)return false;
	ll a = sqrt(k);
	for(ll i=2;i<=a;i++){
		if(k%i==0)return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	ll number;
	cin >> number;
	if(isown(number)==true){
		cout << number -1;
	}else{
		ll a = sqrt(number);
		if(number%a==0){
			ll b = number/a;
			cout<< a+b-2;
		}else{
			ll lowa = a*a, lowb= (a+1)*(a+1);
			ll low = abs(number - lowa)<abs(number-lowb)?a:a+1;
			ll bit;
			for(ll i = low-1; i>=1;i--){
				if(number%i==0){
					bit = i;
					break;
				}
			}
			ll sit=number/bit;
			cout<<sit+bit-2;
			}	

		}
	}
