#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
	char CARDSeries[20];
	int BaseClockSpeed;
	int VRAMCapacity;
	int PowerSupplySize;
	int MemoryBandwith;
	struct stack *next;
};
struct stack *top,*newstack;

void Push(char CARDInput[20],int BaseClockInput,int VRAMInput,int PowerSupplyInput, int MemoryBandwithInput){
	newstack = (struct stack*)malloc(sizeof(struct stack));
	strcpy(newstack->CARDSeries,CARDInput);
	newstack->BaseClockSpeed=BaseClockInput;
	newstack->VRAMCapacity=VRAMInput;
	newstack->PowerSupplySize=PowerSupplyInput;
	newstack->MemoryBandwith=MemoryBandwithInput;
	
	if(top==NULL){
		newstack->next=NULL;
		top=newstack;
	}else{
		newstack->next=top;
		top=newstack;
	}
	
}

void Pop(){
	struct stack *deletestack,*current;
	current=top;
	top=top->next;
	deletestack=current;
	free(deletestack);
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
	
	
	Push(CARDSeriesInput,BaseClockSpeedInput,VRAMCapacityInput,PowerSupplySizeInput,MemoryBandwithInput);
	
	printf("\n<<%s Data is pushed into the stack>>\n",CARDSeriesInput);
	
}

void Display(){
	
	struct stack *key;
	if(top==NULL){
		printf("<<There is No Data>>\n");
		return;
	}
	key=top;
	
	printf("NVIDIA CARD Series\t Base Clock Speed\t VRAM Capacity\t Power Supply Size\t Memory Bandwith\n");
	printf("========================================================================================================\n");
	while(key!=NULL){
		printf("%-20s\t %d MHZ\t\t %d GB\t\t %d Watt\t\t %d GB/s\n",key->CARDSeries,key->BaseClockSpeed,key->VRAMCapacity,key->PowerSupplySize,key->MemoryBandwith);
		key=key->next;
	}
	
	
}

void Delete(){
	struct stack *current,*deletestack;
	current=top;
	char CARDSeriesInput[30];
	
	Display();
	printf("\n");
	printf("Enter Which CARD Series data do you want to Delete: ");
	scanf("%s",CARDSeriesInput);
	getchar();
	
	while(current!=NULL){
		if(strcmp(current->CARDSeries,CARDSeriesInput)==0 && current==top){
			top=top->next;
			deletestack=current;
			free(deletestack);
			break;
		}
		if(strcmp(current->next->CARDSeries,CARDSeriesInput)==0){
				
				deletestack=current->next;
				current->next=current->next->next;
				free(deletestack);
				break;
			}
		current= current->next;
	}
	
	printf("\n<<%s is popped from the stack>>\n",CARDSeriesInput);
}

int main(){
	int menu;
	printf("STACK\n");
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
