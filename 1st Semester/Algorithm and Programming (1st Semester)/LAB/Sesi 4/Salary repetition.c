#include <stdio.h>

int main(){
	double sales,salary;
	int week,year;
	week = 1;
	year = 52;
	// do while
	do{
	printf("Enter sales in dollars (-1 to end): ");
	scanf("%lf",&sales);
	if(sales==-1){
		break;
	}
	salary= 200 + (sales * 9 / 100);
	printf("Salary is :$%.2lf\n",salary);
	}while(week<=52);
	week = 1;
	// while
	while(week<=52){
	printf("Enter sales in dollars (-1 to end): ");
	scanf("%lf",&sales);
	if(sales==-1){
		break;
	}
	salary= 200 + (sales * 9 / 100);
	printf("Salary is :$%.2lf\n",salary);
	}
	
	
	
	return 0;
}
