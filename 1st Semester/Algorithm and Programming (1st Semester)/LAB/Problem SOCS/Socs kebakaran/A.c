#include <stdio.h>
void jumlah(int baris[],int x,int y){
    if(2 * y <= x){
        baris[2 * y] += baris[y];
        jumlah(baris,x,y * 2);
    }
    if(2 * y + 1 <= x){
        baris[2 * y + 1] +=baris[y];
        jumlah(baris,x, y * 2 + 1);
    }
    if(2 * y > x && 2 * y + 1 > x){
        printf("%d\n",baris[y]);
    }
}
int main(){
    int kasus;
    scanf("%d", &kasus);
    for(int i = 0; i < kasus;i++){
        int N;
        scanf("%d", &N);
        int baris[N];
		for(int i = 1; i <= N; i++){
            scanf("%d", &baris[i]);
        }
		printf("Case #%d:\n", i + 1);
        jumlah(baris,N, 1);
    }
    return 0;
}
