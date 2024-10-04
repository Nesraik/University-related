#include <stdio.h>
#include <stdlib.h>
struct node{
	int power;
	int coefficient;
	struct node *next;
	
};

struct node *head=0,*tail=0,*NewNode=0,*head2,*tail2,*NewNode2,*current,*current2,*head3,*tail3,*NewNode3,*duplicate,*key;
void CreateLinkedList(int CoefficientInput, int PowerInput){
	
	NewNode = (struct node*)malloc(sizeof(struct node));
	NewNode->coefficient=CoefficientInput;
	NewNode->power=PowerInput;
	
	NewNode->next=NULL;
	head = NewNode;
	tail=head;
	
}

void AddLastLinkedList(int Coefficient, int Power){
	
	NewNode = (struct node*)malloc(sizeof(struct node));
	
	NewNode->coefficient=Coefficient;
	NewNode->power=Power;
	
	tail->next=NewNode;
	tail = NewNode;
	NewNode->next=NULL;
	
}

void PrintLinkedList(){
	
	key = head;
	
	while(key!=NULL){
		printf("%dX^%d +",key->coefficient,key->power);
		
		key = key->next;
	}
	
}

int main(){
	
	//First Input
	
	CreateLinkedList(3,2);
	AddLastLinkedList(5,1);
	AddLastLinkedList(6,0);
	
	PrintLinkedList();
}
