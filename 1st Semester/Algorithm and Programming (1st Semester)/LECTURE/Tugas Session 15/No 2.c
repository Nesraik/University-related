#include <stdio.h>

struct Address{
	char streetname[40];
	int streeetnumber;
	char city[100];
	char province[100];
};
struct DOB{
	int date, month ,year;
};
typedef struct Student{
	int studentnumber;
	char Name[300];
	struct Address address;
	char BirthPlace[200];
	struct DOB dob;
}Students;
int main(){
	Students Student [30];
	for(int i=0; i<30; i++){
		printf("Student #%d\n",i+1);
		printf("Student Number: ");
		scanf("%d",&Student[i].studentnumber);
		getchar();
		printf("\nStudent Name: ");
		scanf("%[^\n]",Student[i].Name);
		getchar();
		printf("\nInput Address\n");
		printf("\nStreet Name: ");
		scanf("%[^\n]",Student[i].address.streetname);
		getchar();
		printf("\nStreet Number: ");
		scanf("%d",&Student[i].address.streeetnumber);
		getchar();
		printf("\nCity: ");
		scanf("%[^\n]",Student[i].address.city);
		getchar();
		printf("\nProvince: ");
		scanf("%[^\n]",Student[i].address.province);
		getchar();
		printf("\nBirth Place: ");
		scanf("%[^\n]",Student[i].BirthPlace);
		getchar();
		printf("\nInput Date of Birth\n");
		printf("Date: ");
		scanf("%d",&Student[i].dob.date);
		getchar();
		printf("\nMonth: ");
		scanf("%d",&Student[i].dob.month);
		getchar();
		printf("\nYear: ");
		scanf("%d",&Student[i].dob.year);
		getchar();
		printf("=======================================\n");
	}	
	return 0;
}
