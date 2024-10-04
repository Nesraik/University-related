class Ganjil implements Runnable{

    @Override
    public void run(){
        for(int i=1;i<=50;i+=2){
            System.out.println("Angka Ganjil: "+i);
            try{
                Thread.sleep(1000);
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        }
    }

}

class Genap implements Runnable{
    @Override
    public void run(){
        for(int i=2;i<=50;i+=2){
            System.out.println("Angka Genap: "+i);
            try{
                Thread.sleep(1000);
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        }
    }
}


public class MultiThreadTest {
    
    public static void main(String [] args) throws InterruptedException{
        Ganjil AngkaGanjil = new Ganjil();
        Thread ThreadGanjil = new Thread(AngkaGanjil);

        Genap AngkaGenap = new Genap();
        Thread ThreadGenap = new Thread(AngkaGenap);

        ThreadGanjil.start();
        ThreadGanjil.join(1000);
        ThreadGenap.start();

    }
}
