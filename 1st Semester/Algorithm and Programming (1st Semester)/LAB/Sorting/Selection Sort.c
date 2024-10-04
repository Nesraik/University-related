#include <stdio.h>
void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void selectionsort(int array[], int size){
	for(int step=0; step<size-1;step++){
		int min=step;
		for(int i=step+1; i<size;i++){
			if(array[i]<array[min]){
				min=i;
			}		
		}
		swap(&array[min],&array[step]);
	}
}
int main(){
	int array[]={80,40,20,76,11,35};
	int size=sizeof(array)/sizeof(array[0]);
	selectionsort(array,size);
	printf("Selection Sort: ");
	for(int i=0; i<size;i++){
		printf("%d ",array[i]);
	}printf("\n");
}
