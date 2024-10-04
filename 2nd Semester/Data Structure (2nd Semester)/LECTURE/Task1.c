#include <stdio.h>
#include <stdlib.h>

struct node{
	int num;
	struct node *next;
};

struct node *NewNode=0, *head=0, *tail=0,*FirstNode=0;
struct node *key=0;
void CreateLinkedList(int input){
	
	NewNode = (struct node*)malloc(sizeof(struct node));
	NewNode->num=input;
	
	NewNode->next=NULL;
	head=NewNode;
	tail=head;
	
}

void AppendLinkedList(int input){
	
	NewNode = (struct node*)malloc(sizeof(struct node));
	NewNode->num=input;
	
	NewNode->next=head;
	head=NewNode;
	
}

void delete_begin(){
	
	struct node *deletenode;
	deletenode = head;
	
	head = head->next;
	
	free(deletenode);
	
	key = head;
	printf("Data after head/first node is deleted\n");
	while(key!=NULL){
		printf("%d ",key->num);
		key = key->next;
	}
	printf("\n");
}

void delete_last(){
	
	struct node *deletenode;
	
	deletenode=head;
	while(deletenode->next!=tail){
		deletenode = deletenode->next;
	}
	
	tail = deletenode;
	tail->next=NULL;
	
	free(deletenode->next);
	
	key=head;		
	printf("Data after tail/last node is deleted\n");
	while(key!=NULL){
		printf("%d ",key->num);
		key = key->next;
	}
	printf("\n");
}

int search_element(int number){
	int i=0;
	key=head;
	while(key!=NULL){
		if(key->num==number){
			return i;
		}
		key = key->next;
		i++;
	}
	return -1;
}


int main(){
	int input;
	CreateLinkedList(1);
	AppendLinkedList(2);	
	AppendLinkedList(3);
	AppendLinkedList(4);
	AppendLinkedList(5);
	
	key = head;
	
	printf("Original Data\n");
	while(key!=NULL){
		printf("%d ",key->num);
		key = key->next;
	}
	printf("\n");
	
	delete_begin();
	
	delete_last();
	
	printf("Enter the value whose element do you want to search: ");
	
	scanf("%d",&input);
	
	int index = search_element(input);
	
	printf("The element of that value is %d\n",index);
	
	
}
