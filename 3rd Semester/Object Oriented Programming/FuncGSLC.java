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


public class FuncGSLC{
    public void insertdata(ArrayList<DataEntry> entryData, Scanner Input){
        //Scanner Input = new Scanner(System.in);
        String UsernameCheck;
        String UserPassCheck;
        String UserPhoneNumberCheck;
    
        System.out.print("Name: ");
        //Input.nextLine();
        UsernameCheck = Input.nextLine();
        System.out.print("Pass: ");
        UserPassCheck = Input.nextLine();
        System.out.print("Phone: ");
        UserPhoneNumberCheck = Input.nextLine();

        entryData.add(new DataEntry(UsernameCheck,UserPassCheck,UserPhoneNumberCheck));
        System.out.println("New data is added");
        //  Input.close();
    } 
    public static void main (String[] args){
        ArrayList<DataEntry> entryData = new ArrayList<DataEntry>(); 
        Scanner Getin = new Scanner(System.in);
        FuncGSLC app = new FuncGSLC();

        int menu = 0,Order=0;
        while(menu!=4){
            System.out.println("1. Input Data");
            System.out.println("2. Show Data");
            System.out.println("3. Delete Data");
            System.out.println("4. Exit");
            System.out.print("Your Choice: ");


            menu = Getin.nextInt();
            Getin.nextLine();

            switch(menu){

                case 1:
                    app.insertdata(entryData, Getin);
                    break;
                case 2:
                    System.out.println("=====================================================");
                    System.out.println("|No|\t Name|\t Pass|\t Phone");
                    System.out.println("=====================================================");

                    if(entryData.size() == 0){
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
                    
                    if(entryData.size()== 0){
                        System.out.println("\t\t|No data exist|");
                    }else{
                        Order = 1;
                        for (DataEntry ShowEntry : entryData) {
                            System.out.printf("|%2d| %8s| %6s| %s|\n",Order,ShowEntry.Username,ShowEntry.UserPass,ShowEntry.UserPhoneNumber);
                            Order++;
                            System.out.println("=====================================================");
                        }
                            
                        System.out.print("Input data number to be deleted: ");
                        int Option = Getin.nextInt();
                        entryData.remove(Option-1);
                        System.out.println("Data is removed");

                    }
                    break;  


            }

        }
        Getin.close();

    }

}
