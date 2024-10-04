#include <stdio.h>
#include <string.h>

void swap(char *data1, char *data2) {
    char temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

void swapStr(char *str1, char *str2) {
    char temp[255];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

void quicksort(char number[],int first,int last){
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

int main() {
    int width, height;
    scanf("%d %d", &width, &height);

    char str[width][height + 1];

    for (int widthCounter = 0; widthCounter < width; widthCounter++) {
        scanf("%s", str[widthCounter]);

        quicksort(str[widthCounter], 0, height - 1);
    }

    for (int widthCounter = 0; widthCounter < width - 1; widthCounter++) {
        for (int eleCounter = 0; eleCounter < width - widthCounter - 1; eleCounter++) {
            if ((str[eleCounter][0] < str[eleCounter + 1][0]) ||
                (str[eleCounter][0] == str[eleCounter + 1][0] &&
                strcmp(str[eleCounter], str[eleCounter + 1]) < 0)) {
                swapStr(str[eleCounter], str[eleCounter + 1]);
            }
        }
    }

    for (int outputCounter = 0; outputCounter < width; outputCounter++) {
        printf("%s\n", str[outputCounter]);
    }
    return 0;
}
