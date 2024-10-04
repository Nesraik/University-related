#include <stdio.h>
struct kmhs{
	char nim[11];
	char name[30];
	float gpa;
};

int main(){
	struct kmhs Student[5];
	for(int i=0;i<5;i++){
		printf("Student #%d\n",i+1);
		printf("NIM: ");
		scanf("%[^\n]",Student[i].nim);
		getchar();
		printf("\nName: ");
		scanf("%[^\n]",Student[i].name);
		getchar();
		printf("\nGPA: ");
		scanf("%f",&Student[i].gpa);
		getchar();
		printf("\n");
	}
	printf("\nGPA >= 3.0\n");
	for(int i=0; i<5; i++){
		if(Student[i].gpa >= 3.0){
			printf("%s\n",Student[i].name);
		}
	}
	printf("===================================\n");
	printf("GPA < 3.0\n");
	for(int i=0; i<5; i++){
		if(Student[i].gpa < 3.0){
			printf("%s\n",Student[i].name);
		}
	}
	return 0;  
}
