#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define Size 100

struct Hash{
	struct Hash *next;
	char Application[30];
	char PasswordApplication[30];
	char UsernameApp[30];
};
struct node{
	int NodeHeight;
	char Username[30];
	char Password[30];
	struct node *left;
	struct node *right;
	//Nambah didalam ini diganti ama nama structnya
	struct Hash *HashTable[Size];
	char SecurityAnswer[30];
	char SecurityQuestion[300];
	int key;
};


char UsernameCurrent[30];
int HashKey;

int Height(struct node *NodeInput){
	if(NodeInput==NULL){
		return 0;
	}else{
		return NodeInput->NodeHeight;
	}
}

int Max(int num1,int num2){
	if(num1>num2){
		return num1;
	}else{
		return num2;
	}
}

int CheckBalance(struct node *NodeInput){
	if(NodeInput==NULL){
		return 0;
	}else{
		return Height(NodeInput->left)-Height(NodeInput->right);
	}
}

struct node *RightRotate(struct node *OldCurrent){
	
	struct node *NewCurrent = OldCurrent->left;
	struct node *RightNewCurrent=NewCurrent->right;
	
	NewCurrent->right=OldCurrent;
	OldCurrent->left=RightNewCurrent;
	
	OldCurrent->NodeHeight=1 + Max(Height(OldCurrent->left),Height(OldCurrent->right));
	NewCurrent->NodeHeight=1 + Max(Height(NewCurrent->left),Height(NewCurrent->right));
	
	return NewCurrent;
}

struct node *LeftRotate(struct node *OldCurrent){
	
	struct node *NewCurrent=OldCurrent->right;
	struct node *LeftNewCurrent = NewCurrent->left;
	
	NewCurrent->left=OldCurrent;
	OldCurrent->right=LeftNewCurrent;
	
	OldCurrent->NodeHeight= 1 + Max(Height(OldCurrent->left),Height(OldCurrent->right));
	NewCurrent->NodeHeight= 1 + Max(Height(NewCurrent->left),Height(NewCurrent->right));
	
	return NewCurrent;
}

struct node *MinVal (struct node *root){
	
	struct node *Current = root;
	
	while(Current->left!=NULL){
		Current=Current->left;
	}
	return Current;
}

struct node *insert(struct node *root,char *UsernameInput, char *PasswordInput,int keyInput, char *SecurityQuestionIn, char *AnswerIn){
	if(root==NULL){
		struct node *Newnode = (struct node*)malloc(sizeof(struct node));
		strcpy(Newnode->Username,UsernameInput);
		strcpy(Newnode->Password,PasswordInput);
		strcpy(Newnode->SecurityQuestion,SecurityQuestionIn);
		strcpy(Newnode->SecurityAnswer,AnswerIn);

		Newnode->key=keyInput;;
		Newnode->NodeHeight=1;
		Newnode->right=NULL;
		Newnode->left=NULL;
		return Newnode;
	}
	
	if(keyInput<root->key){
		root->left=insert(root->left,UsernameInput,PasswordInput,keyInput,SecurityQuestionIn,AnswerIn);
	}else if(keyInput>root->key){
		root->right=insert(root->left,UsernameInput,PasswordInput,keyInput,SecurityQuestionIn,AnswerIn);
	}
	
	root->NodeHeight= 1 + Max(Height(root->left),Height(root->right));
	
	int BalanceFactor = CheckBalance(root);
	
	
	if(BalanceFactor>1 && keyInput<root->left->NodeHeight){
		return RightRotate(root);
	}
	
	if(BalanceFactor>1 && keyInput>root->left->NodeHeight){
		root->left=LeftRotate(root->left);
		return RightRotate(root);
	}
	
	if(BalanceFactor<-1 && keyInput>root->right->NodeHeight){
		return LeftRotate(root);
	}
	
	if(BalanceFactor<-1 && keyInput<root->right->NodeHeight){
		root->right=RightRotate(root->right);
		return LeftRotate(root);
	}
	
	return root;
	
}

struct node *DeleteNode(struct node *root, int key){
	
	if(root==NULL){
		return root;
	}
	
	if(key<root->key){
		root->left=DeleteNode(root->left,key);
	}else if(key>root->key){
		root->right=DeleteNode(root->right,key);
	}else{
		if(root->left==NULL){
			struct node *temp = root->right;
			free(root);
			return temp;
		}else if(root->right==NULL){
			struct node *temp = root->left;
			free(root);
			return temp;
		}else{
			struct node *temp = MinVal(root->right);
			root->key=temp->key;
			root->right=DeleteNode(root->right,temp->key);
		}	
	}
	
	root->NodeHeight= 1 + Max(Height(root->left),Height(root->right));
	
	int BalanceFactor = CheckBalance(root);
	
	
	if(BalanceFactor>1 && CheckBalance(root->left)>=0){
		return RightRotate(root);
	}
	if(BalanceFactor>1 && CheckBalance(root->right)<0){
		root->left=LeftRotate(root->left);
		return RightRotate(root);
	}
	if(BalanceFactor<-1 && CheckBalance(root->right)<=0){
		return LeftRotate(root);
	}
	if(BalanceFactor<-1 && CheckBalance(root->left)>0){
		root->right=RightRotate(root->right);
		return LeftRotate(root);
	}
	
	return root;
	
}



struct node *Search(struct node *root,int KeyString){
	if(root==NULL){
		return root;
	}
	if(KeyString==root->key){
		return root;
	}else if(KeyString<root->key){
		return Search(root->left,KeyString);
	}else if(KeyString>root->key){
		return Search(root->right,KeyString);
	}
	
}

void CreateAccount(struct node **root){
	
	char Usernametest[30],Passwordtest[30];
	int length,UsernameSum;
	struct node *Data;
	do{
		printf("Username[5-30]: ");
		scanf("%s",Usernametest);
		getchar();
		length = strlen(Usernametest);
		
		UsernameSum=0;
		for(int i=0;i<length;i++){
			UsernameSum+=Usernametest[i];
		}
		Data = Search((*root),UsernameSum);
		if(Data!=NULL){
			printf("Username is taken\n");
		}
	}while(Data!=NULL || length < 5 || length >30);	
		
	do{
		printf("Password[5-30]: ");
		scanf("%s",Passwordtest);
		getchar();
		length = strlen(Passwordtest);
	}while(length<5 || length>30);
	
	char SecurityQuestion[300],Answer[30];
	
	int menu;
	printf("\n<<Choose one of security question below>>\n");
	printf("1. What is the middle name of your youngest child?\n");
	printf("2. What was the name of your first stuffed animal?\n");
	printf("3. In what city or town did your mother and father meet?\n");		
	printf("4. What was the first exam you failed?\n");
	printf(">> ");
	scanf("%d",&menu);
	switch(menu){
		case 1:
			system("cls");
			printf("1. What is the middle name of your youngest child?\n");
			strcpy(SecurityQuestion,"What is the middle name of your youngest child?");
			printf("Answer: ");
			fflush(stdin);
			scanf("%[^\n]",Answer);
			getchar();
			break;	
		case 2:
			system("cls");
			printf("2. What was the name of your first stuffed animal?\n");
			strcpy(SecurityQuestion,"What was the name of your first stuffed animal?");
			printf("Answer: ");
			fflush(stdin);
			scanf("%[^\n]",Answer);
			getchar();
			break;
		case 3:
			system("cls");
			printf("3. In what city or town did your mother and father meet?\n");		
			strcpy(SecurityQuestion,"In what city or town did your mother and father meet?");
			printf("Answer: ");
			fflush(stdin);
			scanf("%[^\n]",Answer);
			getchar();
			break;
		case 4:
			system("cls");
			printf("4. What was the first exam you failed?\n");
			strcpy(SecurityQuestion,"What was the first exam you failed?");
			printf("Answer: ");
			fflush(stdin);
			scanf("%[^\n]",Answer);
			getchar();
			break;
	}
	
	length = strlen(Answer);
	for(int i=0;i<length;i++){
		if(Answer[i]<'a'){
			Answer[i]= Answer[i]+32;
		}
	}
	*root = insert((*root),Usernametest,Passwordtest,UsernameSum,SecurityQuestion,Answer);
	printf("\n<<Account Created>>\n");
}







void ChangePass(struct node *root){
	
	int length,Sum=0;
	
	length = strlen(UsernameCurrent);
	for(int i=0;i<length;i++){
		Sum+=UsernameCurrent[i];
	}
	struct node *Data = Search(root,Sum);
	
	char Passwordtest[30];
	do{
		printf("Password[5-30]: ");
		scanf("%s",Passwordtest);
		getchar();
		length = strlen(Passwordtest);
	}while(length<5 || length>30);
	
	strcpy(Data->Password,Passwordtest);
	printf("<<Password Changed!!>>\n\n");
	
}

void DeleteAccount(struct node **root){
	
	int length;
	
	char UsernameCheck[30],PasswordCheck[30];
	
	printf("Username: ");
	scanf("%s",UsernameCheck);
	getchar();
	
	length=strlen(UsernameCheck);
	int UsernameSum=0;
	
	for(int i=0;i<length;i++){
		UsernameSum+=UsernameCheck[i];
	}
	
	struct node *Data = Search(*root,UsernameSum);
	
	if(Data==NULL){
		printf("Account Doesnot Exist\n");
		return;
	}else{
		char PasswordCheck[30];
		printf("Password: ");
		scanf("%s",PasswordCheck);
		if(strcmp(PasswordCheck,Data->Password)!=0){
			printf("Invalid Password\n");
		}else{
			int menu;
			printf("Are you sure you want to delete your current account?\n");
			printf("1. Yes\n");
			printf("2. No\n");
			printf(">> ");
			scanf("%d",&menu);
			switch(menu){
				case 1:
					
					(*root) = DeleteNode((*root),UsernameSum);
					printf("Delete Success\n");
					break;
				case 2:
					printf("Going back to menu\n");
					break;
			}
		}
		
	}
	
}

//Narok main buat password disini
void BeforeMain(struct node **root){
	int menu;
	
	do{
		printf("Hi <<%s>>\n\n",UsernameCurrent);
		printf("1.Continue to Main Menu\n");
		printf("2.Change Password Account\n");
		printf("3.Logout\n");
		printf(">> ");
		scanf("%d",&menu);
		
		switch(menu){
			case 1:
				system("cls");
				MainMenu(root);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				ChangePass(*root);
				system("pause");
				system("cls");
				break;
		}
		
	}while(menu!=3);
	return;
}


void LoginAccount(struct node *root){
	
	char UsernameCheck[30],PasswordCheck[30];
	
	printf("Username: ");
	scanf("%s",UsernameCheck);
	getchar();
	
	int length=strlen(UsernameCheck);
	int UsernameSum=0;
	
	for(int i=0;i<length;i++){
		UsernameSum+=UsernameCheck[i];
	}
	
	struct node *Data = Search(root,UsernameSum);
	
	if(Data==NULL){
		printf("Account Doesnot Exist\n");
		return;
	}else{
		strcpy(UsernameCurrent,UsernameCheck);
		int limit=3,limit2=3;
		do{
			printf("Password: ");
			scanf("%s",PasswordCheck);
			getchar();
			if(strcmp(PasswordCheck,Data->Password)!=0){
				limit--;
				printf("Invalid Password\n");
			}else{
				break;
			}
		}while(limit>0);
		if(limit==0){
			system("cls");
			int menu,length2;
			char AnswerCheck[30],NewPassword[30];
			printf("Forgot Password?\n");
			printf("1. Yes\n");
			printf("2. No\n");
			printf(">> ");
			scanf("%d",&menu);
			
			switch(menu){
				case 1:
					do{
						system("cls");
						printf("<<Answer this question>>[Remaining Attempt: %d]\n",limit2);
						printf("%s\n",Data->SecurityQuestion);
						printf(">> ");
						scanf("%s",AnswerCheck);
						
						length2 = strlen(AnswerCheck);
						
						for(int i=0;i<length2;i++){
							if(AnswerCheck[i]<'a'){
								AnswerCheck[i]= AnswerCheck[i]+32;
							}
						}
						
						if(strcmp(Data->SecurityAnswer,AnswerCheck)!=0){
							limit2--;
							continue;
						}else{
							printf("Enter a new Password\n");
							scanf("%s",NewPassword);
							strcpy(Data->Password,NewPassword);
							getchar();
							return;
						}
					}while(limit2>0);
					system("cls");
					printf("<<Attempt limit is reached>>\n");
					printf("<<Your account is now blocked>>\n");
					printf("<<Please contact our customer service>>\n");
					printf("CS (Davin): 082233445566\n");
					return;
				case 2:
					return;
			}
		}
		
	}
	system("cls");
	printf("<<Login Success>>\n\n");
	for(int i=0; i<Size;i++){
		Data->HashTable[i]=NULL;
	}
	system("pause");
	system("cls");
	BeforeMain(&root);
	
	
}

int main(){
	struct node *root=NULL;
	int menu;
	do{
		printf("<<Password Manager>>\n\n");
		printf("<<Menu>>\n");
		printf("1. Create Account\n");
		printf("2. Login\n");
		printf("3. Display Account(testing)\n");
		printf("4. Delete Account\n");
		printf("5. Exit\n");
		printf(">> ");
		scanf("%d",&menu);
		
		switch(menu){
			
			case 1:
				system("cls");
				CreateAccount(&root);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				LoginAccount(root);
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				PrintAccount(root);
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				DeleteAccount(&root);
				system("pause");
				system("cls");
				break;
			
		}
	}while(menu!=5);
}

