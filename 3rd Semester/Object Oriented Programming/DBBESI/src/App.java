import java.util.Scanner;

public class App {

    public static void clearScreen() {  
        System.out.print("\033[H\033[2J");  
        System.out.flush();  
    }
    
    public void insertItem(){
        Storage Storages =  new Storage();
        Scanner input = new Scanner(System.in);
        int menu = 0;
        do
        {
        System.out.println("<Insert Menu>");
        System.out.println("1. Metal");
        System.out.println("2. RoofTile");
        System.out.println("3. Rope");
        System.out.println("4. Tool");
        System.out.println("5. Exit");
        System.out.print(">> ");
        menu = input.nextInt();
        input.nextLine();
        switch(menu){
            case 1:
                String Name,Query;
                double Price;
                int Length;
                int Width;
                int Thickness;

                System.out.println("Enter Name: ");
                Name = input.nextLine();

                System.out.println("Enter Length: ");
                Length = input.nextInt();

                System.out.println("Enter Thickness: ");
                Thickness = input.nextInt();

                System.out.println("Enter Width: ");
                Width = input.nextInt();

                System.out.println("Enter Price: ");
                Price = input.nextDouble();

                Item Metal =  new Item(Price, Name, Length, Width, Thickness);

                Query = Storages.getInsertMetalQuery(Metal.getName(), Metal.getLength(), Metal.getWidth(), Metal.getThickness(), Metal.getPrice());
                Storages.insert(Query);
                break;

            case 2:
                String Colour;

                System.out.println("Enter Name: ");
                Name = input.nextLine();

                System.out.println("Enter Length: ");
                Length = input.nextInt();
                input.nextLine();

                System.out.println("Enter Colour: ");
                Colour = input.nextLine();

                System.out.println("Enter Width: ");
                Width = input.nextInt();
                input.nextLine();

                System.out.println("Enter Price: ");
                Price = input.nextDouble();
                input.nextLine();

                Item RoofTile =  new Item(Price, Name, Length, Width, Colour);

                Query = Storages.getInsertRoofTileQuery(RoofTile.getName(), RoofTile.getLength(), RoofTile.getWidth(), RoofTile.getColor(), RoofTile.getPrice());
                Storages.insert(Query);
                break;
            case 3:
                System.out.println("Enter Name: ");
                Name = input.nextLine();

                System.out.println("Enter Length: ");
                Length = input.nextInt();
                input.nextLine();

                System.out.println("Enter Price: ");
                Price = input.nextDouble();
                input.nextLine();

                Item Rope = new Item(Name, Length, Price);

                Query = Storages.getInsertRopeQuery(Rope.getName(), Rope.getLength(), Rope.getPrice());
                Storages.insert(Query);
                break;

            case 4:
                System.out.println("Enter Name: ");
                Name = input.nextLine();

                System.out.println("Enter Colour: ");
                Colour = input.nextLine();

                System.out.println("Enter Price: ");
                Price = input.nextDouble();
                input.nextLine();

                Item Tool =  new Item(Price, Name, Colour);

                Query = Storages.getInsertToolQuery(Tool.getName(), Tool.getColor(), Tool.getPrice());
                Storages.insert(Query);
                break;

            case 5:
                return;
            }
        }while(menu!=5);
        input.close();
    }
    
    public void displayItem(){
        Scanner input = new Scanner(System.in);
        int menu = 0;
        Storage Storages = new Storage();
        do{
            System.out.println("<Display Menu>");
            System.out.println("1. Metal");
            System.out.println("2. RoofTile");
            System.out.println("3. Tool");
            System.out.println("4. Rope");
            System.out.println("5. Exit");
            System.out.println(">> ");

            menu = input.nextInt();
            input.nextLine();

            switch(menu){
                case 1:
                    Storages.displayMetal();
                    break;
                case 2:
                    Storages.displayRooftile();
                    break;
                case 3:
                    Storages.displayTool();
                    break;
                case 4:
                    Storages.displayRope();
                    break;
                case 5:
                    return;
            }
        }while(menu!=5);

        input.close();
    }
    
    public void updateItem(){
        int menu = 0,menu2 = 0,id=0,ivar;
        String newData, query;
        double dvar;
        Scanner input = new Scanner(System.in);
        Storage Storages = new Storage();
        do{
            System.out.println("<Update Menu>");
            System.out.println("1. Metal");
            System.out.println("2. RoofTile");
            System.out.println("3. Tool");
            System.out.println("4. Rope");
            System.out.println("5. Exit");
            System.out.println(">> ");

            menu = input.nextInt();
            input.nextLine();

            switch(menu){
                case 1:
                    Storages.displayMetal();
                    System.out.println("<Update Metal>");
                    System.out.println("Enter ID: ");
                    id = input.nextInt();
                    input.nextLine();

                    System.out.println("<Column>");
                    System.out.println("1. Name");
                    System.out.println("2. Length");
                    System.out.println("3. Width");
                    System.out.println("4. Thickness");
                    System.out.println("5. Price");
                    System.out.println("6. Exit ");
                    System.out.println(">> ");

                    menu2 = input.nextInt();
                    input.nextLine();

                    switch(menu2){
                        case 1:
                            System.out.println("Enter New Name: ");
                            newData = input.nextLine();

                            query = "UPDATE Metal SET NAME = '"+newData+"' WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        case 2:
                            System.out.println("Enter New Length: ");
                            ivar = input.nextInt();

                            query = "UPDATE Metal SET LENGTH = "+ivar+" WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        case 3:
                            System.out.println("Enter New Width: ");
                            ivar = input.nextInt();

                            query = "UPDATE Metal SET WIDTH = "+ivar+" WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        case 4:
                            System.out.println("Enter New Thickness: ");
                            ivar = input.nextInt();

                            query = "UPDATE Metal SET THICKNESS = "+ivar+" WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        case 5:
                            System.out.println("Enter New Price: ");
                            dvar  = input.nextDouble();

                            query = "UPDATE Metal SET PRICE = "+dvar+" WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        default:
                            break;
                    }
                    break;
                case 2:
                    Storages.displayRooftile();
                    System.out.println("<Update RoofTile>");
                    System.out.println("Enter ID: ");
                    id = input.nextInt();
                    input.nextLine();

                    System.out.println("<Column>");
                    System.out.println("1. Name");
                    System.out.println("2. Length");
                    System.out.println("3. Width");
                    System.out.println("4. Colour");
                    System.out.println("5. Price");
                    System.out.println("6. Exit ");
                    System.out.println(">> ");

                    menu2 = input.nextInt();
                    input.nextLine();

                    switch(menu2){
                        case 1:
                            System.out.println("Enter New Name: ");
                            newData = input.nextLine();

                            query = "UPDATE RoofTile SET NAME = '"+newData+"' WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        case 2:
                            System.out.println("Enter New Length: ");
                            ivar = input.nextInt();

                            query = "UPDATE RoofTile SET LENGTH = "+ivar+" WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        case 3:
                            System.out.println("Enter New Width: ");
                            ivar = input.nextInt();

                            query = "UPDATE RoofTile SET WIDTH = "+ivar+" WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        case 4:
                            System.out.println("Enter New Colour: ");
                            newData = input.nextLine();

                            query = "UPDATE RoofTile SET COLOR = '"+newData+"' WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        case 5:
                            System.out.println("Enter New Price: ");
                            dvar  = input.nextDouble();

                            query = "UPDATE RoofTile SET PRICE = "+dvar+" WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        default:
                            break;
                    }
                    break;
                case 3:
                    Storages.displayTool();
                    System.out.println("<Update Tool>");
                    System.out.println("Enter ID: ");
                    id = input.nextInt();
                    input.nextLine();

                    System.out.println("<Column>");
                    System.out.println("1. Name");
                    System.out.println("2. Colour");
                    System.out.println("3. Price");
                    System.out.println("4. Exit ");
                    System.out.println(">> ");

                    menu2 = input.nextInt();
                    input.nextLine();

                    switch(menu2){
                        case 1:
                            System.out.println("Enter New Name: ");
                            newData = input.nextLine();

                            query = "UPDATE Tool SET NAME = '"+newData+"' WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        case 2:
                            System.out.println("Enter New Colour: ");
                            newData = input.nextLine();

                            query = "UPDATE Tool SET COLOR = '"+newData+"' WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        case 3:
                            System.out.println("Enter New Price: ");
                            dvar  = input.nextDouble();

                            query = "UPDATE Tool SET PRICE = "+dvar+" WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        default:
                            break;
                    }
                    break;
                case 4:
                    Storages.displayRope();
                    System.out.println("<Update Rope>");
                    System.out.println("Enter ID: ");
                    id = input.nextInt();
                    input.nextLine();

                    System.out.println("<Column>");
                    System.out.println("1. Name");
                    System.out.println("2. Length");
                    System.out.println("3. Price");
                    System.out.println("4. Exit ");
                    System.out.println(">> ");

                    menu2 = input.nextInt();
                    input.nextLine();

                    switch(menu2){
                        case 1:
                            System.out.println("Enter New Name: ");
                            newData = input.nextLine();

                            query = "UPDATE Rope SET NAME = '"+newData+"' WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        case 2:
                            System.out.println("Enter New Length: ");
                            ivar = input.nextInt();

                            query = "UPDATE Rope SET LENGTH = "+ivar+" WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        case 3:
                            System.out.println("Enter New Price: ");
                            dvar  = input.nextDouble();

                            query = "UPDATE Rope SET PRICE = "+dvar+" WHERE ID = "+id+";";
                            Storages.update(query);
                            break;
                        default:
                            break;
                    }
                    break;
                case 5:
                    return;
            }
        }while(menu!=5);

        input.close();
    }

    public void deleteItem(){
        int menu = 0,id=0;
        String query;
        Scanner input = new Scanner(System.in);
        Storage Storages = new Storage();
        do{
            System.out.println("<Delete Menu>");
            System.out.println("1. Metal");
            System.out.println("2. RoofTile");
            System.out.println("3. Tool");
            System.out.println("4. Rope");
            System.out.println("5. Exit");
            System.out.println(">> ");

            menu = input.nextInt();
            input.nextLine();

            switch(menu){
                case 1:
                    Storages.displayMetal();
                    System.out.println("<Delete Metal>");
                    System.out.println("Enter ID: ");
                    id = input.nextInt();
                    input.nextLine();

                    query = "DELETE FROM Metal WHERE ID = "+id+";";
                    Storages.delete(query);
                    break;
                case 2:
                    Storages.displayRooftile();
                    System.out.println("<Delete RoofTile>");
                    System.out.println("Enter ID: ");
                    id = input.nextInt();
                    input.nextLine();

                    query = "DELETE FROM RoofTile WHERE ID = "+id+";";
                    Storages.delete(query);
                    break;
                case 3:
                    Storages.displayTool();
                    System.out.println("<Delete Tool>");
                    System.out.println("Enter ID: ");
                    id = input.nextInt();
                    input.nextLine();

                    query = "DELETE FROM Tool WHERE ID = "+id+";";
                    Storages.delete(query);
                    break;
                case 4:
                    Storages.displayRope();
                    System.out.println("<Delete Rope>");
                    System.out.println("Enter ID: ");
                    id = input.nextInt();
                    input.nextLine();

                    query = "DELETE FROM Rope WHERE ID = "+id+";";
                    Storages.delete(query);
                    break;
                case 5:
                    return;
            }
        }while(menu!=5);

        input.close();
    }
    public static void main(String[] args) throws Exception {
        int menu = 0;
        Scanner input = new Scanner(System.in);
        Storage Storages =  new Storage();
        Storages.initDB();
        App app = new App();
        do{
            System.out.println("Toko Besi DB");
            System.out.println("1. Insert Item");
            System.out.println("2. Update Item");
            System.out.println("3. Display Item");
            System.out.println("4. Delete Item");
            System.out.println("5. Exit");
            System.out.print(">> ");

            menu = input.nextInt();
            input.nextLine();
            
            switch(menu){
                case 1:
                    clearScreen();
                    app.insertItem();
                    break;
                case 2:
                    clearScreen();
                    app.updateItem();
                    break;
                case 3:
                    clearScreen();
                    app.displayItem();
                    break;
                case 4:
                    clearScreen();
                    break;
                case 5:
                    default:
                    break;
            }

        }while(menu!=5);
        input.close();
        

    }
}
