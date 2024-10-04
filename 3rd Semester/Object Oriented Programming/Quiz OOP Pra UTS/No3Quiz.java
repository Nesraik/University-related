abstract class Human{
    String Name;
    int Age;
    Human(String Name, int Age){
        this.Name = Name;
        this.Age = Age;
    }

    public void greeting(){
        System.out.printf("My name is %s and my age is %d",this.Name,this.Age);
    }
}

class Binusian extends Human{
    String BinusianID;
    Binusian(String Name, int Age, String BinusianID){
        super(Name, Age);
        this.BinusianID = BinusianID;
    }
    @Override
    public void greeting(){
        System.out.printf("My name is %s aged %d years old and my BinusianID is %s",Name,Age,this.BinusianID);
    }
}


public class No3Quiz {
    public static void main(String[] args) {
        Binusian Davin = new Binusian("Davin", 19, "2601231235");
        Davin.greeting();
    }
}
