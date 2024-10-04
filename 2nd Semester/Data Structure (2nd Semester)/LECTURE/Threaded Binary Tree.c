#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Source :
-Insertion
https://www.geeksforgeeks.org/threaded-binary-tree-insertion/

-Deletion 
https://www.geeksforgeeks.org/threaded-binary-search-tree-deletion/

*/
struct node{
	int Key;
	struct node *left;
	struct node *right;
	bool RightThread;
	bool LeftThread;
};

//Note: RightThread is false when its connecting to something, else its true
//		Left Thread is false when its connecting to something, else its true
//This means the "thread" is set to true when it can be used and when its false, it mean the "thread" is used

struct node *Insert(struct node *root, int KeyInput){
	
	struct node *current = root;
	struct node *parent = NULL;
	
	while(current!=NULL){
		
		if(KeyInput == current->Key){
			printf("Duplicate Key\n");
			return root;
		}
		
		parent = current;
		
		if(KeyInput < current->Key ){
			if(current->LeftThread==false){
				current=current->left;
			}else{
				break;
			}
		}else{
			if(current->RightThread==false){
				current=current->right;
			}else{
				break;
			}
		}
	}
	
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->Key=KeyInput;
	newnode->LeftThread=true;
	newnode->RightThread=true;
	newnode->left=NULL;
	newnode->right=NULL;
	
	//Root is empty / First Data
	if(parent==NULL){
		root=newnode;
	}
	//if Data's key is smaller than parent's key, it goes to the left subtree / its inserted in the left side 
	else if(KeyInput<parent->Key){
		newnode->left=parent->left;
		newnode->right=parent;
		parent->left=newnode;
		parent->LeftThread=false;//The parent's left "thread" is used to connect to newnode
	}
	//If Data's key is bigger than parent's key, it goes to the right subtree /  its inserted in the right side
	else{
		newnode->right=parent->right;
		newnode->left=parent;
		parent->right=newnode;
		parent->RightThread=false;//The parent's right "thread" is used to connect to newnode;
	}
	
	return root;
}

//Find Inorder Successor
struct node *InorderSuccessor(struct node *current){
	//if there's  no right child
	if(current->RightThread==true){
		//go up right side of current node and return that node which will be an InorderSuccessor of current node
		return current->right;	
	}
	
	//There is a right child 
	current=current->right;
	
	//Find the leftmost child on the right subtree
	
	while(current->LeftThread==false){//as long as left thread is connecting to something, we travel through the thread
		current=current->left;
	}
	return current;
}

struct node *InorderPredecessor(struct node *current){
	
	//if there's no left child
	if(current->LeftThread==true){
		//go up left side of current node and return that node which will be an InorderPredecessor of current node
		return current->left;
	}
	
	//There is left child
	current=current->left;
	
	//Find the Rightmost child on the right subtree
	
	while(current->RightThread==false){//as long as right thread is connecting to something, we travel through the thread
		current=current->right;
	}
	return current;
	
}
struct node *NoChild(struct node *root, struct node *parent, struct node *current){
	
	if(parent==NULL){
		root==NULL;
	}
	
	//Current is parent's left child
	else if(current==parent->left){
		//Restore Connection and Unconnect parent node with current node
		parent->left=current->left;
		parent->LeftThread=true;
	}
	//Current is parent's right child
	else if(current==parent->right){
		//Restore Connection and Unconnect parent node with current node
		parent->right=current->right;
		parent->RightThread=true;
	}
	free(current);
	return root;	
}

struct node *OneChild(struct node *root, struct node *parent, struct node *current){
	
	struct node *Child;
	
	//If current's child is on the left
	if(current->LeftThread==false){
		Child=current->left;//Set Child node
	}
	//if current's child is on the right
	else{
		Child=current->right;//Set Child node
	}
	
	//If current's parent node doesnt exist, set the child to be the root
	if(parent==NULL){
		root=Child;
	}
	
	//We want to connect the parent of current(node to be deleted) to current's child
	
	//if current is parent's left child
	else if(current==parent->left){
		parent->left=Child;//Connect parent to current's child
	}
	//if current is parent's right child
	else{
		parent->right=Child;//Connect parent to current's child
	}
	
	//Find predecessor and Successor in case of current having a right/left subtree
	
	struct node *Predecessor = InorderPredecessor(root);
	struct node *Successor = InorderSuccessor(root);
	
	//If current has left subtree
	if(current->LeftThread==false){
		Predecessor->right=Successor;//Connect Current's Predecessor to Current's Successor
	}
	
	//If current has right subtree
	else{
		Successor->left=Predecessor;//Connect Current's Successor to Current's Predecessor
	}
	
	free(current);
	return root;
}

struct node *TwoChild(struct node *root, struct node *parent, struct node *current){
	
	struct node *ParentOfSuccessor = current;
	struct node *Successor = current->right;
	
	//Finding Current's Succesor and Its parent
	while(Successor->LeftThread==false){
		ParentOfSuccessor = Successor;
		Successor = Successor->left;
	}
	
	//Grabbing Successor's Key
	current->Key=Successor->Key;
	
	//We are deleting Successor's node
	//If Successor has no child
	if(Successor->LeftThread==true && Successor->RightThread==true){
	
		root = NoChild(root,ParentOfSuccessor,Successor);
	}
	//If Succesor has either left or right subtree
	else{
		root = OneChild(root,ParentOfSuccessor,Successor);
	}
	
	
	
	
}

void PrintInorder(struct node *root){
	//if there is no data
	if(root==NULL){
		printf("Tree is empty\n");
		return;
	}
	
	struct node *current = root;
	
	//Travel to the leftmost side of the tree
	
	while(current->LeftThread==false){//as long as left thread is connecting to something, we travel through the thread
		current=current->left;
	}
	
	while(current!=NULL){
		printf("%d ",current->Key);
		
		//store inorder successor
		current = InorderSuccessor(current);
	}
}

struct node *DeleteThreadedNode(struct node *root, int DeleteKey){
	
	struct node *current=root;
	struct node *parent=NULL;
	
	int found=0;
	while(current!=NULL){
		
		//When we found the node that we want to delete
		if(DeleteKey==current->Key){
			found = 1;
			break;
		}
		parent=current;
		if(DeleteKey<current->Key){
			if(current->LeftThread==false){
				current=current->left;
			}else{
				break;
			}
		}else{
			if(current->RightThread==false){
				current=current->right;
			}else{
				break;
			}
		}
	}
	
	if(found==0){
		printf("Inputed Key is not present in the tree\n");
		return 0;
	}//When the node to be deleted has two child
	else if(current->LeftThread==false && current->RightThread==false){
		root = TwoChild(root,parent,current);
	}//When the node to be deleted has one child
	else if(current->RightThread==false || current->LeftThread==false){
		root = OneChild(root,parent,current);
	}//When the node to be deleted has no child
	else{
		root = NoChild(root,parent,current);
	}
	return root;
	
}


int main(){
	struct node *root=NULL;
	
	//First Data
	root = Insert(root,30);

	Insert(root,15);
	Insert(root,40);
	Insert(root,14);
	Insert(root,16);
	Insert(root,35);
	
	printf("Before Deletion:\n");
	PrintInorder(root);
	
	DeleteThreadedNode(root,30);
	printf("\n\nAfter Deleting 30: \n");
	PrintInorder(root);
	
	DeleteThreadedNode(root,40);
	printf("\n\nAfter Deleting 40: \n");
	PrintInorder(root);
	
}
