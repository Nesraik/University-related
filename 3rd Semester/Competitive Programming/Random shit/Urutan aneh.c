#include <stdio.h>

void swap(int *a, int *b){
	int temp=*a;
	*a = *b;
	*b = temp;
}

int Partition (int *array, int low, int high){
	int pivot = array[high];
	int i = low - 1;
	
	for(int j = low; j<high;j++){
		if(array[j]<=pivot){
			i++;
			swap(&array[j], &array[i]);
		}	
	}
	swap(&array[i+1],&array[high]);
	return i+1;
}

void quicksort (int *array, int low,int high){
	
	if(low<high){
		int pi = Partition (array,low,high);
		quicksort(array,low,pi-1);
		quicksort(array,pi+1,high);
	}
}

int main(){
	int size;
	scanf("%d",&size);
	int array[size];
	
	for(int i=0;i<size;i++){
		scanf("%d",&array[i]);
	}
	
	quicksort(array,0,size-1);
	
	for(int i=0;i<=9;i++){
		for(int j=0;j<size;j++){
			if(array[j] % 10 == i){
				printf("%d\n",array[j]);
			}
		}
	}
	/*
	for(int i=0;i<size;i++){
		printf("%d ",array[i]);
	}
	*/
}
