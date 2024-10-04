#include <stdio.h>

void quicksort(int number[],int first,int last){
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
    int Caselimit;
    scanf("%d", &Caselimit);

    for (int Casenumber = 1; Casenumber <= Caselimit; Casenumber++) {
        int question, time;
        scanf("%d %d", &question, &time);

        int question_time[question];
        for (int questionCounter = 0; questionCounter < question; questionCounter++) {
            scanf("%d", &question_time[questionCounter]);
        }

        quicksort(question_time, 0, question - 1);

        int minPoint = 0, maxPoint = 0,
            mintime = time, maxtime = time,
            i = question - 1;

        while (i >= 0) {
            mintime -= question_time[i];
            maxtime -= question_time[(question - 1) - i--];

            if (mintime >= 0) minPoint++;
            if (maxtime >= 0) maxPoint++;
        }
        printf("Case #%d: %d %d\n", Casenumber, minPoint, maxPoint);
    }
    return 0;
}
