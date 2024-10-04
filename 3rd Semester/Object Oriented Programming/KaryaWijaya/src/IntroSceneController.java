import java.io.FileWriter;
import java.io.IOException;
import org.json.JSONObject;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import javafx.scene.Node; 

public class IntroSceneController{
    private Stage stage;
    private Scene scene;
    private Parent root;

    @FXML
    private TextField usernametextfield;

    @FXML
    void nextButton(ActionEvent event) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("DashboardScene.fxml"));
        root = loader.load();
        DashboardSceneController Dashboard = loader.getController();
        String username = usernametextfield.getText();
        Dashboard.setUserNameLabel(username);
        
        Dashboard.setCurrentTimeLabel(java.time.format.DateTimeFormatter.ofPattern("EEEE dd MMMM yyyy").format(java.time.LocalDate.now()));
        switchDashboard(event);
        writeJsonFile(username);
        
    }

    void writeJsonFile(String username){
        JSONObject Jobj = new JSONObject();
        Jobj.put("User", username);

        try(FileWriter file = new FileWriter("user.json")){
            file.write(Jobj.toString());
            file.flush();
        }catch(IOException e){
            e.printStackTrace();
        }
       
    }

    void switchDashboard(ActionEvent event) throws IOException {
        stage = (Stage)((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setResizable(false);
        stage.setScene(scene);
        stage.show();
        
    }
    

}