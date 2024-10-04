class PersegiPanjang{
    private int Panjang;
    private int Lebar;

    PersegiPanjang(int Panjang,int Lebar){
        setPanjang(Panjang);
        setLebar(Lebar);
    }
    public void setPanjang(int Panjang){
        this.Panjang = Panjang;
    }

    public void setLebar(int Lebar){
        this.Lebar = Lebar;
    }

    public int getPanjang(){
        return this.Panjang;
    }

    public int getLebar(){
        return this.Lebar;
    }

    public int getArea(){
        return this.Panjang * this.Lebar;
    }
    public int getPerimeter(){
        return 2*this.Panjang + 2 * this.Lebar;
    }
}

public class No4Quiz {
    public static void main(String [] args){
        PersegiPanjang BangunDatarPertama = new PersegiPanjang(10,5);
        System.out.printf("Panjang sebelum perubahan: %d\n",BangunDatarPertama.getPanjang());
        System.out.printf("Lebar sebelum perubahan: %d\n",BangunDatarPertama.getLebar());
        System.out.printf("Area: %d\n",BangunDatarPertama.getArea());
        System.out.printf("Perimeter: %d\n",BangunDatarPertama.getPerimeter());
        BangunDatarPertama.setPanjang(12);
        BangunDatarPertama.setLebar(10);
        System.out.printf("Panjang setelah perubahan: %d\n",BangunDatarPertama.getPanjang());
        System.out.printf("Lebar setelah perubahan: %d\n",BangunDatarPertama.getLebar());
        System.out.printf("Area: %d\n",BangunDatarPertama.getArea());
        System.out.printf("Perimeter: %d\n",BangunDatarPertama.getPerimeter());
    }
}
