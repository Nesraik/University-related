import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;

public class App extends Application {
    public static void main(String[] args) throws Exception {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root;
        
        if(!new java.io.File("user.json").exists()){
            root = FXMLLoader.load(getClass().getResource("IntroScene.fxml"));
        }else{
            FXMLLoader loader = new FXMLLoader(getClass().getResource("DashboardScene.fxml"));
            root = loader.load();
            DashboardSceneController Dashboard = loader.getController();
            Dashboard.setCurrentTimeLabel(java.time.format.DateTimeFormatter.ofPattern("EEEE dd MMMM yyyy").format(java.time.LocalDate.now()));
            java.util.Scanner scanner = new java.util.Scanner(new java.io.File("user.json"));
            String fileContent = scanner.useDelimiter("\\Z").next();
            scanner.close();
            Dashboard.setUserNameLabel(new org.json.JSONObject(fileContent).getString("User"));
        }
        Scene scene = new Scene(root);
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.setTitle("Karya Wijaya");
        primaryStage.getIcons().add(new Image(getClass().getResourceAsStream("icon.png")));
        primaryStage.show();
    }
}
