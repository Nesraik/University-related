abstract class Property{
    private int Length;
    private int Width;
    private int Thickness;
    private String Color;
    
    Property(int Length, int Width, int Thickness){
        setLength(Length);
        setWidth(Width);
        setThickness(Thickness);
    }

    Property(int Length, int Width, String Color){
        setLength(Length);
        setWidth(Width);
        setColor(Color);
    }

    Property(int Length){
        setLength(Length);
    }
     
    Property(String Color){
        setColor(Color);
    }
    public void setLength(int Length){
        this.Length=Length;
    }
    public void setWidth(int Width){
        this.Width=Width;
    }
    public void setThickness(int Thickness){
        this.Thickness=Thickness;
    }
    public void setColor(String Color){
        this.Color=Color;
    }
    public int getLength(){
        return this.Length;
    }
    public int getWidth(){
        return this.Width;
    }
    public int getThickness(){
        return this.Thickness;
    }
    public String getColor(){
        return this.Color;
    }    
}
public class Item extends Property{
    private double Price;
    private String Name;

    //Metal
    Item(double Price, String Name, int Length, int Width, int Thickness){
        super(Length, Width, Thickness);
        setPrice(Price);
        setName(Name);
    }
    
    //RoofTile
    Item(double Price, String Name, int Length,int Width, String Color){
        super(Length, Width, Color);
        setPrice(Price);
        setName(Name);
        
    }

    //Rope
    Item(String Name, int Length, double Price){
        super(Length);
        setName(Name);
        setPrice(Price);
    }
    
    //Tool
    Item(double Price, String Name, String Color){
        super(Color);
        setPrice(Price);
        setName(Name);
    }
    public void setPrice(double Price){
        this.Price=Price;
    }

    public void setName(String Name){
        this.Name=Name;
    }

    public String getName(){
        return this.Name;
    }
    public double getPrice(){
        return this.Price;
    }
  
}

