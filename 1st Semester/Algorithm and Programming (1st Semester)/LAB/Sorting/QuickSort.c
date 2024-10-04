#include <stdio.h>
void quicksort(int array[],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(array[i]<=array[pivot]&&i<last)
         i++;
         while(array[j]>array[pivot])
         j--;
         if(i<j){
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
         }
      }
      temp=array[pivot];
      array[pivot]=array[j];
      array[j]=temp;
      quicksort(array,first,j-1);
      quicksort(array,j+1,last);
   }
}

int main(){
	int array[]={80,40,20,76,11,35};
	int size= sizeof(array)/sizeof(array[0]);
	quicksort(array,0,size-1);
	printf("Quick Sort: ");
	for(int i=0; i<size;i++){
		printf("%d ",array[i]);
	}printf("\n");
}
