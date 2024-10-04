#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int height;
	struct node *left;
	struct node *right;
	char GameTitle [26];
	char GameGenre [10];
	int GameStock;
	int Key;
};

int Height(struct node *NodeIn){
	if(NodeIn==NULL){
		return 0;
	}else{
		return NodeIn->height;
	}
}

int Max(int a, int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

int CheckBalance(struct node *NodeIn){
	if(NodeIn==NULL){
		return 0;
	}else{
		return Height(NodeIn->left)-Height(NodeIn->right);
	}
}

struct node *MinVal(struct node *RootIn){
	
	struct node *Current=RootIn;
	
	while(Current->left!=NULL){
		Current=Current->left;
	}
	return Current;
	
}

struct node *RightRotate(struct node *Current){
	
	struct node *NewCurrent = Current->left;
	struct node *RightOldCurrent = NewCurrent->right;
	
	NewCurrent->right=Current;
	Current->left=RightOldCurrent;
	
	Current->height= 1 + Max(Height(Current->left),Height(Current->right));
	NewCurrent->height= 1 + Max(Height(NewCurrent->left),Height(NewCurrent->right));
	
	return NewCurrent;
	
}

struct node *LeftRotate(struct node *Current){
	
	struct node *NewCurrent = Current->right;
	struct node *LeftOldCurrent = NewCurrent->left;
	
	NewCurrent->left=Current;
	Current->right=LeftOldCurrent;
	
	Current->height= 1 + Max(Height(Current->left),Height(Current->right));
	NewCurrent->height= 1 + Max(Height(NewCurrent->left),Height(NewCurrent->right));
	
	return NewCurrent;
	
}



struct node *Insert(struct node *root, char *GameTitleIn, char *GameGenreIn, int GameStockIn,int KeyIn){
	
	if(root==NULL){
		struct node *Newnode = (struct node*)malloc(sizeof(struct node));
		Newnode->height=1;
		strcpy(Newnode->GameTitle,GameTitleIn);
		strcpy(Newnode->GameGenre,GameGenreIn);
		Newnode->GameStock=GameStockIn;
		Newnode->left=NULL;
		Newnode->right=NULL;
		Newnode->Key=KeyIn;
		return Newnode;
	}
	
	if(KeyIn < root->Key){
		root->left=Insert(root->left,GameTitleIn,GameGenreIn,GameStockIn,KeyIn);
	}else if(KeyIn>root->Key){
		root->right=Insert(root->right,GameTitleIn,GameGenreIn,GameStockIn,KeyIn);
	}
	
	root->height = 1 + Max(Height(root->left),Height(root->right));
	
	int BalanceFactor = CheckBalance(root);
	
	if(BalanceFactor>1 && KeyIn<root->left->Key){
		return RightRotate(root);
	}
	if(BalanceFactor>1 && KeyIn>root->left->Key){
		root->left=LeftRotate(root->left);
		return RightRotate(root);
	}
	if(BalanceFactor<-1 && KeyIn>root->right->Key){
		return LeftRotate(root);
	}
	if(BalanceFactor<-1 && KeyIn<root->right->Key){
		root->right=RightRotate(root->right);
		return LeftRotate(root);
	}
	
	return root;
	
}

struct node *Delete(struct node *root, int KeyIn){
	
	if(root==NULL){
		return root;
	}
	
	if(KeyIn<root->Key){
		root->left=Delete(root->left,KeyIn);
	}else if(KeyIn>root->Key){
		root->right=Delete(root->right,KeyIn);
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
			root->Key=temp->Key;
			root->right=Delete(root->right,temp->Key);
			
		}
	}
		
	root->height = 1 + Max(Height(root->left),Height(root->right));
	
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

struct node *Search(struct node *root,int KeyIn){

	if(root==NULL){
		return root;
	}
	
	if(KeyIn==root->Key){
		return root;
	}else if(KeyIn<root->Key){
		return Search(root->left,KeyIn);
	}else{
		return Search(root->right,KeyIn);
	}
	
}

void InsertGame (struct node **root){
	
	char Title[26],Genre[10];
	int StockIn,SumofASCII,length;
	struct node *Data;
	do{
		printf("Input game title[5-25][unique]: ");
		fflush(stdin);
		scanf("%[^\n]",Title);
		getchar();
		
		length = strlen(Title);
		
		SumofASCII = 0;
		for(int i=0;i<length;i++){
			SumofASCII+=Title[i];
		}	
		
		Data = Search ((*root),SumofASCII);
		
	}while(Data!=NULL || length < 5 || length>30);
	
	do{
		printf("Input game type[Action|RPG|Adventure|Card Game]: ");
		scanf("%[^\n]",Genre);
		getchar();
	}while(strcmp(Genre,"Action")!=0 && strcmp(Genre,"RPG")!=0 && strcmp(Genre,"Adventure")!=0 && strcmp(Genre,"Card Game")!=0 );
	
	do{
		printf("Input game stock[>=1]: ");
		scanf("%d",&StockIn);
	}while(StockIn<1);
	
	*root = Insert((*root),Title,Genre, StockIn, SumofASCII);
	
	printf("\nInsert success !\n\n");
}

void PrintInOrder(struct node *root){
	if(root!=NULL){
		
		PrintInOrder(root->left);
		printf("|%-20s\t |%-20s\t |%d\t\t|\n",root->GameTitle,root->GameGenre,root->GameStock);
		printf("-----------------------------------------------------------------\n");
		PrintInOrder(root->right);
	}

}

void ViewGame(struct node *root){
	
	if(root==NULL){
		printf("Warehouse is empty !\n");
		return;
	}
	
	printf("-----------------------------------------------------------------\n");
	printf("|Game Title\t\t |Game Genre\t\t |Game Stock\t|\n");
	printf("-----------------------------------------------------------------\n");
	PrintInOrder(root);
}

struct node *UpdateGame(struct node **root){
	
	if(*root==NULL){
		printf("Warehouse is empty !\n");
		return 0;
	}
	char GameTitleIn[26];
	printf("Input game title: ");
	fflush(stdin);
	scanf("%[^\n]",GameTitleIn);
	getchar();
	
	int length = strlen(GameTitleIn);
	
	int SumofASCII=0;
	
	for(int i=0;i<length;i++){
		SumofASCII+=GameTitleIn[i];
	}
	
	struct node *Data = Search ((*root),SumofASCII);
	
	if(Data==NULL){
		printf("\nData not found !\n");
		return 0;
	}else{
		printf("Current Stock: %d\n",Data->GameStock);
		char Option[30];
		int StockIn;
		do{
			printf("Input update type[add|remove][case insensitive]: ");
			scanf("%s",Option);
			getchar();
			
			length = strlen(Option);
			
			for(int i=0;i<length;i++){
				if(Option[i]<'a'){
					Option[i]= Option[i]+32;
				}
			}

		}while(strcmp(Option,"add")!=0 && strcmp(Option,"remove")!=0);
		
		if(strcmp(Option,"add")==0){
			do{
				printf("Input stock to add[>=1]: ");
				scanf("%d",&StockIn);
			}while(StockIn<1);
			Data->GameStock= Data->GameStock + StockIn;
			printf("\nInsert Success !\n");
		}else{
			do{
				printf("Input stock to remove[1-%d]: ",Data->GameStock);
				scanf("%d",&StockIn);
			}while(StockIn<1 || StockIn > Data->GameStock);
			
			Data->GameStock = Data->GameStock - StockIn;
			
			if(Data->GameStock==0){
				*root = Delete (*root,SumofASCII);
				printf("%s is removed from the warehouse !\n\n",Data->GameTitle);
				return (*root);
			}
		}
		
	}
	
}


int main(){
	struct node *root=NULL;
	int menu;
	do{
		printf("Bluejack Gshop\n");
		printf("==============\n");
		printf("1. Insert Game\n");
		printf("2. View Game\n");
		printf("3. Update Stock\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d",&menu);
		
		switch(menu){
			case 1:
				system("cls");
				InsertGame(&root);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				ViewGame(root);
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				UpdateGame(&root);
				system("pause");
				system("cls");
				break;
		}
	}while(menu!=4);
}

