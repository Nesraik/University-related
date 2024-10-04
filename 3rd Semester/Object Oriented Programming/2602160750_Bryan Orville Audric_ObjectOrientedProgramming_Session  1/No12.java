class No12{  
    public static void main(String args[]){  
        int x = 1;
        System.out.println((true)&& (3>4));//print false
        System.out.println(!(x>0)&& (x>0));//print false
        System.out.println((x!=1)==!(x==1));//print true
        System.out.println((x>=0)|| (x<0));//print true
    }
} 