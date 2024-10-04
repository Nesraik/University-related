import java.util.Scanner;

class No2 {
    static void check(char character){
      if ((character >= '0' & character <= '9') || (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')){
        System.out.println(character +" is alphanumeric");
      }else{
        System.out.println(character +" is not alphanumeric");
      }
    }
    public static void main(String args[] ) {
        Scanner Input = new Scanner(System.in);
        char Charactertest;
        Charactertest = Input.next().charAt(0);
        check(Charactertest);
        Input.close(); 
    }
}