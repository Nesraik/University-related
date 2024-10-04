#include <stdio.h>
#include <stdlib.h>
struct address{
	char street[100];
	char area[100];
};

struct name{
	char Firstname[20];
	char Middlename[20];
	char Lastname[20];
};

struct Employee{
	int id;
	struct name Employeename;
	struct address Employeeaddress;
	char jobtitle[20];
	char gender[10];
};

int main(){
	
	struct Employee Employees;
	
	//Input
	printf("Enter ID: ");
	scanf("%d",&Employees.id);
	getchar();
	
	printf("<<Name>>\n");
	printf("Enter first name: ");
	scanf("%s",Employees.Employeename.Firstname);
	getchar();
	
	printf("Enter middle name: ");
	scanf("%s",Employees.Employeename.Middlename);
	getchar();
	
	printf("Enter last name: ");
	scanf("%s",Employees.Employeename.Lastname);
	getchar();
	
	printf("<<Address>>\n");
	printf("Enter street name: ");
	scanf("%s",Employees.Employeeaddress.street);
	getchar();
	
	printf("Enter area name: ");
	scanf("%s",Employees.Employeeaddress.area);
	getchar();
	
	printf("Enter job title: ");
	scanf("%s",Employees.jobtitle);
	getchar();
	
	printf("Enter gender: ");
	scanf("%s",Employees.gender);
	getchar();
	
	system("cls");
	//Output
	printf("Name: %s %s %s\n",Employees.Employeename.Firstname,Employees.Employeename.Middlename,Employees.Employeename.Lastname);
	printf("Address: %s, %s\n",Employees.Employeeaddress.street,Employees.Employeeaddress.area);
	printf("Job title: %s\n",Employees.jobtitle);
	printf("Gender: %s\n",Employees.gender);
	
}

