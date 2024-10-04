#include <stdio.h>
#include <stdlib.h>

struct contacts{
	char phonenumber[50];
	char email [50];
};

struct StudentDetail{
	char NIM[20];
	char name[100];
	struct contacts *contact;
	//contact = malloc(sizeof(struct contacts));
};

int main(){
	struct StudentDetail *ptrStudentDetail;
	ptrStudentDetail = malloc (sizeof(struct StudentDetail));
	//contact = malloc(sizeof(struct contacts));

	
	printf("Enter student ID: ");
	fflush(stdin);
	scanf("%s",ptrStudentDetail->NIM);
	getchar();
	
	printf("Enter Name: ");
	fflush(stdin);
	scanf("%[^\n]",ptrStudentDetail->name);
	getchar();
	
	/*printf("Enter Phone Number: ");
	fflush(stdin);
	scanf("%s",ptrStudentDetail->contact->phonenumber);
	getchar();
	
	printf("Enter Email: ");
	fflush(stdin);
	scanf("%s",ptrStudentDetail->contact->email);
	getchar();
	*/
	//ptrStudentDetail = &Students;
	system("cls");
	
	printf("NIM: %s\n",ptrStudentDetail->NIM);
	printf("Name: %s\n",ptrStudentDetail->name);
	//printf("Phone Number: %s\n",ptrStudentDetail->contact->phonenumber);
	//printf("Email: %s\n",ptrStudentDetail->contact->email);
	
	
}
