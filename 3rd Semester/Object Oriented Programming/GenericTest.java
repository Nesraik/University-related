import java.util.Scanner;

class BangunRuang <X extends Number, Y extends Number, Z extends Number>{

    private X Length;
    private Y Width;
    private Z Height;

    BangunRuang(X Length, Y Width, Z Height){
        setLength(Length);
        setWidth(Width);
        setHeight(Height);
    }

    public void setLength(X Length){
        this.Length=Length;
    }
    public void setWidth(Y Width){
        this.Width=Width;
    }
    public void setHeight(Z Height){
        this.Height=Height;
    }   

    public Z getHeight(){
        return this.Height;
    }
    public Y getWidth(){
        return this.Width;
    }
    public X getLength(){
        return this.Length;
    }


    public double getVolume(){
        return this.Height.doubleValue() * this.Length.doubleValue() * this.Width.doubleValue();
    }

}

public class GenericTest {
    
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
