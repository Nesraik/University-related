#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct CakeShop{
	int no;
	char CakeCode[10];
	char CakeName[100];
	int Availability;
	float price;
}CakeShop;


void SellStock(CakeShop Cakes[4]){
	int i,found=0,indchange,quantitytest;
	char cakecodetest[10];
	printf("Input Cake Code [5 Chars]: ");
	scanf("%s",cakecodetest);
	getchar();
	
	
	for(i=0;i<4;i++){
		if(strcmp(cakecodetest,Cakes[i].CakeCode)==0){
			found=1;
			indchange=i;
			break;
			}
		}
	
	while(found!=1){
		printf("---The Cake Code Doesnot Exist---\n");
		printf("Input Cake Code [5 Chars]: ");
		scanf("%s",cakecodetest);
		getchar();
		for(i=0;i<4;i++){
		if(strcmp(cakecodetest,Cakes[i].CakeCode)==0){
			found=1;
			indchange=i;
			break;
			}
		}
	}
	
	printf("Input Quantity [0..%d]: ",Cakes[indchange].Availability);
	scanf("%d",&quantitytest);
	
	while(quantitytest<=0 && quantitytest>Cakes[indchange].Availability){
		printf("Quantity cannot be 0 or the quantity of cake is not enough\n");
		printf("Input Quantity [0..%d]: ",Cakes[indchange].Availability);
		scanf("%d",&quantitytest);
	}
	
	Cakes[indchange].Availability=Cakes[indchange].Availability-quantitytest;
	
	float totalprice = Cakes[indchange].price*quantitytest;
	
	printf("\n\nTotal Price is: Rp%.0f,- x %d = Rp%.0f,-\n",Cakes[indchange].price,quantitytest,totalprice);
	
	printf("\n---Thank You---\n");
}



void Addstock(CakeShop Cakes[4]){
	int i,found=0,indchange=0,quantitytest;
	char cakecodetest[10];
	printf("Input Cake Code [5 Chars]: ");
	scanf("%s",cakecodetest);
	getchar();
	
	for(i=0;i<4;i++){
		if(strcmp(cakecodetest,Cakes[i].CakeCode)==0){
			found=1;
			indchange=i;
			break;
			}
		}
	
	while(found!=1){
		printf("---The Cake Code Doesnot Exist---\n");
		printf("Input Cake Code [5 Chars]: ");
		scanf("%s",cakecodetest);
		getchar();
		for(i=0;i<4;i++){
		if(strcmp(cakecodetest,Cakes[i].CakeCode)==0){
			found=1;
			indchange=i;
			break;
			}
		}
	}
	
	printf("Input Quantity [0..10]: ");
	scanf("%d",&quantitytest);
	
	while(quantitytest<=0 || quantitytest>10){
		printf("Quantity cannot be 0 or more than 10\n");
		printf("Input Quantity [0..10]: ",Cakes[indchange].Availability);
		scanf("%d",&quantitytest);
	}
	
	Cakes[indchange].Availability=Cakes[indchange].Availability+quantitytest;
	
	printf("---Adding Stock Success---\n");
	
	
}
void Database(CakeShop Cakes[4]){
	//Cakecode
	strcpy(Cakes[0].CakeCode,"CK001");
	strcpy(Cakes[1].CakeCode,"CK009");
	strcpy(Cakes[2].CakeCode,"CK017");
	strcpy(Cakes[3].CakeCode,"CK023");
	
	//Name of Cakes
	strcpy(Cakes[0].CakeName,"Blueberry Cake");
	strcpy(Cakes[1].CakeName,"Chococip Cake");
	strcpy(Cakes[2].CakeName,"Mayonaise Cake");
	strcpy(Cakes[3].CakeName,"Strawberry Shortcake");
	
	//Availabity
	Cakes[0].Availability=13;
	Cakes[1].Availability=5;
	Cakes[2].Availability=24;
	Cakes[3].Availability=7;

	//Price
	Cakes[0].price=25000;
	Cakes[1].price=20000;
	Cakes[2].price=30000;
	Cakes[3].price=17500;
	
}

int main(){
	CakeShop* Cakes=malloc(4*sizeof(*Cakes));
	Database(Cakes);
	int menu;
	int i;

	do{
	printf("BLUE CAKE SHOP CASHIER\n");
	printf("======================\n\n");
	printf("No\t|Cake Code\t|Cake Name\t\t\t|Available\t|Price\n");
	printf("--------------------------------------------------------------------------------------------\n");
	for(i=0;i<4;i++){
		printf("%d\t|",i+1);
		printf("%s\t\t|",Cakes[i].CakeCode);
		printf("%-20s\t\t|",Cakes[i].CakeName);
		printf("%d\t\t|",Cakes[i].Availability);
		printf("Rp%.0f,-",Cakes[i].price);
		printf("\n");
	}
	printf("--------------------------------------------------------------------------------------------\n");
	
		printf("Menu:\n");
		printf("1. Sell\n");
		printf("2. Add Stock\n");
		printf("3. Exit\n");
		printf("Input choice: ");
		scanf("%d",&menu);
		switch(menu){
			case 1:
				SellStock(Cakes);
				system("pause");
				system("cls");
				break;
			case 2:
				Addstock(Cakes);
				system("pause");
				system("cls");
				break;				
		}	
	}while(menu!=3);
	free(Cakes);
	
}
