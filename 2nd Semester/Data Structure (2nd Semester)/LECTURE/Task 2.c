#include <stdio.h>
#include <stdlib.h>
struct node{
	int power;
	int coefficient;
	struct node *next;
	
};

struct node *head,*tail,*NewNode,*head2,*tail2,*NewNode2,*current,*current2,*head3,*tail3,*NewNode3,*duplicate,*key;
void CreateLinkedList(int CoefficientInput, int PowerInput){
	
	NewNode = (struct node*)malloc(sizeof(struct node));
	NewNode->coefficient=CoefficientInput;
	NewNode->power=PowerInput;
	
	NewNode->next=NULL;
	head = NewNode;
	tail=head;
	
}

void CreateLinkedList2(int CoefficientInput, int PowerInput){
	
	NewNode2 = (struct node*)malloc(sizeof(struct node));
	NewNode2->coefficient=CoefficientInput;
	NewNode2->power=PowerInput;
	
	head2 = NewNode2;
	tail2=head2;
	NewNode2->next=NULL;
}

void CreateLinkedList3(int CoefficientInput, int PowerInput){
	
	NewNode3 = (struct node*)malloc(sizeof(struct node));
	NewNode3->coefficient=CoefficientInput;
	NewNode3->power=PowerInput;
	

	head3 = NewNode3;
	tail3=head3;
	NewNode3->next=NULL;
}

void AddLastLinkedList(int Coefficient, int Power){
	
	NewNode = (struct node*)malloc(sizeof(struct node));
	
	NewNode->coefficient=Coefficient;
	NewNode->power=Power;
	
	tail->next=NewNode;
	tail = NewNode;
	NewNode->next=NULL;
	
}

void AddLastLinkedList2(int Coefficient, int Power){
	
	NewNode2 = (struct node*)malloc(sizeof(struct node));
	
	NewNode2->coefficient=Coefficient;
	NewNode2->power=Power;
	
	tail2->next=NewNode2;
	tail2 = NewNode2;
	NewNode2->next=NULL;
}
void AddLastLinkedList3(int Coefficient, int Power){
	
	NewNode3 = (struct node*)malloc(sizeof(struct node));
	
	NewNode3->coefficient=Coefficient;
	NewNode3->power=Power;
	
	tail3->next=NewNode3;
	tail3 = NewNode3;
	NewNode3->next=NULL;
}

void MultiplyPolynomial(){
	int NewCoefficient,NewPower;
	current=head;
	int i=0,j=0;
	while(current!=NULL){
		current2=head2;
		while(current2!=NULL){
			NewCoefficient = current->coefficient * current2->coefficient;
			NewPower = current->power + current2->power;
			if(i == 0 && j== 0){
				CreateLinkedList3(NewCoefficient,NewPower);
			}else{
				AddLastLinkedList3(NewCoefficient,NewPower);
			}
			
			current2=current2->next;
			j++;
		}
		current=current->next;
		i++;
	}
}


void RemoveDuplicate(){
	
	current=head3;
	while(current!=NULL&&current->next!=NULL){
		current2=current;
		while(current2!=NULL && current2->next!=NULL){
			if(current->power == current2->next->power){
				current->coefficient = current->coefficient+ current2->next->coefficient;
				duplicate = current2->next;
				current2->next= current2->next->next;
				free(duplicate);
			}else{
				current2=current2->next;
			}
		}
		current=current->next;
	}
}

void PrintLinkedList3(){
	
	key = head3;
	
	printf("Expected Output: ");
	while(key!=NULL){
		if(key->power>0){
			printf("%dX^%d + ",key->coefficient,key->power);
		}
		else{
			printf("%d",key->coefficient);
		}
		key = key->next;
	}
	
}

void PrintLinkedList2(){
	
	key = head2;
	
	printf("Second Output: ");
	while(key!=NULL){
		if(key->power>0){
			printf("%dX^%d + ",key->coefficient,key->power);
		}
		else{
			printf("%d",key->coefficient);
		}
		key = key->next;
	}
	printf("\n");
	
}

void PrintLinkedList(){
	
	key = head;
	
	printf("First Output: ");
	while(key!=NULL){
		if(key->power>0){
			printf("%dX^%d + ",key->coefficient,key->power);
		}
		else{
			printf("%d",key->coefficient);
		}
		key = key->next;
	}
	printf("\n");
	
}

int main(){
	
	//First Input
	
	CreateLinkedList(3,2);
	AddLastLinkedList(5,1);
	AddLastLinkedList(6,0);
	
	PrintLinkedList();
	//Second Input
	
	CreateLinkedList2(6,1);
	AddLastLinkedList2(8,0);
	PrintLinkedList2();
	
	MultiplyPolynomial();
	RemoveDuplicate();
	PrintLinkedList3();
	
}
