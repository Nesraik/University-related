#include <stdio.h>
int binarySearch(int a[], int left,int right, int q)
{
    int hasil=-2;
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(a[mid]<q)
        {
            left=mid+1;
        }
        else
        {
            if(a[mid]==q)
            {
                hasil=mid;
            }
            right=mid-1;
        }
    }
    return hasil+1;
}
int main(){
   int i, size,size2,order;
   scanf("%d %d",&size,&size2);
   int number[size];
   for(i=0;i<size;i++){
    scanf("%d",&number[i]);
	}
   int number2[size2];
   for(i=0;i<size2;i++){
   	scanf("%d",&number2[i]);
   }
   for(i=0;i<size2;i++){
   	 order = binarySearch(number,0,size-1,number2[i]);
   	 printf("%d\n",order);
   }
	
   return 0;
}
