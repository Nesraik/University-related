//Bryan Orville Audric
//2602160750
#include <stdlib.h>
#include <stdio.h>

struct node{
	int Data;
	// 1 Red, 0 Black
	int Color;
	struct node *Parent;
	struct node *right;
	struct node *left;
	
};

struct node *root = NULL;

void SwapColor(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void RightRotate(struct node *Current){
	
	struct node *LeftCurrent = Current->left;
	
	Current->left=LeftCurrent->right;
	
	if(Current->left!=NULL){
		Current->left->Parent=Current;
	}
	LeftCurrent->Parent=Current->Parent;
	
	if(Current->Parent==NULL){
		root = LeftCurrent;
	}else if(Current == Current->Parent->left){
		Current->Parent->left= LeftCurrent;
	}else{
		Current->Parent->right=LeftCurrent;
	}
	
	LeftCurrent->right=Current;
	Current->Parent=LeftCurrent;
	
	
}

void LeftRotate(struct node *Current){
	
	struct node *RightCurrent = Current->right;
	
	Current->right=RightCurrent->left;
	
	if(Current->right!=NULL){
		Current->right->Parent=Current;
	}
	
	RightCurrent->Parent=Current->Parent;
	
	if(Current->Parent==NULL){
		root=RightCurrent;
	}else if(Current == Current->Parent->left){
		Current->Parent->left=RightCurrent;
	}else{
		Current->Parent->right=RightCurrent;
	}
	RightCurrent->left=Current;
	Current->Parent=RightCurrent;
	
}


struct node *BinarySearchInsertion(struct node *root,struct node *Current){
	
	if(root==NULL){
		return Current;
	}
	
	
	if(Current->Data<root->Data){
		root->left=BinarySearchInsertion(root->left,Current);
		root->left->Parent=root;
	}else if(Current->Data>root->Data){
		root->right=BinarySearchInsertion(root->right,Current);
		root->right->Parent=root;
	}
	
	return root;
}

void Fix(struct node *root, struct node *Current){
	
	struct node *GrandParent = NULL;
	struct node *Parent = NULL;
	
	while(Current!=root && Current->Color==1 && Current->Parent->Color==1){
		
		Parent = Current->Parent;
		GrandParent = Current->Parent->Parent;
		
		if(Parent == GrandParent->left){
			struct node *ParentSibling = GrandParent->right;
			
			if(ParentSibling!=NULL  && ParentSibling->Color==1){
				GrandParent->Color=1;
				Parent->Color=0;
				ParentSibling->Color=0;
				Current=GrandParent;
				
			}else{
				
				if(Current == Parent->right){
					LeftRotate(Parent);
					Current = Parent;
					Parent = Current->Parent;
				}
				
				RightRotate(GrandParent);
				SwapColor(&GrandParent->Color,&Parent->Color);
				
				Current = Parent;
			}
			
		}else{
			
			struct node *ParentSibling = GrandParent->left;
			
			if(ParentSibling!=NULL && ParentSibling->Color==1){
				GrandParent->Color=1;
				Parent->Color=0;
				ParentSibling->Color=0;
				Current=GrandParent;
			}else{
				
				if(Current == Parent->left){
					RightRotate(Parent);
					Current=Parent;
					Parent = Current->Parent;
				}
				
				LeftRotate(GrandParent);
				SwapColor(&GrandParent->Color,&Parent->Color);
				
				Current = Parent;
				
				
			}	
			
		}	
	}
}

void Insertion(){
	

	int Array[] = {41,22,5,51,48,29,18,21,45,3};
	
	int Length = sizeof(Array)/sizeof(Array[0]);
	
	for(int i=0;i<Length;i++){
		
		struct node *NewNode = (struct node*)malloc(sizeof(struct node));
		NewNode->Data=Array[i];
		NewNode->Color=1;
		NewNode->left=NULL;
		NewNode->right=NULL;
		NewNode->Parent=NULL;
		
		root = BinarySearchInsertion(root,NewNode);
		Fix(root,NewNode);
		
		root->Color=0;
	}
	
}

void PrintInOrder(struct node *root){
	
	if(root!=NULL){
		
		PrintInOrder(root->left);
		printf("%d ",root->Data);
		PrintInOrder(root->right);
	}
}


int main(){
	int menu;

	do{
		printf("1. Insertion\n");
		printf("2. PrintInorder\n");
		printf("3. Exit\n");
		printf(">> ");
		scanf("%d",&menu);
		switch(menu){
			case 1:
				system("cls");
				Insertion();
				printf("[41,22,5,51,48,29,18,21,45,3]\nInserted\n");
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				printf("InOrder Traversal\n");
				PrintInOrder(root);
				printf("\n");
				system("pause");
				system("cls");
				break;
		}
	}while(menu!=3);
}
