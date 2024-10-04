#include <stdio.h>
#include <stdlib.h>
struct groceries{
	char product[20];
	int date1;
	int month1;
	int year1;
	int price;
	int date2;
	int month2;
	int year2;
	char aisle[10];
	char Category;
};

void monthselection(int x){
	switch(x){
		case 1:
			printf("January ");
			break;
		case 2:
			printf("February ");
			break;
		case 3:
			printf("March ");
			break;
		case 4:
			printf("April ");
			break;
		case 5:
			printf("May ");
			break;
		case 6:
			printf("June ");
			break;
		case 7:
			printf("July ");
			break;
		case 8:
			printf("August ");
			break;
		case 9:
			printf("September ");
			break;
		case 10:
			printf("October ");
			break;
		case 11:
			printf("November ");
			break;
		case 12:
			printf("December ");
			break;
	}
}
void MeatCreate(){
	struct groceries grocery;
	FILE*fptr;
	fptr=fopen("Grocery.txt","a");
	printf("Enter Product Name: ");
	scanf("%s",grocery.product);
	getchar();
	
	printf("Write 'R' for red meat\n");
	printf("Write 'P' for poultry\n");
	printf("Write 'F' for fish\n");
	printf("Product Category: ");
	scanf("%c",&grocery.Category);
	getchar();
	
	printf("Enter Price: ");
	scanf("%d",&grocery.price);
	getchar();
	system("cls");
	printf("Packaging\n");
	printf("Date: ");
	scanf("%d",&grocery.date1);
	getchar();
	
	printf("Month: ");
	scanf("%d",&grocery.month1);
	getchar();
	
	printf("Year: ");
	scanf("%d",&grocery.year1);
	getchar();
	
	system("cls");
	
	printf("Expiration\n");
	printf("Date: ");
	scanf("%d",&grocery.date2);
	getchar();
	
	printf("Month: ");
	scanf("%d",&grocery.month2);
	getchar();
	
	printf("Year: ");
	scanf("%d",&grocery.year2);
	getchar();
	
	system("Cls");
	fprintf(fptr,"%s;%c;%d;%d;%d;%d;%d;%d;%d\n",grocery.product,grocery.Category,grocery.price,grocery.date1,grocery.month1,grocery.year1,grocery.date2,grocery.month2,grocery.year2);
	printf("=============The Data You've just Added======================\n");
	printf("\nProduct Name: %s\n",grocery.product);
	printf("Category: %c\n",grocery.Category);
	printf("Price: %dC\n",grocery.price);
	
	printf("\nPackaging\n");
	printf("Date: %d\n",grocery.date1);	
	printf("Month: ");
	monthselection(grocery.month1);
	printf("\nYear: %d\n",grocery.year1);
	
	printf("\nExpiration\n");
	printf("Date: %d\n",grocery.date2);
	printf("Month: ");
	monthselection(grocery.month2);
	printf("\nYear: ");
	printf("%d\n",grocery.year2);
	fclose(fptr);
}
void ProduceCreate(){
	FILE*fptr;
	struct groceries grocery;
	fptr=fopen("Grocery.txt","a");
	printf("Enter Product Name: ");
	scanf("%s",grocery.product);
	getchar();
	
	printf("Write 'F' for Fruit\n");
	printf("Write 'V' for Vegetable\n");
	printf("Enter Product Category: ");
	scanf("%c",&grocery.Category);
	getchar();
	
	printf("Enter Price: ");
	scanf("%d",&grocery.price);
	getchar();
	system("cls");
	
	printf("Date Received\n");
	printf("Date: ");
	scanf("%d",&grocery.date1);
	getchar();
	printf("Month: ");
	scanf("%d",&grocery.month1);
	getchar();
	printf("Year: ");
	scanf("%d",&grocery.year1);
	getchar();
	
	system("Cls");
	fprintf(fptr,"%s;%c;%d;%d;%d;%d;\n",grocery.product,grocery.Category,grocery.price,grocery.date1,grocery.month1,grocery.year1);
	
	printf("=============The Data You've just Added======================\n");
	printf("\nProduct Name: %s\n",grocery.product);
	printf("Category: %c\n",grocery.Category);
	printf("Price: %d cents\n",grocery.price);
	
	printf("\nDate Received\n");
	printf("Date: %d\n",grocery.date1);
	printf("Month: ");
	monthselection(grocery.month1);
	printf("\nYear: %d\n",grocery.year1);
	fclose(fptr);
}

void DairyCreate(){
	FILE*fptr;
	struct groceries grocery;
	fptr=fopen("Grocery.txt","a");
	printf("Enter Product Name: ");
	scanf("%s",grocery.product);
	getchar();
	
	printf("Enter Price: ");
	scanf("%d",&grocery.price);
	getchar();
	system("cls");
	
	system("cls");
	printf("Expiration Date\n");
	printf("Month: ");
	scanf("%d",&grocery.month2);
	getchar();
	printf("Year: ");
	scanf("%d",&grocery.year2);
	getchar();
	system("cls");
	
	fprintf(fptr,"%s;%d;%d;%d;\n",grocery.product,grocery.price,grocery.month2,grocery.year2);
	
	printf("=============The Data You've just Added======================\n");
	printf("\nProduct Name: %s\n",grocery.product);
	
	printf("Price: %d cents\n",grocery.price);
	printf("\nExpiration Date\n");
	printf("Month: ");
	monthselection(grocery.month2);
	printf("\nYear: %d\n",grocery.year2);
	fclose(fptr);	
}

void CannedGoodsCreate(){
	FILE*fptr;
	struct groceries grocery;
	fptr=fopen("Grocery.txt","a");
	printf("Enter Product Name: ");
	scanf("%s",grocery.product);
	getchar();
	
	printf("Enter Price: ");
	scanf("%d",&grocery.price);
	getchar();
	system("cls");
	
	system("cls");
	printf("Expiration Date\n");
	printf("Month: ");
	scanf("%d",&grocery.month2);
	getchar();
	printf("Year: ");
	scanf("%d",&grocery.year2);
	getchar();
	
	printf("Aisle: ");
	scanf("%s",grocery.aisle);
	getchar();
	
	fprintf(fptr,"%s;%d;%d;%d;%s;\n",grocery.product,grocery.price,grocery.month2,grocery.year2,grocery.aisle);
	
	system("cls");
	printf("=============The Data You've just Added======================\n");
	printf("\nProduct Name: %s\n",grocery.product);
	
	printf("Price: %d cents\n",grocery.price);
	printf("\nExpiration Date\n");
	printf("Month: ");
	monthselection(grocery.month2);
	printf("\nYear: %d\n",grocery.year2);
	printf("Aisle: %s\n",grocery.aisle);
	fclose(fptr);
}

void NonFoodsCreate(){
	FILE*fptr;
	struct groceries grocery;
	fptr=fopen("Grocery.txt","a");
	printf("Enter Product Name: ");
	scanf("%s",grocery.product);
	getchar();
	
	printf("Write 'C' for cleaning product\n");
	printf("Write 'P' for pharmacy\n");
	printf("Write 'O' for other\n");
	printf("Enter Product Category: ");
	scanf("%c",&grocery.Category);
	getchar();
	
	printf("Enter Price: ");
	scanf("%d",&grocery.price);
	getchar();
	
	printf("Aisle: ");
	scanf("%s",grocery.aisle);
	getchar();
	
	fprintf(fptr,"%s;%c;%d;%s;\n",grocery.product,grocery.Category,grocery.price,grocery.aisle);
	system("cls");
	
	printf("=============The Data You've just Added======================\n");
	printf("\nProduct Name: %s\n",grocery.product);
	printf("Category: %c\n",grocery.Category);
	printf("Price: %d cents\n",grocery.price);
	printf("Aisle: %s\n",grocery.aisle);
	fclose(fptr);
}
int main(){
	int menu;
	do{
	printf("Product Type\n");
	printf("1. Meats\n");
	printf("2. Produce\n");
	printf("3. Dairy\n");
	printf("4. Canned Goods\n");
	printf("5. NonFoods\n");
	printf("6. Exit Program\n");
	printf("\nSelect Product: ");
	scanf("%d",&menu);
	switch(menu){
		case 1:
			system("cls");
			MeatCreate();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			ProduceCreate();
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			DairyCreate();
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			CannedGoodsCreate();
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			NonFoodsCreate();
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			printf("-----------------Program Closed-----------------\n");
			break;
		}
	}while(menu!=6);	
}

