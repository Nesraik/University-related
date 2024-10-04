import java.util.Scanner;

public class App {

    public static void cls() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    public static void main(String[] args) throws Exception {
       Scanner Input = new Scanner(System.in);
       int menu = 0;
       int number2 = 0;
       int total = 0;
       while(menu!=7){
           cls();
           System.out.println("Calculator");
           System.out.println("===================");
           System.out.println("Total = "+total);

           if(total==0){
                System.out.println("Input a number: ");
                total = Input.nextInt();
           }

           System.out.println("1. Addition");
           System.out.println("2. Substraction");
           System.out.println("3. Multiplication");
           System.out.println("4. Division");
           System.out.println("5. Modulo");
           System.out.println("6. Reset Input");
           System.out.println("7. Exit");

        menu = Input.nextInt();
        
        cls();
        
        System.out.println("Input number: ");
        number2 = Input.nextInt();

        switch(menu){
            case 1 -> total = number1 
        }



       }
    }
}
