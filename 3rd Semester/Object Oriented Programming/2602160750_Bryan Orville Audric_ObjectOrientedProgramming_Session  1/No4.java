import java.util.Scanner;

public class No4{  
    public static void main(String args[]){  
        Scanner Input = new Scanner(System.in);
        System.out.println("Enter hexadecimal: ");
        String hexadecimal = Input.next();  
        int DecimalNumber=Integer.parseInt(hexadecimal,16);
        System.out.println(DecimalNumber);  
    }
} 