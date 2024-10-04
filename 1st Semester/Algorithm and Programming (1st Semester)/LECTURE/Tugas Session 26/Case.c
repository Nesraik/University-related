#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct products{
	char productcode[12];
	char productname[30];
	float quantity;
	float price;
};
struct purchases{
	char productname2[30];
	float quantity2;
	float price2;
	float subtotal;
};

FILE*fptr;
char customername[32];
float productquantitytest;
char productcodetest[12];

void FinishSales(struct purchases purchase[100]){
	fptr=fopen("purchase.txt","r");
	printf("Thank you %s,\n\n",customername);
	int i=0;
	printf("Purchase list\n");
	printf("==============\n");
	printf("\n\nProduct name\t\t\t Quantity\t\t Price\t\t\t Subtotal\n");
	while(fscanf(fptr,"%[^'#']#%f#%f#%f\n",&purchase[i].productname2,&purchase[i].quantity2,&purchase[i].price2,&purchase[i].subtotal)!=EOF){
		printf("%-20s\t\t %-20.0f\t %-20.3f\t %.3f\n",purchase[i].productname2,purchase[i].quantity2,purchase[i].price2,purchase[i].subtotal);
		i++;
	}
	int limit = i;
	fclose(fptr);
	char discountlogo='%';
	float total=0;
	float discount=0;
	float discamt=0;
	float amtdue=0;
	for(int i=0; i<limit;i++){
		total+=purchase[i].subtotal;
	}
	if(total>=1000000){
		discount = 0.1;
	}else if(total>500000){
		discount = 0.08;
	}else if(total>300000){
		discount = 0.05;
	}else{
	}
	discamt = discount * total;
	
	amtdue = total - discamt;
	printf("\nTotal: %f\n",total);
	printf("Discount: %.0f%c\n",discount*100,discountlogo);
	printf("Disc Amt: %.3f\n",discamt);
	printf("Amount due: %.3f\n",amtdue);
	
	char renamefile[30];
	strcpy(renamefile,customername);
	strcat(renamefile,".txt");
	
	rename("purchase.txt",renamefile);
}

void InputSales(struct products product[100]){
	struct purchases purchase;
	int indganti,found=0;
	
	fptr=fopen("data.txt","r");
	printf("Enter Product Code: ");
	fflush(stdin);
	scanf("%s",productcodetest);
	
	int limit=0;
	while(fscanf(fptr,"%[^'#']#%[^'#']#%f#%f\n",&product[limit].productcode,&product[limit].productname,&product[limit].quantity,&product[limit].price)!=EOF){
		limit++;
	}
	fclose(fptr);
	
	for(int i=0;i<limit;i++){
		if(strcmp(product[i].productcode,productcodetest)==0){
			indganti=i;
			found=1;
			break;
		}
	}

	if(found ==0){
		printf("Product doesnot exist\n");
		return;
	}
	
	printf("Enter Quantity: ");
	scanf("%f",&productquantitytest);
	
	while(productquantitytest<1 || productquantitytest > product[indganti].quantity){
		printf("Invalid amount of quantity\n");
		printf("Enter Quantity: ");
		fflush(stdin);
		scanf("%f",&productquantitytest);
	}
	
	product[indganti].quantity = product[indganti].quantity - productquantitytest;
	
	fptr=fopen("data.txt","w");
	for (int i = 0; i < limit; i++)
    {
    if(i == limit-1){
    fprintf(fptr,"%s#%s#%.0f#%.3f",product[i].productcode,product[i].productname,product[i].quantity,product[i].price);
	}
	else{
	fprintf(fptr,"%s#%s#%.0f#%.3f\n",product[i].productcode,product[i].productname,product[i].quantity,product[i].price);
		}
    }
	fclose(fptr);
	
	strcpy(purchase.productname2,product[indganti].productname);
	purchase.quantity2=productquantitytest;
	purchase.price2=product[indganti].price;
	purchase.subtotal= productquantitytest * purchase.price2;
	
	fptr=fopen("purchase.txt","a");
	fprintf(fptr,"%s#%.0f#%.3f#%.3f\n",purchase.productname2,purchase.quantity2,purchase.price2,purchase.subtotal);
	fclose(fptr);
	
}
void ReadProduct(struct products product[100]){
	fptr=fopen("data.txt","r");
	int limit=0;
	printf("Product Code\t\t\t Product Name\t\t\t Quantity\t\t Price\n");
	printf("=======================================================================================================\n");
	while(fscanf(fptr,"%[^'#']#%[^'#']#%f#%f\n",&product[limit].productcode,&product[limit].productname,&product[limit].quantity,&product[limit].price)!=EOF){
		printf("%-20s\t\t %-20s\t\t %-20.0f\t %.3f\n",product[limit].productcode,product[limit].productname,product[limit].quantity,product[limit].price);	
	}
	fclose(fptr);
}

void MainMenu(){
	int menu;
	struct products product[100];
	struct purchases purchase[100];
	system("cls");
	do{
	ReadProduct(product);
		printf("\n<<Main Menu>>\n");
		printf("1.Input sales\n");
		printf("2.Finish sales\n");
		printf("3.Exit\n");
		printf("Option: ");
		scanf("%d",&menu);
		
		switch(menu){
			case 1:
				system("cls");
				InputSales(product);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				FinishSales(purchase);
				system("pause");
				system("cls");
				return;
				break;
		}
	}while(menu!=3);
}

int main(){
	int menu,option;
	do{
	system("cls");
	printf("\nCustomer's name: ");
	fflush(stdin);
	scanf("%[^\n]",customername);
	getchar();
	int length=strlen(customername);
	
	while(length<5 || length>30){
		printf("invalid customer name\n");
		printf("Customer's name: ");
		fflush(stdin);
		scanf("%[^\n]",customername);
		getchar();
		length=strlen(customername);
		}
	MainMenu();
	printf("Do you want to continue?\n");
	printf("1.Yes\n");
	printf("2.No\n");
	printf("Option: ");
	scanf("%d",&option);
	if(option==2){
		break;
	}
	}while(1);
	system("cls");
	printf("-----------------------------Purchase saved succesfully-----------------------------\n");
}
