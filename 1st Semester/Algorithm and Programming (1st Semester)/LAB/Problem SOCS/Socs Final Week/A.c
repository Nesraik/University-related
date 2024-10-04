#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("./testdata.in", "r");

    int Caselimit;
    fscanf(file, "%d\r\n", &Caselimit);

    for (int Casenumber = 1; Casenumber <= Caselimit; Casenumber++) {
        char str[101];

        int isVisited[26];
        memset(isVisited, 0, sizeof(isVisited));
        fscanf(file, "%s\r\n", str);

        int Count;

        fscanf(file, "%d\r\n", &Count);
        char fromChar, toChar;

        for (int Input = 0; Input < Count; Input++) {
            fscanf(file, "%c %c\r\n", &fromChar, &toChar);

            if (!isVisited[fromChar - 'A']) {
                isVisited[fromChar - 'A'] = 1;
                for (int counter = 0; counter < strlen(str); counter++) {
                    if (str[counter] == fromChar) str[counter] = toChar;
                }
            }
        }

        int charCounter[26] = {0};

        for (int counter = 0; counter < strlen(str); counter++) charCounter[str[counter] - 'A']++;

        for (int output = 0; output < 26; output++) {
            if (charCounter[output]) {
                printf("%c %d\n", 'A' + output, charCounter[output]);
            }
        }
    }

    fclose(file);
    
    return 0;
}
