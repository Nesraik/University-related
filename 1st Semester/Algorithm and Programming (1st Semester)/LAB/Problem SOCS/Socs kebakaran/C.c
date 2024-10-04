#include <stdio.h>
int bilmin = 100000;
char papancatur[9][9];
int counter = 0;
int x;
int y;
void z(char papancatur[][9]){
    for(int i=1; i<=8; i++){
        printf("%s", papancatur[i]);
        printf("\n");
    }
    printf("\n");
}
void calculate(char papancatur[][9], int x, int y){
    if(x < 0 || y < 0 || papancatur[x][y] == 'V' || y >= 8 || x >= 8){
        return;
 	}else if(papancatur[x][y] == 'E'){
        if(bilmin > counter){
            bilmin = counter;
        }
        return;
    }else if(counter >= bilmin){
        return;
    }
    counter++;
    papancatur[x][y] = 'V';
    calculate(papancatur, x + 2, y + 1);
    calculate(papancatur, x + 1, y + 2);
    calculate(papancatur, x - 2, y + 1);
    calculate(papancatur, x - 1, y + 2);
    calculate(papancatur, x + 2, y - 1);
    calculate(papancatur, x + 1, y - 2);
    calculate(papancatur, x - 2, y - 1);
    calculate(papancatur, x - 1, y - 2);
    papancatur[x][y] = ' ';
    counter--;
    return;
}
int main(){
    int kasus;
    scanf("%d",&kasus);
	for(int i = 0; i < kasus; i++){
        bilmin = 100000;
        counter = 0;
        for(int j = 0; j < 8; j++){
            for(int k = 0; k < 8; k++){
                papancatur[j][k] = ' ';
            }
        }
		char baris1[3], baris2[3];
        scanf("%s %s", baris1, baris2);
		papancatur[7 - (baris1[1] - '1')][baris1[0] - 'A'] = 'S';
        papancatur[7 - (baris2[1] - '1')][baris2[0] - 'A'] = 'E';
		x = 7 - (baris1[1] - '1');
        y = baris1[0] - 'A';
        calculate(papancatur, x, y);   
		printf("Case #%d: %d\n", i + 1, bilmin);
    }
    return 0;
}
