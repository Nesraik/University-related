import java.util.Scanner;

class BangunRuang <X extends Number, Y extends Number, Z extends Number>{

     X Length;
     Y Width;
     Z Height;

    BangunRuang(X Length, Y Width, Z Height){
        this.Length = Length;
        this.Width = Width;
        this.Height = Height;
    }

    public T getLength(){
        return this.Length;
    }

    public T getWidth(){
        return this.Width;
    }

    public T getHeight(){
        return this.Height;
    }

    public double getVolume(){
        double Volume = this.Height.doubleValue() * this.Length.doubleValue() *  this.Width.doubleValue();
        return Volume;
    }

}

public class generic {
    
    public static void main (String [] args){
        Scanner input = new Scanner(System.in);

        System.out.println("Enter Length(Int): ");
        Integer Length = input.nextInt();
        System.out.println("Enter Width(Float): ");
        Float Width= input.nextFloat();
        System.out.println("Enter Height(Double): ");
        Double Height= input.nextDouble();

        BangunRuang<Integer,Float,Double> BangunRuangs =  new BangunRuang<>(Length, Width, Height);

        System.out.println(BangunRuangs.getVolume());
        input.close();
    }
}
