#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Size 31

int Heap[Size];
int CurrentSize=0;

void Swap(int *a, int *b){
	
	int temp = *a;
	*a = *b;
	*b = temp;

}

void Insert(int value){
	if(CurrentSize==Size){
		printf("Heap is full\n");
		return;
	}
	
	Heap[CurrentSize]=value;
	int Current = CurrentSize;
	
	while(Current!=0 && Heap[Current - 1 / 2] <  Heap[Current]){
		Swap(&Heap[Current-1/2],&Heap[Current]);
		Current = Current-1/2;
	}
	
	CurrentSize++;	
}

void Heapify(int root){
	
	int largest = root;
	int rootleft = 2 * root + 1;
	int rootright = 2 * root + 2;
	
	if(rootleft<CurrentSize && Heap[rootleft] > Heap[largest]){
		largest = rootleft;
	}
	
	if(rootright<CurrentSize && Heap[rootright]>Heap[largest]){
		largest = rootright;
	}
	
	if(largest !=root){
		Swap(&Heap[largest],&Heap[root]);
		Heapify(largest);
	}
	
}


void Pop(){
	if(CurrentSize==0){
		printf("There is no data\n");
		return;
	}
	
	int Max = Heap[0];
	
	Heap[0] = Heap[CurrentSize-1];
	CurrentSize--;
	
	Heapify(0);
	printf("Delete Success\n");
	
}

void View(){
	
	int Element=0, Space,PreSpace;
	int length = 4,Height = 5;
	
	for(int i=0; i< Height;i++){
		Space = pow(2,Height-1-i)*length + pow(2,Height-i)-2;
		PreSpace = (Space)/2;
		for(int k = 0; k<PreSpace;k++){
			printf(" ");
		}
		for(int j= 0; j< pow(2,i);j++){
			if(Heap[Element]=='\0'){
				printf("NL");
			}else{
				printf("%2d",Heap[Element]);
				Element++;
			}
			for(int l = 0 ; l<Space;l++){
				printf(" ");
			}
		}
		printf("\n");
	}
	
	
}


int main(){
	int menu,value;
	do{
		printf("MAX HEAP TREE\n");
		printf("=================\n");
		printf("1. Insert\n");
		printf("2. View\n");
		printf("3. Pop\n");
		printf("4. Exit\n");
		printf("Choose: ");
		scanf("%d",&menu);
		switch(menu){
			case 1:
				printf("Input your data [1-100]: ");
				scanf("%d",&value);
				Insert(value);
				printf("Insert Success\n");
				system("pause");
				system("cls");
				break;
			case 2:
				printf("Only 5 levels are shown\n");
				View();
				system("pause");
				system("cls");
				break;
			case 3:
				Pop();
				system("pause");
				system("cls");
				break;
			case 4:
				for(int i=0;i<CurrentSize;i++){
					Heap[i]=='\0';
				}
		}
	}while(menu!=4);
}
