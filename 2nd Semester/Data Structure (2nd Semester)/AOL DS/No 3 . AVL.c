//Bryan Orville Audric
//2602160750
#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	struct node *left;
	struct node *right;
	int height;
};
int Count=0;
int Height(struct node *NodeIn){
	if(NodeIn==NULL){
		return 0;
	}else{
		return NodeIn->height;
	}
}

int Max (int a, int b){
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

struct node *RightRotate(struct node *Current){
	struct node *NewCurrent = Current->left;
	struct node *RightNewCurrent = NewCurrent->right;
	
	NewCurrent->right=Current;
	Current->left=RightNewCurrent;
	
	Current->height = 1 + Max(Height(Current->left),Height(Current->right));
	NewCurrent->height = 1 + Max(Height(NewCurrent->left),Height(NewCurrent->right));
	
	return NewCurrent;
	
}

struct node *LeftRotate(struct node *Current){
	struct node *NewCurrent = Current->right;
	struct node *LeftNewCurrent = NewCurrent->left;
	
	NewCurrent->left=Current;
	Current->right=LeftNewCurrent;
	
	Current->height = 1 + Max(Height(Current->left),Height(Current->right));
	NewCurrent->height = 1 + Max(Height(NewCurrent->left),Height(NewCurrent->right));
	
	return NewCurrent;
	
}

struct node *insert(struct node *root, int KeyInput){
	
	if(root==NULL){
		struct node *NewNode = (struct node*)malloc(sizeof(struct node));
		NewNode->key=KeyInput;
		NewNode->left=NULL;
		NewNode->right=NULL;
		NewNode->height=1;
		
		return NewNode;
	}
	
	if(KeyInput<root->key){
		root->left=insert(root->left,KeyInput);
	}else if(KeyInput>root->key){
		root->right=insert(root->right,KeyInput);
	}else{
		return root;
	}
	
	root->height = 1 + Max(Height(root->left),Height(root->right));
	
	int BalanceFactor = CheckBalance(root);
	
	if(BalanceFactor>1 && KeyInput<root->left->key){
		return RightRotate(root);
	}
	if(BalanceFactor>1 && KeyInput>root->left->key){
		root->left = LeftRotate(root->left);
		return RightRotate(root);
	}
	if(BalanceFactor<-1 && KeyInput>root->right->key){
		return LeftRotate(root);
	}
	if(BalanceFactor<-1 && KeyInput<root->right->key){
		root->right = RightRotate(root->right);
		return LeftRotate(root);
	}
	return root;
}

struct node *MinVal(struct node *root){
	
	struct node *Current=root;
	
	while(Current->left!=NULL){
		Current=Current->left;
	}
	
	return Current;
}


struct node *Deletenode (struct node *root, int KeyIn){
	
	if(root==NULL){
		return root;
	}
	
	if(KeyIn<root->key){
		root->left=Deletenode(root->left,KeyIn);
	}else if(KeyIn>root->key){
		root->right=Deletenode(root->right,KeyIn);
	}else{
		Count++;
		if(Count==1){
			printf("Data found\n");
			printf("Value %d was deleted\n",KeyIn);
		}
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
			root->right=Deletenode(root->right,temp->key);
		}	
	}
	root->height = 1 + Max(Height(root->left),Height(root->right));
	
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

void PrintPreOrder(struct node *root){
	if(root!=NULL){
		printf("%d ",root->key);
		PrintPreOrder(root->left);
		PrintPreOrder(root->right);
	}
}

void PrintInOrder(struct node *root){
	if(root!=NULL){
		PrintInOrder(root->left);
		printf("%d ",root->key);
		PrintInOrder(root->right);
	}	
}

void PrintPostOrder(struct node *root){
	if(root!=NULL){
		PrintPostOrder(root->left);
		PrintPostOrder(root->right);
		printf("%d ",root->key);
	}	
}

int main(){
	struct node *root=NULL;
	int menu,Data,DeleteData;
	do{
		printf("1. Insertion\n");
		printf("2. Deletion\n");
		printf("3. Traversal\n");
		printf("4. Exit\n");
		printf("Choose : ");
		scanf("%d",&menu);
		
		switch(menu){
			case 1:
				printf("Insert: ");
				scanf("%d",&Data);
				root = insert(root,Data);
				system("pause");
				system("cls");
				break;
			case 2:
				printf("Delete : ");
				scanf("%d",&DeleteData);
				Count=0;
				root = Deletenode(root,DeleteData);
				system("pause");
				system("cls");
				break;
			case 3:
				printf("Preorder: ");
				PrintPreOrder(root);
				printf("\n");
				printf("Inorder: ");
				PrintInOrder(root);
				printf("\n");
				printf("Postorder: ");
				PrintPostOrder(root);
				printf("\n");
				system("pause");
				system("cls");
				break;
		}
	}while(menu!=4);
	printf("Thank you\n");
	
}




