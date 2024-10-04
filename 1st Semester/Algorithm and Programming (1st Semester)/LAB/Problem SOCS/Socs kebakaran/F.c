#include <stdio.h>
int quicksort(int number[25],int first,int last){
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
int binarySearch(int array[], int x, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid+1;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main(){
   int i, size,size2,order;
   scanf("%d",&size);
   int number[size];
   for(i=0;i<size;i++){
    scanf("%d",&number[i]);
	}
   quicksort(number,0,size-1);
   scanf("%d",&size2);
   int number2[size2];
   for(i=0;i<size2;i++){
   	scanf("%d",&number2[i]);
   }
   for(i=0;i<size2;i++){
   	 order = binarySearch(number,number2[i],0,size);
   	 printf("%d\n",order);
   }
	
   return 0;
}
