#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char CARDSeries[20];
	int BaseClockSpeed;
	int VRAMCapacity;
	int PowerSupplySize;
	int MemoryBandwith;
	struct node *next;
	struct node *previous;
};
struct node *head, *tail,*newnode;
int DataSize=0;

void CreateLinkedList(char CARDInput[20],int BaseClockInput,int VRAMInput,int PowerSupplyInput, int MemoryBandwithInput){
	
	newnode = (struct node*)malloc(sizeof(struct node));
	strcpy(newnode->CARDSeries,CARDInput);
	newnode->BaseClockSpeed=BaseClockInput;
	newnode->VRAMCapacity=VRAMInput;
	newnode->PowerSupplySize=PowerSupplyInput;
	newnode->MemoryBandwith=MemoryBandwithInput;
	
	head=newnode;
	tail=head;
	tail->next=head;
	head->previous=tail;
	
}

void AddFromtheRight(char CARDInput[20],int BaseClockInput,int VRAMInput,int PowerSupplyInput, int MemoryBandwithInput){
	newnode = (struct node*)malloc(sizeof(struct node));
	strcpy(newnode->CARDSeries,CARDInput);
	newnode->BaseClockSpeed=BaseClockInput;
	newnode->VRAMCapacity=VRAMInput;
	newnode->PowerSupplySize=PowerSupplyInput;
	newnode->MemoryBandwith=MemoryBandwithInput;
	
	tail->next=newnode;
	tail=newnode;
	tail->next=head;
	head->previous=tail;
	
}

void Store(){
	
	char CARDSeriesInput[20];
	int BaseClockSpeedInput,VRAMCapacityInput,PowerSupplySizeInput,MemoryBandwithInput;
	
	printf("NVIDIA CARD Series: ");
	fflush(stdin);
	scanf("%[^\n]",CARDSeriesInput);
	getchar();
	
	printf("Base Clock Speed(MHZ): ");
	scanf("%d",&BaseClockSpeedInput);
	getchar();
	
	printf("VRAM Capacity(GB): ");
	scanf("%d",&VRAMCapacityInput);
	getchar();
	
	printf("Size of Power Supply(Watt): ");
	scanf("%d",&PowerSupplySizeInput);
	getchar();
	
	printf("Memory Bandwith(GB/s): ");
	scanf("%d",&MemoryBandwithInput);
	getchar();
	
	if(DataSize==0){
		CreateLinkedList(CARDSeriesInput,BaseClockSpeedInput,VRAMCapacityInput,PowerSupplySizeInput,MemoryBandwithInput);
	}else{
		AddFromtheRight(CARDSeriesInput,BaseClockSpeedInput,VRAMCapacityInput,PowerSupplySizeInput,MemoryBandwithInput);
	}
	DataSize++;
	
}

void Display(){
	
	struct node *key;
	if(DataSize==0){
		printf("<<There is No Data>>\n");
		return;
	}
	key=head;
	
	printf("NVIDIA CARD Series\t Base Clock Speed\t VRAM Capacity\t Power Supply Size\t Memory Bandwith\n");
	printf("========================================================================================================\n");
	do{
		printf("%-20s\t %d MHZ\t\t %d GB\t\t %d Watt\t\t %d GB/s\n",key->CARDSeries,key->BaseClockSpeed,key->VRAMCapacity,key->PowerSupplySize,key->MemoryBandwith);
		key=key->next;
	}while(key!=tail->next);
	
}

void Delete(){
	struct node *current,*deletenode,*current2;
	current=head;
	char CARDSeriesInput[30];
	
	Display();
	printf("\n");
	printf("Enter Which CARD Series data do you want to Delete: ");
	scanf("%s",CARDSeriesInput);
	getchar();
	
	do{
		if(strcmp(current->next->CARDSeries,CARDSeriesInput)==0){
			deletenode=current->next;
			if(deletenode==head){
				head=deletenode->next;
				current2=current->next->next;
				current->next=current2;
				current2->previous=current;	
			}else if(deletenode==tail){
				tail=deletenode->next;
				current2=current->next->next;
				current->next=current2;
				current2->previous=current;
			}else{
				current2=current->next->next;
				current->next=current2;
				current2->previous=current;
			}	
			free(deletenode);
		}
		current=current->next;
	}while(current!=tail->next);
	printf("<<Data Deleted>>\n");
}

int main(){
	int menu;
	printf("CIRCULAR DOUBLY LINKED LIST\n");
	do{
		printf("<<Menu>>\n");
		printf("1. Store\n");
		printf("2. Display\n");
		printf("3. Delete\n");
		printf("Menu Selection: ");
		scanf("%d",&menu);
		
		switch(menu){
			
			case 1:
				system("cls");
				Store();
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				Display();
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				Delete();
				system("pause");
				system("cls");
				break;
		}
	}while(menu!=4);
	
	
}
