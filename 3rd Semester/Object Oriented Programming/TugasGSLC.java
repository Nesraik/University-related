import java.util.ArrayList;
import java.util.Scanner;

class DataEntry{

    String Username;
    String UserPass;
    String UserPhoneNumber;
    DataEntry(String Name, String Password, String PhoneNumber){
        this.Username = Name;
        this.UserPass = Password;
        this.UserPhoneNumber = PhoneNumber;
    }
}  


public class TugasGSLC{
    public static void main (String[] args){
        ArrayList<DataEntry> entryData = new ArrayList<DataEntry>(); 
        Scanner Input = new Scanner(System.in);

        int menu = 0,CurrentData = 0,Order=0;
        while(menu!=4){
            System.out.println("1. Input Data");
            System.out.println("2. Show Data");
            System.out.println("3. Delete Data");
            System.out.println("4. Exit");
            System.out.print("Your Choice: ");


            menu = Input.nextInt();

            switch(menu){

                case 1:
                    String UsernameCheck;
                    String UserPassCheck;
                    String UserPhoneNumberCheck;
                
                    System.out.print("Name: ");
                    Input.nextLine();
                    UsernameCheck = Input.nextLine();
                    System.out.print("Pass: ");
                    UserPassCheck = Input.next();
                    System.out.print("Phone: ");
                    UserPhoneNumberCheck = Input.next();

                    entryData.add(new DataEntry(UsernameCheck,UserPassCheck,UserPhoneNumberCheck));
                    CurrentData = entryData.size();
                    System.out.println("New data is added");
                    break;
                case 2:
                    System.out.println("=====================================================");
                    System.out.println("|No|\t Name|\t Pass|\t Phone");
                    System.out.println("=====================================================");

                    if(CurrentData == 0){
                        System.out.println("\t\t|No data exist|");
                    }else{
                        Order = 1;
                        for (DataEntry ShowEntry : entryData) {
                            System.out.printf("|%2d| %8s| %6s| %s|\n",Order,ShowEntry.Username,ShowEntry.UserPass,ShowEntry.UserPhoneNumber);
                            Order++;
                            System.out.println("=====================================================");
                        }
                    }
                    break;
                case 3:
                    
                    System.out.println("=====================================================");
                    System.out.println("|No|\t Name|\t Pass|\t Phone");
                    System.out.println("=====================================================");
                    
                    if(CurrentData == 0){
                        System.out.println("\t\t|No data exist|");
                    }else{
                        Order = 1;
                        for (DataEntry ShowEntry : entryData) {
                            System.out.printf("|%2d| %8s| %6s| %s|\n",Order,ShowEntry.Username,ShowEntry.UserPass,ShowEntry.UserPhoneNumber);
                            Order++;
                            System.out.println("=====================================================");
                        }
                            
                        System.out.print("Input data number to be deleted: ");
                        int Option = Input.nextInt();
                        entryData.remove(Option-1);
                        CurrentData-=1;
                        System.out.println("Data is removed");

                    }
                    break;  


            }

        }
        Input.close();

    }

}
