import java.io.IOException;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.stage.Stage;

public class DashboardSceneController {

    @FXML
    private Label currentTimeLabel;

    @FXML
    private Label usernameLabel;

    private Stage stage;
    private Scene scene;
    private Parent root;

    void setUserNameLabel(String username){
        usernameLabel.setText(username);
    }

    void setCurrentTimeLabel(String currentTime){
        currentTimeLabel.setText(currentTime);
    }

    @FXML
    void switchMetalScene(ActionEvent event) throws IOException{
        root = FXMLLoader.load(getClass().getResource("MetalScene.fxml"));
        stage = (Stage)((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setResizable(false);
        stage.setScene(scene);
        stage.show();
    }

}
