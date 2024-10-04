#include"Menus.c"

struct node{
	int NodeHeight;
	char Username[30];
	char Password[30];
	struct node *left;
	struct node *right;
	//Nambah didalam ini diganti ama nama structnya
	struct treeNode *root[10];
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
		
		int i;
		for(i=0;i<10;i++) Newnode->root[i] = NULL;

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
	
	int i;
	for(i=0;i<10;i++) root->root[i] = NULL;

	int BalanceFactor = CheckBalance(root);
	
	
	if(BalanceFactor>1 && keyInput<root->left->key){
		return RightRotate(root);
	}
	
	if(BalanceFactor>1 && keyInput>root->left->key){
		root->left=LeftRotate(root->left);
		return RightRotate(root);
	}
	
	if(BalanceFactor<-1 && keyInput>root->right->key){
		return LeftRotate(root);
	}
	
	if(BalanceFactor<-1 && keyInput<root->right->key){
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
	if(BalanceFactor>1 && CheckBalance(root->left)<0){
		root->left=LeftRotate(root->left);
		return RightRotate(root);
	}
	if(BalanceFactor<-1 && CheckBalance(root->right)<=0){
		return LeftRotate(root);
	}
	if(BalanceFactor<-1 && CheckBalance(root->right)>0){
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
	else return NULL;
}

void CreateAccount(struct node **root){
	
	char Usernametest[30],Passwordtest[30];
	int length,UsernameSum;
	struct node *Data;

	printf("<<Create Account>>\n\n");
	do{
		printf("Username[5-30 chars]: ");
		scanf("%s",Usernametest);
		getchar();
		fflush(stdin);
		length = strlen(Usernametest);
		
		UsernameSum=0;
		for(int i=0;i<length;i++){
			if(i<2){
				UsernameSum+=Usernametest[i]%10;
			}else{
				UsernameSum+=Usernametest[i];
			}
		}
		Data = Search((*root),UsernameSum);
		if(Data!=NULL){
			printf("Username is taken\n");
		}
	}while(Data!=NULL || length < 5 || length >30);	
		
	do{
		printf("Password[5-30 chars]: ");
		scanf("%s",Passwordtest);
		getchar();
		fflush(stdin);
		length = strlen(Passwordtest);
	}while(length<5 || length>30);
	
	char SecurityQuestion[300],Answer[30];
	
	int menu;
	do{
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
				break;	
			case 2:
				system("cls");
				printf("2. What was the name of your first stuffed animal?\n");
				strcpy(SecurityQuestion,"What was the name of your first stuffed animal?");
				break;
			case 3:
				system("cls");
				printf("3. In what city or town did your mother and father meet?\n");		
				strcpy(SecurityQuestion,"In what city or town did your mother and father meet?");
				break;
			case 4:
				system("cls");
				printf("4. What was the first exam you failed?\n");
				strcpy(SecurityQuestion,"What was the first exam you failed?");
				break;
		}
	}while(menu<1 || menu > 4);
	
	printf("Answer: ");
	fflush(stdin);
	scanf("%[^\n]",Answer);
	getchar();
	
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
	
	printf("<<Change Password>>\n\n");
	length = strlen(UsernameCurrent);
	for(int i=0;i<length;i++){
		if(i<2){
			Sum+=UsernameCurrent[i]%10;
		}else{
			Sum+=UsernameCurrent[i];
		}
	}
	struct node *Data = Search(root,Sum);
	
	char Passwordtest[30];
	do{
		printf("New Password[5-30 chars]: ");
		scanf("%s",Passwordtest);
		getchar();
		fflush(stdin);
		length = strlen(Passwordtest);
	}while(length<5 || length>30);
	
	strcpy(Data->Password,Passwordtest);
	printf("<<Password Changed!!>>\n\n");
	
}

void DeleteAccount(struct node **root){
	
	int length;
	
	char UsernameCheck[30];
	
	printf("<<Delete Account>>\n\n");
	printf("Username: ");
	scanf("%s",UsernameCheck);
	getchar();
	fflush(stdin);
	
	length=strlen(UsernameCheck);
	int UsernameSum=0;
	
	for(int i=0;i<length;i++){
		if(i<2){
			UsernameSum+=UsernameCheck[i]%10;
		}else{
			UsernameSum+=UsernameCheck[i];
		}
	}
	
	struct node *Data = Search(*root,UsernameSum);
	
	if(Data==NULL){
		printf("Account Doesnot Exist\n");
		return;
	}else{
		char PasswordCheck[30];
		printf("Password: ");
		scanf("%s",PasswordCheck);
		fflush(stdin);
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

void mainMenu(struct node *node){
    char temp = 'a';
	int i;
	strcpy(session.name, node->Username);
	for(i = 0; i < 10; i++){
		session.hashRoot[i] = node->root[i];
	}
    while(temp != '0'){
        printf("----------------------------\n Hello, %s\n----------------------------\n", session.name);
        printf("0. Log Out\n1. Change my Password Manager password\n2. Add New\n3. View\n4. Delete\n"); 
        temp = getch();
        switch(temp){
            case '0':{
				system("cls");
				for(i=0;i<10;i++) node->root[i] = session.hashRoot[i];
                session_destroy();
				printf("\nLogged Out, ");
                return;                
            }
			case '1':{
				system("cls");
				ChangePass(node);
				break;
			}
            case '2':{
                system("cls");
                add();
                break;
            }
            case '3':{
                system("cls");
                view();
                break;
            }
            case '4':{
                system("cls");
                delete();
                break;
            }
        }
        system("cls");
    }
}

void LoginAccount(struct node *root){
	
	if(root==NULL){
		printf("No account registered\n");
		return;
	}
	char UsernameCheck[30],PasswordCheck[30];
	printf("<<Login>>\n\n");
	printf("Username: ");
	scanf("%s",UsernameCheck);
	getchar();
	fflush(stdin);
	
	int length=strlen(UsernameCheck);
	int UsernameSum=0;
	
	for(int i=0;i<length;i++){
		if(i<2){
			UsernameSum+=UsernameCheck[i]%10;
		}else{
			UsernameSum+=UsernameCheck[i];
		}
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
			fflush(stdin);
			if(strcmp(PasswordCheck,Data->Password)!=0){
				limit--;
				printf("Invalid Password\n");
			}else{
				break;
			}
		}while(limit>0);
		if(limit==0){
			system("cls");
			int menu = 0,length2;
			char AnswerCheck[30],NewPassword[30];

			while(menu != 1 && menu != 2){

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
						fflush(stdin);
						
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
							fflush(stdin);
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

			}//Endwhile

		} 
		
	}
	printf("\n\n<<Login Success>>\n\n");
	system("pause");
	system("cls");
	mainMenu(Data);
	
	
}

int main(){
	struct node *root=NULL;
	char menu; 
	session_destroy();
	do{
		printf("<<Password Manager>>\n\n");
		printf("<<Menu>>\n");
		printf("1. Create Account\n");
		printf("2. Login\n");
		printf("3. Delete Account\n");
		printf("4. Exit\n");
		menu = getch();
		
		switch(menu){
			
			case '1':
				system("cls");
				CreateAccount(&root);
				system("pause");
				break;
			case '2':
				system("cls");
				LoginAccount(root);
				system("pause");
				break;
			case '3':
				system("cls");
				DeleteAccount(&root);
				system("pause");
				break;
			case '4':{
				return 0;
			}
			
		}
		system("cls");
	}while(menu!='4');
}

