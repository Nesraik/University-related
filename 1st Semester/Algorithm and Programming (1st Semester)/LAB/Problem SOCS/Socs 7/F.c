#include <stdio.h>
int quicksort(int number[],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
         i++;
         while(number[j]>number[pivot])
         j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}
int main(){
	int size,a;
	scanf("%d",&size);
	int num[size];
	for(int i=0; i<size; i++){
		scanf("%d",&num[i]);
	}
	quicksort(num,0,size-1);
	int j = (size)/2;
	for(int i=j+1 ; i<size; i++){
		printf("%d",num[i]);
		if(i!=size-1){
			printf(" ");
		}else{
			printf("\n");
		}
	}
	return 0;
}
