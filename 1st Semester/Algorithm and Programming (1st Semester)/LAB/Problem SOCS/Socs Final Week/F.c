#include <stdio.h>

char Area[101][101];

int komodo,
    row = -1, col = -1;

void House(int posX, int posY) {
    if (Area[posX][posY] == 'K') komodo++;

    if (Area[posX][posY] == 'S' || Area[posX][posY] == ' ' || posX < 0
        || posY < 0 || posX >= row || posY >= col) return;
    else Area[posX][posY] = 'S';

    House(posX + 1, posY);
	House(posX - 1, posY);
	House(posX, posY + 1);
	House(posX, posY - 1);
}

int main() {
    int Caselimit;

    scanf("%d", &Caselimit);

    for (int Casenumber = 1; Casenumber <= Caselimit; Casenumber++) {
        scanf("%d %d", &row, &col);

        for (int rowCounter = 0; rowCounter < row; rowCounter++) {
            scanf("%s", Area[rowCounter]);
        }

        int HousePosition[2] = {-1};

        for (int rowCounter = 0; rowCounter < row; rowCounter++) {
            for (int colCounter = 0; colCounter < col; colCounter++) {
                if (Area[rowCounter][colCounter] == 'H'){
                    HousePosition[0] = rowCounter;
                    HousePosition[1] = colCounter;
                }
            }
        }
        komodo = 0;

        if (HousePosition[0] != -1 && HousePosition[1] != -1) House(HousePosition[0], HousePosition[1]);
        
        printf("Case #%d: %d\n", Casenumber, komodo);

        for (int rowCounter = 0; rowCounter < row; rowCounter++) {
            for (int colCounter = 0; colCounter < col; colCounter++){
                Area[rowCounter][colCounter] = ' ';
            }
        }
    }
    return 0;
}
