public class Matrix {
    final int N = 2;
    int [][] e = new int[N][N];

    public int [][] jumlahMatrix(int [][] a){
        int [][] hasil = new int[N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                hasil[i][j] = e[i][j] + a[i][j];
            }
        }
        return hasil;
    }
    public int [][] transpose(){
        int [][] Transposed = new int[N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                Transposed[i][j] = e[j][i];
            }
        }
        return Transposed;
    }
}
