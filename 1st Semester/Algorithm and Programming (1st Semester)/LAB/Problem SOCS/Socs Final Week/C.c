#include <stdio.h>
void swap(long long *data1, long long *data2) {
    long long temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

int partition(long long arr[], int lowBound, int highBound) {
    long long pivot = arr[highBound];
    int pointer = lowBound - 1;
    
    for (int counter = lowBound; counter < highBound; counter++) {
        if (arr[counter] <= pivot) {
            pointer++;
            swap(&arr[counter], &arr[pointer]);
        }
    }
    swap(&arr[pointer + 1], &arr[highBound]);
    return pointer + 1;
}

void quicksort(long long arr[], int lowBound, int highBound) {
    if (lowBound < highBound) {
        int pivot = partition(arr, lowBound, highBound);

        quicksort(arr, lowBound, pivot - 1);

        quicksort(arr, pivot + 1, highBound);
    }
}

int main(){
    int missions;
    long long Power;

    scanf("%d", &missions);

    long long requirement[missions];

    for (int missionCounter = 0; missionCounter < missions; missionCounter++) {
        scanf("%lld", &requirement[missionCounter]);
    }

    scanf("%lld", &Power);
    
    quicksort(requirement, 0, missions - 1);

    int missionCount = 0;
    for (int counter = 0; counter < missions; counter++) {
        Power -= requirement[counter];

        if (Power < 0) break;

        missionCount++;
    }
    printf("%d\n", missionCount);
    return 0;
}
