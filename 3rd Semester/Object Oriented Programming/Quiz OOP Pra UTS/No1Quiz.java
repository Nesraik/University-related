import java.util.Scanner;

public class No1Quiz{
    public static void main(String[] args) {
        Scanner Input = new Scanner(System.in);
        Matrix FirstMatrix = new Matrix();
        Matrix SecondMatrix = new Matrix();
        for(int i=0;i<FirstMatrix.N;i++){
            for(int j=0;j<FirstMatrix.N;j++){
                FirstMatrix.e[i][j]= Input.nextInt();
            }
        }

        for(int i=0;i<SecondMatrix.N;i++){
            for(int j=0;j<SecondMatrix.N;j++){
                SecondMatrix.e[i][j]= Input.nextInt();
            }
        }

        int [][] hasil = FirstMatrix.jumlahMatrix(SecondMatrix.e);
        System.out.println("Hasil Penjumlahan Matrix");
        for(int i=0;i<FirstMatrix.N;i++){
            for(int j=0;j<FirstMatrix.N;j++){
                System.out.printf("%d ",hasil[i][j]);
            }System.out.println();
        }

        int [][] transposeFirst = FirstMatrix.transpose();
        System.out.println("Transpose of First Matrix");
        for(int i=0;i<FirstMatrix.N;i++){
            for(int j=0;j<FirstMatrix.N;j++){
                System.out.printf("%d ",transposeFirst[i][j]);
            }System.out.println();
        }

        int [][] transposeSecond = SecondMatrix.transpose();
        System.out.println("Transpose of Second Matrix");
        for(int i=0;i<SecondMatrix.N;i++){
            for(int j=0;j<SecondMatrix.N;j++){
                System.out.printf("%d ",transposeSecond[i][j]);
            }System.out.println();
        }

        Input.close();
    }
}