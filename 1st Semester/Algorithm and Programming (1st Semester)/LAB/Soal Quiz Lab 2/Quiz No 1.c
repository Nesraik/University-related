#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Soal Quiz No 1
struct records{
	char user_id[10];
	char product_id[12];
	char gender;
	char age[7];
	float purchase;
};


int main(){
	struct records record[6000];
	int limit=0;
	FILE*fptr;
	fptr=fopen("data.txt","r");
	
	char idtest[20];
	printf("Masukan User_ID: ");
	fflush(stdin);
	scanf("%[^\n]",idtest);
	getchar();
	system("cls");
	
	printf("Data yang sesuai dengan User_ID\n\n");
	while(fscanf(fptr,"\n%[^','],%[^','],%[^','],%[^','],%f",&record[limit].user_id,&record[limit].product_id,&record[limit].gender,&record[limit].age,&record[limit].purchase)){
		if(strcmp(record[limit].user_id,idtest)==0){
			printf("Product_ID: %s\n",record[limit].product_id);
			printf("Gender: %c\n",record[limit].gender);
			printf("Age: %s\n",record[limit].age);
			printf("Purchase: %.0f\n",record[limit].purchase);
		}
	}
	fclose(fptr);
}
