class No11{  
    public static void main(String args[]){  
        //Output is 65
        char c = 'A';
        int i = (int)c;
        System.out.println(i);

        //Output is 1000
        float f = 1000.34F;
        int i = (int)f;
        System.out.println(i);

        //Output is 1000
        double d = 1000.34;
        int i = (int)d;
        System.out.println(i);

        //Output is 'a'
        int i = 97;
        char c = (char)i;
        System.out.println(c);
    }
} 