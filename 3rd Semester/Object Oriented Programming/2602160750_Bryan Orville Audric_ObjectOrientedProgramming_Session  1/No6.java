
class No6 {
    public static void main(String args[] ) {
        //Contains
        String Stringtest = "OOP";
        System.out.println("Contains");
        System.out.println("==================");

        System.out.println(Stringtest.contains("O"));//Return True
        System.out.println(Stringtest.contains("H"));//Return False
        System.out.println("==================");
        
        //Concat
        String FirstString = "Binus";
        String SecondString = " University";
        System.out.println("Concat");
        System.out.println("==================");
        System.out.println(FirstString.concat(SecondString));
        System.out.println("==================");

        //Compare to
        String String1 = "Binus";
        String String2 = "Binus";
        System.out.println("Compare to");
        System.out.println("==================");
        System.out.println(String1.compareTo(String2));//Return 0 since Both strings are equal
        System.out.println("==================");

        //Format
        String Word = "Food";
        String Sentence = String.format("I eat %s", Word);
        System.out.println("Format");
        System.out.println("==================");
        System.out.println(Sentence);
        System.out.println("==================");

        //charAt
        String Words = "Binus";
        System.out.println("charAt");
        System.out.println("==================");
        System.out.println(Words.charAt(0));
        System.out.println("==================");

        //Replace
        String animal = "Duck";
        System.out.println("Replace");
        System.out.println("==================");
        System.out.println(animal.replace("D", "Y"));
        System.out.println("==================");

        //Substring
        String FullString = "Binus University";
        System.out.println("Substring");
        System.out.println("==================");
        System.out.println(FullString.substring(0, 5));
        System.out.println("==================");

        //Trim
        String WordWithSpace = "    Binus University   ";
        System.out.println("trim");
        System.out.println("==================");
        System.out.println(WordWithSpace.trim());
        System.out.println("==================");

        //toCharArray
        String MyString = "Binus";
        char[] MyArray = MyString.toCharArray();
        System.out.println("toCharArray");
        System.out.println("==================");
        System.out.println(MyArray);
        System.out.println("==================");

        //Split
        String TwoWord = "Binus University";
        String[] arrayofString = TwoWord.split(" ",2);
        System.out.println("Split");
        System.out.println("==================");
        for(int i=0;i<2;i++){
            System.out.println(arrayofString[i]);
        }
        System.out.println("==================");

        //toLowerCase
        System.out.println("toLowercase");
        System.out.println("==================");
        System.out.println("Binus University".toLowerCase());
        System.out.println("==================");

        //toUpperCase
        System.out.println("toUpperCase");
        System.out.println("==================");
        System.out.println("binus university".toUpperCase());
        
    }
}