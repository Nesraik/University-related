#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node{
	int CustomerPoint;
	long long int Key;
	char CustomerPhoneNumber[14];
	char CustomerName[27];
	char CustomerEmail[30];
	struct node *right;
	struct node *left;
};

struct node *Insert(struct node *root,char *CustomerNameInput,char *PhoneNumberInput,char *EmailInput,int Point, long long int KeyInput){
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
	printf("|%-20s\t |%-20s\t |%-20s\t |%d\t\t|\n",root->CustomerName,root->CustomerPhoneNumber,root->CustomerEmail,root->CustomerPoint);
	printf("-----------------------------------------------------------------------------------------\n");
	PrintInOrder(root->right);
}

struct node *Search(struct node *root,long long int Input){
	if(root==NULL){
		return root;
	}
	
	if(Input == root->Key){
		return root;
	}else if(Input > root->Key){
		return Search(root->right,Input);
	}else{
		return Search(root->left,Input);
	}
}

void ViewAll(struct node *root){
	if(root==NULL){
		printf("There is no data !\n\n");
		return;
	}
	printf("-----------------------------------------------------------------------------------------\n");
	printf("|Name\t\t\t |Phone Number\t\t |Email\t\t\t |Points\t|\n");
	printf("-----------------------------------------------------------------------------------------\n");
	PrintInOrder(root);
}
struct node *MinValueNode(struct node *root){
	struct node *current = root;
	
	while(current->left!=NULL){
		current=current->left;
	}
	return current;
}


struct node *DeleteNode(struct node *root,long long int input){
	if(root==NULL){
		printf("Data Invalid !\n");
		return root;
	}else if(input < root->Key){
		root->left=DeleteNode(root->left,input);
	}else if(input > root->Key){
		root->right=DeleteNode(root->right,input);
	}else{
		printf("Delete Success !\n\n");
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

void ProcessOrder(struct node **root){
	char NameInput[27],PhoneNumber[14],Email[30],Drinks[30],option;
	int Point=0,length,RandomCharacterFound,CanGetBonus=0;
	int FreeCafeLatte=0,FreeCaramelMacchiato=0,FreeCappuccino=0,FreeCafeMocha=0;
	int PointUsed,quantity;
	
	char PhoneKeyString[16]="1";
	do{
		printf("Input phone number[10-13][numeric]: ");
		fflush(stdin);
		scanf("%s",PhoneNumber);
		getchar();
		
		strcat(PhoneKeyString,PhoneNumber);
		RandomCharacterFound=0;
		length = strlen(PhoneNumber);
		for(int i=0;i<length;i++){
			if(isdigit(PhoneNumber[i])==0){
				RandomCharacterFound=1;
				break;
			}
		}
	}while(length <10 || length >13 || RandomCharacterFound==1);
	
	long long int PhoneKey=atoll(PhoneKeyString);
	
	struct node *Data;
	Data= Search((*root),(PhoneKey));
	
	if(Data==NULL){
		
		char Mr[] = "Mr. ";
		char Mrs[] = "Mrs. ";
		char *CheckMr,*CheckMrs;
		
		do{		
			printf("Input name[5-25][Mr. ][Mrs. ]: ");
			fflush(stdin);
			scanf("%[^\n]",NameInput);
			getchar();
			
			length = strlen(NameInput);
			CheckMr = strstr(NameInput,Mr);
			CheckMrs = strstr(NameInput, Mrs);		
		}while(length < 5 || length > 25 || (CheckMr == NULL && CheckMrs==NULL)||NameInput[0]!='M');
		
		int CheckAddChar;
		
		char com[] = ".com";
		char co_id[] = ".co.id";
		char *Check_com,*Check_co_id;
		
		do{
			printf("Input email[10-20][email format]: ");
			fflush(stdin);
			scanf("%[^\n]",Email);
			getchar();
			
			length = strlen(Email);
			char *Check_com = strstr(Email,com);
			char *Check_co_id = strstr(Email, co_id);
			CheckAddChar=0;
			for(int i=0;i<length;i++){
				if(Email[i]=='@'){
					CheckAddChar++;
				}
			}	
		}while(CheckAddChar!=1 || length<10 || length>20 || (Check_com==NULL && Check_co_id==NULL)||Email[length-1]!='m'&&Email[length-1]!='d');
		printf("\n\nInsert success!\n");
		printf("\nYou have 0 free drink(s) left\n");
		
	}
	else{
		if(Data->CustomerPoint>25){
			printf("\nDo you want to use your points?[You have %d points][y|n]: ",Data->CustomerPoint);
			scanf("%c",&option);
			getchar();
			
			if(option=='y'){
				int FreeDrinks,FreeDrinksCount;
				CanGetBonus=1;
				
				do{
					printf("How much[%d left]: ",Data->CustomerPoint);
					scanf("%d",&PointUsed);
				}while(PointUsed % 25 !=0 || PointUsed > Data->CustomerPoint || PointUsed == 0);
				
				FreeDrinks = PointUsed / 25;
				printf("You have %d free drink(s) left\n",FreeDrinks);
				
				while(1){
					do{
						printf("\nInput drink [Cafe Latte|Caramel Macchiato|Cappuccino|Cafe Mocha]: ");
						fflush(stdin);
						scanf("%[^\n]",Drinks);
						getchar();
						
					}while(strcmp(Drinks,"Cafe Latte")!=0 && strcmp(Drinks,"Caramel Macchiato")!=0 && strcmp(Drinks,"Cappuccino")!=0
						&& strcmp(Drinks,"Cafe Mocha")!=0);
						
					if(strcmp(Drinks,"Cafe Latte")==0){
						do{
							printf("Input drink quantity[>=1]: ");
							scanf("%d",&quantity);
							FreeCafeLatte+=quantity;
						}while(quantity>FreeDrinks || quantity < 1);
					}else if(strcmp(Drinks,"Caramel Macchiato")==0){
						do{
							printf("Input drink quantity[>=1]: ");
							scanf("%d",&quantity);
						}while(quantity>FreeDrinks || quantity < 1);
						FreeCaramelMacchiato+=quantity;
					}else if(strcmp(Drinks,"Cappuccino")==0){
						do{
							printf("Input drink quantity[>=1]: ");
							scanf("%d",&quantity);
						}while(quantity>FreeDrinks || quantity < 1);
						FreeCappuccino+=quantity;
					}else{
						do{
							printf("Input drink quantity[>=1]: ");
							scanf("%d",&quantity);
						}while(quantity>FreeDrinks || quantity < 1);
						FreeCafeMocha+=quantity;	
					}
					FreeDrinks = FreeDrinks - quantity;
					if(FreeDrinks==0){
						printf("\nYou have %d free drink(s) left\n",FreeDrinks);
						break;
					}else{
						printf("\nYou have %d free drink(s) left\n",FreeDrinks);
					}
				}
			}
		}
	}
	
	int CafeLatte=0,CaramelMacchiato=0,Cappuccino=0,CafeMocha=0;
	while(1){
		do{
			printf("\nInput drink [Cafe Latte|Caramel Macchiato|Cappuccino|Cafe Mocha]: ");
			fflush(stdin);
			scanf("%[^\n]",Drinks);
			getchar();
		}while(strcmp(Drinks,"Cafe Latte")!=0 && strcmp(Drinks,"Caramel Macchiato")!=0 && strcmp(Drinks,"Cappuccino")!=0
		&& strcmp(Drinks,"Cafe Mocha")!=0);
		
		int quantity;
		if(strcmp(Drinks,"Cafe Latte")==0){
			do{
				printf("Input drink quantity[>=1]: ");;
				scanf("%d",&quantity);
			}while(quantity<1);
			CafeLatte+=quantity;
		}else if(strcmp(Drinks,"Caramel Macchiato")==0){
			do{
				printf("Input drink quantity[>=1]: ");;
				scanf("%d",&quantity);
			}while(quantity<1);
			CaramelMacchiato+=quantity;
		}else if(strcmp(Drinks,"Cappuccino")==0){
			do{
				printf("Input drink quantity[>=1]: ");;
				scanf("%d",&quantity);
			}while(quantity<1);
			Cappuccino+=quantity;
		}else{
			do{
				printf("Input drink quantity[>=1]: ");;
				scanf("%d",&quantity);
			}while(quantity<1);
			CafeMocha+=quantity;
		}
		do{
			printf("Do you want to order more?[y|n]: ");
			fflush(stdin);
			scanf("%c",&option);
			getchar();
		}while(option!= 'y' && option !='n');
			
		if(option == 'n'){
			break;
		}
	}
	
	float totalprice=0;
	printf("Order summary:\n");
	if(CanGetBonus==1){
		if(FreeCafeLatte!=0){
			printf("Cafe Latte - %dx = Free\n",FreeCafeLatte);
		}else if(FreeCaramelMacchiato!=0){
			printf("Caramel Macchiato - %dx = Free\n",FreeCaramelMacchiato);
		}else if(FreeCappuccino!=0){
			printf("Cappuccino - %dx = Free\n",FreeCappuccino);
		}else{
			printf("Cafe Mocha - %dx = Free\n",FreeCafeMocha);
		}
	}
	
	if(CafeLatte!=0){
		totalprice =CafeLatte*30000;
		printf("Cafe Latte - %dx = %.0f\n",CafeLatte,totalprice);
	}
	if(CaramelMacchiato!=0){
		printf("Caramel Macchiato - %dx = %d\n",CaramelMacchiato,CaramelMacchiato * 30000);
		totalprice+=CaramelMacchiato * 30000;
	}
	if(Cappuccino!=0){
		printf("Cappucino - %dx = %d\n",Cappuccino,Cappuccino * 30000);
		totalprice+=Cappuccino * 30000;
	}
	if(CafeMocha!=0){
		printf("Cafe Mocha - %dx = %d\n",CafeMocha,CafeMocha * 30000);
		totalprice+=CafeMocha * 30000;
	}
	
	printf("Total: %.0f\n",totalprice);
	
	if(totalprice>50000){
		Point = totalprice / 50000;
		Point = 3 * Point;
	}
	
	printf("Points Obtained: %d\n",Point);
	
	if(Data==NULL){
		(*root) = Insert((*root),NameInput,PhoneNumber,Email,Point+10,PhoneKey);	
	}else{
		Data->CustomerPoint=Data->CustomerPoint-PointUsed;
		Data->CustomerPoint=Data->CustomerPoint+Point;
	}
	
}

struct node *RemoveCustomer(struct node **root){
	
	if((*root)==NULL){
		printf("There is no data!\n\n");
		return 0;
	}
	
	char PhoneNumberInput[15];
	ViewAll(*root);
	printf("Input Phone Number: ");
	fflush(stdin);
	scanf("%s",PhoneNumberInput);
	getchar();
	
	
	char PhoneKeyString[16]="1";
	
	strcat(PhoneKeyString,PhoneNumberInput);
	long long int PhoneKey = atoll(PhoneKeyString);
	
	(*root)= DeleteNode((*root),PhoneKey);
	
	return (*root);
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
				ProcessOrder(&root);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				ViewAll(root);
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				RemoveCustomer(&root);
				system("pause");
				system("cls");
				break;
		}	
	}while(menu!=4);
	
	
}
