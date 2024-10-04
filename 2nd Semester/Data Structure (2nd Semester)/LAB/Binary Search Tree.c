#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node{
	int CustomerPoint;
	int Key;
	char CustomerPhoneNumber[14];
	char CustomerName[27];
	char CustomerEmail[30];
	struct node *right;
	struct node *left;
};
struct node *root=NULL;
struct node *Insert(struct node *root,char *CustomerNameInput,char *PhoneNumberInput,char *EmailInput,int Point, int KeyInput){
	if(root==NULL){
		struct node *newnode=(struct node*)malloc(sizeof(struct node));
		newnode->Key=KeyInput;
		strcpy(newnode->CustomerName,CustomerNameInput);
		strcpy(newnode->CustomerPhoneNumber,PhoneNumberInput);
		strcpy(newnode->CustomerEmail,EmailInput);
		
		newnode->CustomerPoint=Point;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	}else if(KeyInput < root->Key){
		root->left=Insert(root->left,CustomerNameInput,PhoneNumberInput,EmailInput,Point,KeyInput);
	}else if(KeyInput > root->Key){
		root->right=Insert(root->right,CustomerNameInput,PhoneNumberInput,EmailInput,Point,KeyInput);
	}
}

void PrintInOrder(struct node *root){
	if(root==NULL){
		return;
	}
	PrintInOrder(root->left);
	printf("%-20s\t\t %-20s\t\t %-20s\t\t %d\n",root->CustomerName,root->CustomerPhoneNumber,root->CustomerEmail,root->CustomerPoint);
	PrintInOrder(root->right);
}

void ViewAll(struct node *root){
	printf("Name\t\t\t Phone Number\t\t\t Email\t\t\t Points\n");
	printf("------------------------------------------------------------------------------------\n");
	PrintInOrder(root);
	printf("------------------------------------------------------------------------------------\n");
}
struct node *MinValueNode(struct node *root){
	struct node *current = root;
	
	while(current->left!=NULL){
		current=current->left;
	}
	return current;
}


struct node *DeleteNode(struct node *root,int input){
	if(root==NULL){
		return root;
	}else if(input < root->Key){
		root->left=DeleteNode(root->left,input);
	}else if(input > root->Key){
		root->right=DeleteNode(root->right,input);
	}else{
		if(root->right==NULL){
			struct node *temp = root->left;
			free(root);
			return temp;
		}else if(root->left==NULL){
			struct node *temp = root->right;
			free(root);
			return temp;
		}else{
			struct node *temp = MinValueNode(root->right);
			root->Key=temp->Key;
			root->right=DeleteNode(root->right,temp->Key);
		}	
	}	
}

void ProcessOrder(struct node *root){
	char NameInput[27],PhoneNumber[14],Email[30],Drinks[30];
	
	printf("Input phone number[10-13][numeric]: ");
	fflush(stdin);
	scanf("%s",PhoneNumber);
	getchar();
	
	int length = strlen(PhoneNumber);
	
	int RandomCharacterFound=0;
	
	for(int i=0;i<length;i++){
		if(isdigit(PhoneNumber[i])==0){
			RandomCharacterFound=1;
			break;
		}
	}
	
	while(length <10 || length >13 || RandomCharacterFound==1){
		printf("Input phone number[10-13][numeric]: ");
		fflush(stdin);
		scanf("%s",PhoneNumber);
		getchar();
		
		RandomCharacterFound=0;
		length = strlen(PhoneNumber);
		for(int i=0;i<length;i++){
			if(isdigit(PhoneNumber[i])==0){
				RandomCharacterFound=1;
				break;
			}
		}
	}
	
	int SumOfASCII=0;
	for(int i=0;i<length;i++){
		SumOfASCII+=PhoneNumber[i];
	}
	
	printf("Input name[5-25][Mr. ][Mrs. ]: ");
	fflush(stdin);
	scanf("%[^\n]",NameInput);
	getchar();
	
	length = strlen(NameInput);
	
	char Mr[] = "Mr. ";
	char Mrs[] = "Mrs. ";
	
	char *CheckMr = strstr(NameInput,Mr);
	char *CheckMrs = strstr(NameInput, Mrs);
	
	while(length < 5 || length > 25 || (CheckMr == NULL && CheckMrs==NULL)||NameInput[0]!='M'){
			
		printf("Input name[5-25][Mr. ][Mrs. ]: ");
		fflush(stdin);
		scanf("%[^\n]",NameInput);
		getchar();
		
		length = strlen(NameInput);
		CheckMr = strstr(NameInput,Mr);
		CheckMrs = strstr(NameInput, Mrs);		
	}
	
	printf("Input email[10-20][email format]: ");
	fflush(stdin);
	scanf("%[^\n]",Email);
	getchar();
	
	length = strlen(Email);
	int CheckAddChar=0;
	for(int i=0;i<length;i++){
		if(Email[i]=='@'){
			CheckAddChar=1;
			break;
		}
	}
	
	char com[] = ".com";
	char co_id[] = ".co.id";
	
	char *Check_com = strstr(Email,com);
	char *Check_co_id = strstr(Email, co_id);

	while(CheckAddChar==0 || length<10 || length>20 || (Check_com==NULL && Check_co_id==NULL)||Email[length-1]!='m'&&Email[length-1]!='d'){
		printf("Input email[10-20][email format]: ");
		fflush(stdin);
		scanf("%[^\n]",Email);
		getchar();
		
		length = strlen(Email);
		Check_com = strstr(Email,com);
		Check_co_id = strstr(Email, co_id);
		CheckAddChar=0;
		for(int i=0;i<length;i++){
			if(Email[i]=='@'){
				CheckAddChar=1;
				break;
			}
		}	
	}
	
	printf("\n\nInsert success!\n");
	
	int CafeLatte=0,CaramelMacchiato=0,Cappuccino=0,CafeMocha=0;
	while(1){
		printf("Input drink [Cafe Latte|Caramel Macchiato|Cappuccino|Cafe Mocha]: ");
		fflush(stdin);
		scanf("%[^\n]",Drinks);
		getchar();
		
		while(strcmp(Drinks,"Cafe Latte")!=0 && strcmp(Drinks,"Caramel Macchiato")!=0 && strcmp(Drinks,"Cappuccino")!=0 &&
		strcmp(Drinks,"Cafe Mocha")!=0){
			printf("Input drink [Cafe Latte|Caramel Macchiato|Cappuccino|Cafe Mocha]: ");
			fflush(stdin);
			scanf("%[^\n]",Drinks);
			getchar();
		}
		
		int quantity;
		if(strcmp(Drinks,"Cafe Latte")==0){
			printf("Input drink quantity: ");
			scanf("%d",&quantity);
			CafeLatte+=quantity;
		}else if(strcmp(Drinks,"Caramel Macchiato")==0){
			printf("Input drink quantity: ");
			scanf("%d",&quantity);
			CaramelMacchiato+=quantity;
		}else if(strcmp(Drinks,"Cappuccino")==0){
			printf("Input drink quantity: ");
			scanf("%d",&quantity);
			Cappuccino+=quantity;
		}else{
			printf("Input drink quantity: ");
			scanf("%d",&quantity);
			CafeMocha+=quantity;
		}
		
		printf("Do you want to order more?[y|n]: ");
		char option;
		fflush(stdin);
		scanf("%c",&option);
		getchar();
		
		while(option!= 'y' && option !='n'){
			printf("Do you want to order more?[y|n]: ");
			fflush(stdin);
			scanf("%c",&option);
			getchar();
			}
			
		if(option == 'n'){
			break;
		}
	}
	
	int Point;
	float totalprice=0;
	printf("Order summary:\n");
	if(CafeLatte!=0){
		totalprice =CafeLatte*30000;
		printf("Cafe Latte = %dx = %.0f\n",CafeLatte,totalprice);
	}
	if(CaramelMacchiato!=0){
		printf("Caramel Macchiato = %dx = %d\n",CaramelMacchiato,CaramelMacchiato * 30000);
		totalprice+=CaramelMacchiato * 30000;
	}
	if(Cappuccino!=0){
		printf("Cappucino = %dx = %d\n",Cappuccino,Cappuccino * 30000);
		totalprice+=Cappuccino * 30000;
	}
	if(CafeMocha!=0){
		printf("Cafe Mocha = %dx = %d\n",CafeMocha,CafeMocha * 30000);
		totalprice+=CafeMocha * 30000;
	}
	
	printf("total = %.0f\n",totalprice);
	
	if(totalprice>50000){
		Point = totalprice / 50000;
	}
	
	printf("Points Obtained: %d\n",Point);
	
	root = Insert(root,NameInput,PhoneNumber,Email,Point,SumOfASCII);
	
}


int main(){
	struct node *root=NULL;
	int menu;
	do{
		printf("BlueBucks\n");
		printf("===================\n");
		printf("1. Process Order\n");
		printf("2. View All Customer\n");
		printf("3. Remove Customer\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d",&menu);
		
		switch(menu){
			case 1:
				system("cls");
				ProcessOrder(root);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				ViewAll(root);
				system("pause");
				system("cls");
				break;
		}	
	}while(menu!=4);
	
	
}
