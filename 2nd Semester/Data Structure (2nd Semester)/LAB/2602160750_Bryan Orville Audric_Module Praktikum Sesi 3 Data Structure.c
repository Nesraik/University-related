#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct queue{
	char Name[100];
	int age;
	char Desc[200];
	char code [10];
	struct queue *next;
	struct queue *prev;
};
int datasize=0;
struct queue *front,*rear,*newqueue;

void EnqueueFromtheRight(char NameInput[100], int AgeInput, char DescInput[200], char CodeInput[10]){
	newqueue = (struct queue*)malloc(sizeof(struct queue));
	strcpy(newqueue->Name,NameInput);
	newqueue->age=AgeInput;
	strcpy(newqueue->Desc,DescInput);
	strcpy(newqueue->code,CodeInput);
	
	if(front==NULL){
		newqueue->next=NULL;
		newqueue->prev=NULL;
		front=newqueue;
		rear=front;
	}else{
		rear->next=newqueue;
		newqueue->prev=rear;
		newqueue->next=NULL;
		rear=newqueue;
	}

}

void EnqueueFromtheLeft(char NameInput[100], int AgeInput, char DescInput[200], char CodeInput[10]){
	newqueue = (struct queue*)malloc(sizeof(struct queue));
	strcpy(newqueue->Name,NameInput);
	newqueue->age=AgeInput;
	strcpy(newqueue->Desc,DescInput);
	strcpy(newqueue->code,CodeInput);
	
	if(front==NULL){
		newqueue->next=NULL;
		newqueue->prev=NULL;
		front=newqueue;
		rear=front;
	}else{
		newqueue->next=front;
		front->prev=newqueue;
		newqueue->prev=NULL;
		front=newqueue;
	}
	
}

void EnqueuetotheMiddle(char NameInput[100], int AgeInput, char DescInput[200], char CodeInput[10]){
	newqueue = (struct queue*)malloc(sizeof(struct queue));
	strcpy(newqueue->Name,NameInput);
	newqueue->age=AgeInput;
	strcpy(newqueue->Desc,DescInput);
	strcpy(newqueue->code,CodeInput);
	
	struct queue *current,*current2;
	int found=0;
	
	if(front==NULL){
		newqueue->next=NULL;
		newqueue->prev=NULL;
		front=newqueue;
		rear=front;
		return;
	}
	
	current=front;
	while(current!=NULL){
		if(strcmp(current->code,"Green")==0){
			found = 1;
			break;
		}
		current=current->next;
	}
	
	if(found == 1){
		current=front;
		while(current!=NULL){
			if(strcmp(current->next->code,"Green")==0){
				current2=current->next;
				
				current->next=newqueue;
				newqueue->prev=current;
				
				newqueue->next=current2;
				current2->prev=newqueue;
				break;
			}
		current=current->next;
		}
	}else{
		rear->next=newqueue;
		newqueue->prev=rear;
		newqueue->next=NULL;
		rear=newqueue;	
	}
	
	
	
}


void Insert(){
	char NameInputs[100],DescInputs[100],CodeInputs[100];
	int AgeInputs;
	
	printf("Input patient name[4-25]: ");
	fflush(stdin);
	scanf("%[^\n]",NameInputs);
	getchar();
	
	int length =strlen(NameInputs);
	
	while(length<4 || length >25){
		printf("Input patient name[4-25]: ");
		fflush(stdin);
		scanf("%[^\n]",NameInputs);
		getchar();
		
		length =strlen(NameInputs);
	}
	
	printf("Input patient age[>= 0]: ");
	scanf("%d",&AgeInputs);
	getchar();
	
	while(AgeInputs<0){
		printf("Input patient age[>= 0]: ");
		scanf("%d",&AgeInputs);
		getchar();
	}
	
	printf("Input patient description[>= 6]: ");
	fflush(stdin);
	scanf("%[^\n]",DescInputs);
	getchar();
	
	length =strlen(DescInputs);
	
	while(length<6){
		printf("Input patient description[>= 6]: ");
		fflush(stdin);
		scanf("%[^\n]",DescInputs);
		getchar();
		
		length =strlen(DescInputs);
	}
	
	printf("Input code[Red|Yellow|Green]: ");
	fflush(stdin);
	scanf("%s",CodeInputs);
	getchar();
	
    while(strcmp(CodeInputs,"Green")!=0 && strcmp(CodeInputs,"Yellow")!=0 && strcmp(CodeInputs,"Red")!=0){
    	printf("Input code[Red|Yellow|Green]: ");
		fflush(stdin);
		scanf("%[^\n]",CodeInputs);
		getchar();
	}
	
	if(strcmp(CodeInputs,"Green")==0){
		EnqueueFromtheRight(NameInputs, AgeInputs, DescInputs, CodeInputs);
	}else if(strcmp(CodeInputs,"Red")==0){
		EnqueueFromtheLeft(NameInputs, AgeInputs, DescInputs, CodeInputs);
	}else{
		EnqueuetotheMiddle(NameInputs, AgeInputs, DescInputs, CodeInputs);
	}
	datasize++;
	
	printf("\nInsert Success !\n");
}

void View(){
	struct queue *current;
	int index=1;
	
	if(front==NULL||datasize==0){
		printf("There is no queue yet!\n");
		return;
	}
	printf("Patient List: \n");
	printf("-----------------------------------------------------------------------------------------\n");
	printf("|No\t |Name\t\t\t |Age\t |Description\t\t\t |Code\n");
	printf("-----------------------------------------------------------------------------------------\n");
	current=front;
	while(current!=NULL){
		printf("|%d\t |%-20s\t |%d\t |%-20s\t\t |%s\n",index,current->Name,current->age,current->Desc,current->code);
		printf("-----------------------------------------------------------------------------------------\n");
		current=current->next;
		index++;
	}printf("\n");
	
}

void Dequeue(){
	if(front==NULL||datasize==0){
		printf("There is no queue yet!\n");
		return;
	}
	printf("The next patient is: \n");
	printf("Name: %s\n",front->Name);
	printf("Age: %d\n",front->age);
	printf("Description: %s\n",front->Desc);
	printf("Code: %s\n",front->code);
	
	
	if(front->next==NULL){
		free(front);
		front=NULL;
	}else{
		struct queue *deletequeue;
		deletequeue=front;
		front=front->next;
		front->prev=NULL;
		free(deletequeue);
	}	
	datasize=datasize-1;
}



int main(){
	int menu;
	printf("BLUEJACK HOSPITAL\n");
	printf("==================\n\n");
	do{
		printf("<<Menu>>\n");
		printf("1. Insert\n");
		printf("2. View\n");
		printf("3. Next Queue\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d",&menu);
		
		switch(menu){
			case 1:
				system("cls");
				Insert();
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				View();
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				Dequeue();
				system("pause");
				system("cls");
				break;	
		}
	}while(menu!=4);
	
}

