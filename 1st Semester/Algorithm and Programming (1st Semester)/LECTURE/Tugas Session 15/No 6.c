#include <stdio.h>

struct studentscore{
	char nim[11];
	char name[30];
	char subjectcode[5];
	int sks;
	char grade;
};

int main(){
	struct studentscore Student[5];
	printf("NIM: ");
	scanf("%[^\n]",Student[0].nim);
	getchar();
	printf("Name: ");
	scanf("%[^\n]",Student[0].name);
	getchar();
	for(int i=0;i<5;i++){
		printf("\nSubject %d\n",i+1);
		printf("Subject Code: ");
		scanf("%s",Student[i].subjectcode);
		getchar();
		printf("SKS: ");
		scanf("%d",&Student[i].sks);
		getchar();
		printf("Grade: ");
		scanf("%c",&Student[i].grade);
		getchar();
	}
	char grades []={'E','D','C','B','A'};
	
	float sumgrade,totalsks;
	float GPA;
	sumgrade=0;
	totalsks=0;
	for(int i=0; i<5 ; i++){
		totalsks+=Student[i].sks;
		for(int j=0; j<5; j++){
			if(Student[i].grade==grades[j]){
				sumgrade+= j*Student[i].sks;	
			}
		}
	}
	GPA= sumgrade/totalsks;
	printf("\n===============================\n");
	printf("\nGPA: %.2f",GPA);
	return 0;
}
