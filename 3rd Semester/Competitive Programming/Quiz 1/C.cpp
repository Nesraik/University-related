#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
int solve(int* health, int n)
{
	int currentgcd = gcd(health[0], health[1]);

	for (int i = 2; i < n; ++i) {
		currentgcd = gcd(currentgcd, health[i]);
	}
	return currentgcd;
}


int main()
{
	int n;
	scanf("%d",&n);
	int health[n];
	for(int i=0;i<n;i++){
		scanf("%d",&health[i]);
	}
	
	int answer = solve(health,n);
	printf("%d\n",answer);

	return 0;
}

