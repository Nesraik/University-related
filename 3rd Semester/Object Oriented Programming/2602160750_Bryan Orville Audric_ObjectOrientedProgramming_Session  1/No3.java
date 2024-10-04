import java.util.Scanner;

class No3 {
    static void check(Character character){
      if (Character.isUpperCase(character)){
        System.out.println(character +" is UpperCase");
      }else{
        System.out.println(character +" is LowerCase");
      }
    }
    public static void main(String args[] ) {
        Scanner Input = new Scanner(System.in);
        char Charactertest;
        System.out.print("Enter a Character: ");
        Charactertest = Input.next().charAt(0);
        check(Charactertest);
        Input.close(); 
    }
}