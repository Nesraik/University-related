#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("./testdata.in", "r");
    int Caselimit;

    fscanf(file, "%d\r\n", &Caselimit);

    for (int Casenumber = 1; Casenumber <= Caselimit; Casenumber++) {
        int time, durationMin, durationMax;
        fscanf(file, "%d %d %d\r\n", &time, &durationMin, &durationMax);

        char biner[time + 1];
        fscanf(file, "%s\r\n", biner);

        int mainindex = 0,
            lightningCounter = 0;
        while (biner[mainindex] != '\0') {
            int oneCounter = 0;
            if (biner[mainindex] == '1') {
                oneCounter++;
                int secondindex = mainindex + 1;
                while (biner[secondindex] != '\0') {
                    if (biner[secondindex] == '1') oneCounter++;
                    else break;
                    secondindex++;
                }
                if (oneCounter >= durationMin && oneCounter <= durationMax) {
                    lightningCounter++;
                }
                mainindex = secondindex--;
            }
            mainindex++;
        }
        printf("Case #%d: %d\n", Casenumber, lightningCounter);
    }
    return 0;
}
