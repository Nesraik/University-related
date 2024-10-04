import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;



public class Storage implements DBMethods{
    int Length;
    int Width;
    int Thickness;
    String Color;
    double Price;
    String Name;
    static final String DB_URL = "jdbc:mysql://localhost:3306/";
    static final String CreatedDB_URL = "jdbc:mysql://localhost:3306/TokoBesi";
    static final String USERNAME = "root";
    static final String PASS = "";

    public void initDB(){
        try(Connection Connect = DriverManager.getConnection(CreatedDB_URL, USERNAME, PASS);
        ){

        }catch(SQLException e){
            try(Connection Connect = DriverManager.getConnection(DB_URL, USERNAME, PASS);
                Statement stmt = Connect.createStatement();)
            {
                String queryString = "CREATE DATABASE TokoBesi";
                stmt.executeUpdate(queryString);
                System.out.println("Database Created");
                initMetalTable();
                initRoofTileTable();
                initRopeTable();
                initToolTable();

            }catch(SQLException F){
                F.printStackTrace();
            }
        }
    }

    public void initMetalTable(){
        try(Connection Connect = DriverManager.getConnection(CreatedDB_URL, USERNAME, PASS);
        ){

            String queryString = "CREATE TABLE Metal("+
            "ID INT PRIMARY KEY NOT NULL AUTO_INCREMENT,"+
            "NAME VARCHAR (255) NOT NULL,"+
            "LENGTH INT NOT NULL,"+
            "WIDTH INT NOT NULL,"+
            "THICKNESS INT NOT NULL,"+
            "PRICE DOUBLE NOT NULL);";
            PreparedStatement stmt = Connect.prepareStatement(queryString);
            stmt.executeUpdate();

        }catch(SQLException e){
            e.printStackTrace();
        }
    }

    public void initRopeTable(){
        try(Connection Connect = DriverManager.getConnection(CreatedDB_URL, USERNAME, PASS);){

            String queryString = "CREATE TABLE Rope ("+
            "ID INT PRIMARY KEY NOT NULL AUTO_INCREMENT,"+
            "NAME VARCHAR (255) NOT NULL,"+
            "LENGTH INT NOT NULL,"+
            "PRICE DOUBLE NOT NULL);";
            PreparedStatement stmt = Connect.prepareStatement(queryString);
            stmt.executeUpdate();

        }catch(SQLException e){
            e.printStackTrace();
        }
    }

    public void initToolTable(){
        try(Connection Connect = DriverManager.getConnection(CreatedDB_URL, USERNAME, PASS);){

            String queryString = "CREATE TABLE Tool ("+
            "ID INT PRIMARY KEY NOT NULL AUTO_INCREMENT,"+
            "NAME VARCHAR (255) NOT NULL,"+
            "COLOR VARCHAR (255) NOT NULL,"+
            "PRICE DOUBLE NOT NULL);";
            PreparedStatement stmt = Connect.prepareStatement(queryString);
            stmt.executeUpdate(queryString);

        }catch(SQLException e){
            e.printStackTrace();
        }
    }

    public void initRoofTileTable(){
        try(Connection Connect = DriverManager.getConnection(CreatedDB_URL, USERNAME, PASS);){

            String queryString = "CREATE TABLE RoofTile ("+
            "ID INT PRIMARY KEY NOT NULL AUTO_INCREMENT,"+
            "NAME VARCHAR (255) NOT NULL,"+
            "LENGTH INT NOT NULL,"+
            "WIDTH INT NOT NULL,"+
            "COLOR VARCHAR (255) NOT NULL,"+
            "PRICE DOUBLE NOT NULL);";
            PreparedStatement stmt = Connect.prepareStatement(queryString);
            stmt.executeUpdate(queryString);

        }catch(SQLException e){
            e.printStackTrace();
        }
    }
    public String getInsertMetalQuery(String Name, int Length, int Width, int Thickness, double Price){
        String Query = "INSERT INTO Metal (NAME,LENGTH,WIDTH,THICKNESS,PRICE)"+
        "VALUES('"+Name+"',"+String.valueOf(Length)+","+String.valueOf(Width)+","+String.valueOf(Thickness)+
        ","+String.valueOf(Price)+");";

        return Query;
    }

    public String getInsertRoofTileQuery(String Name, int Length, int Width, String Colour, double Price){
        String Query = "INSERT INTO RoofTile (NAME,LENGTH,WIDTH,COLOR,PRICE)"+
        "VALUES('"+Name+"',"+String.valueOf(Length)+","+String.valueOf(Width)+",'"+Colour+
        "',"+String.valueOf(Price)+");";

        return Query;
    }
    public String getInsertRopeQuery(String Name, int Length, double Price){
        String Query = "INSERT INTO Rope (NAME,LENGTH,PRICE)"+
        "VALUES('"+Name+"',"+String.valueOf(Length)+","+String.valueOf(Price)+");";

        return Query;
    }


    public String getInsertToolQuery(String Name, String Colour, double Price){
        String Query = "INSERT INTO Tool (NAME,COLOR,PRICE)"+
        "VALUES('"+Name+"','"+Colour+"',"+String.valueOf(Price)+");";

        return Query;
    }
    @Override
    public <T> void insert(T queryString){
        try(Connection Connect = DriverManager.getConnection(CreatedDB_URL, USERNAME, PASS);){

            PreparedStatement stmt = Connect.prepareStatement((String)queryString);
            stmt.executeUpdate();

        }catch(SQLException e){
            e.printStackTrace();
        }
    }

    public void displayMetal(){
        int count =0;
        try(Connection Connect = DriverManager.getConnection(CreatedDB_URL, USERNAME, PASS);){
            PreparedStatement stmt = Connect.prepareStatement("SELECT * FROM Metal");
            ResultSet rs =  stmt.executeQuery();

            while(rs.next()){
                System.out.println(rs.getInt("ID")+" - "+
                rs.getString("NAME")+ " - "+rs.getInt("LENGTH")+" - "+rs.getInt("WIDTH")+" - "+ 
                rs.getInt("THICKNESS")+" - "+ rs.getDouble("PRICE"));
                count++;
            }
            if(count==0){
                System.out.println("There is no data");
            }

        }catch(SQLException e){
            e.printStackTrace();
        }
    }

    public void displayRooftile(){
        int count =0;
        try(Connection Connect = DriverManager.getConnection(CreatedDB_URL, USERNAME, PASS);){
            PreparedStatement stmt = Connect.prepareStatement("SELECT * FROM RoofTile");
            ResultSet rs =  stmt.executeQuery();
            while(rs.next()){
                System.out.println(rs.getInt("ID")+" - "+
                rs.getString("NAME")+ " - "+rs.getInt("LENGTH")+" - "+rs.getInt("WIDTH")+" - "+ 
                rs.getString("COLOR")+" - "+ rs.getDouble("PRICE"));
                count++;
            }
            if (count==0) {
                System.out.println("There is no data");
            }
            
        }
        catch(SQLException e){
            e.printStackTrace();
        }
    }

    public void displayTool(){
        int count =0;
        try(Connection Connect = DriverManager.getConnection(CreatedDB_URL, USERNAME, PASS);){
            PreparedStatement stmt = Connect.prepareStatement("SELECT * FROM Tool");
            ResultSet rs =  stmt.executeQuery();
            
            while(rs.next()){
                System.out.println(rs.getInt("ID")+" - "+
                rs.getString("NAME")+ " - "+ 
                rs.getString("COLOR")+" - "+ rs.getDouble("PRICE"));
                count++;
            }
            if(count==0){
                System.out.println("There is no data");
            }  
        }catch(SQLException e){
            e.printStackTrace();
        }
    }
    
    public void displayRope(){
        int count =0;
        try(Connection Connect = DriverManager.getConnection(CreatedDB_URL, USERNAME, PASS);){
            PreparedStatement stmt = Connect.prepareStatement("SELECT * FROM Rope");
            ResultSet rs =  stmt.executeQuery();
            while(rs.next()){
                System.out.println(rs.getInt("ID")+" - "+
                rs.getString("NAME")+ " - "+rs.getInt("LENGTH")+" - "+ rs.getDouble("PRICE"));
                count++;
            }
            if(count==0){
                System.out.println("There is no data");
            }
                
        }catch(SQLException e){
            e.printStackTrace();
        }
    
    }


    @Override
    public void update(String query) {
        try(Connection Connect = DriverManager.getConnection(CreatedDB_URL, USERNAME, PASS);){
            PreparedStatement stmt = Connect.prepareStatement(query);
            stmt.executeUpdate();

        }catch(SQLException e){
            e.printStackTrace();
        }
    }

    @Override
    public void delete(String query) {
        
        try(Connection Connect = DriverManager.getConnection(CreatedDB_URL, USERNAME, PASS);){
            PreparedStatement stmt = Connect.prepareStatement(query);
            stmt.executeUpdate();
        }catch(SQLException e){
            e.printStackTrace();
        }
    }
}