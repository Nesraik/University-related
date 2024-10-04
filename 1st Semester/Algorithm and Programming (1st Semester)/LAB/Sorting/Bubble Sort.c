#include <stdio.h>
void bubblesort(int array[],int size){
	int temp;
	for(int loop=0; loop<size-1;loop++){
	for(int i=0;i<size-loop-1;i++){
		if(array[i]>array[i+1]){
			temp=array[i];
			array[i]=array[i+1];
			array[i+1]=temp;
				}
			}
		}
	}
int main(){
	int array[]={80,40,20,76,11,35};
	int size=sizeof(array)/sizeof(array[0]);
	bubblesort(array,size);
	printf("Bubble Sort: ");
	for(int i=0;i<size;i++){
		printf("%d ",array[i]);
	}printf("\n");
	
}
