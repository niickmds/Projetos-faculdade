module org.example.ativalunojavafx {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.web;

    requires org.controlsfx.controls;
    requires com.dlsc.formsfx;
    requires net.synedra.validatorfx;
    requires org.kordamp.ikonli.javafx;
    requires org.kordamp.bootstrapfx.core;
    requires eu.hansolo.tilesfx;
    requires com.almasb.fxgl.all;
    requires java.desktop;

    opens org.example.ativalunojavafx to javafx.fxml;
    exports org.example.ativalunojavafx;
    exports org.example.ativalunojavafx.Entidades;
    opens org.example.ativalunojavafx.Entidades to javafx.fxml;
    exports org.example.ativalunojavafx.Cadastros;
    opens org.example.ativalunojavafx.Cadastros to javafx.fxml;
    exports org.example.ativalunojavafx.Entidades.Textos;
    opens org.example.ativalunojavafx.Entidades.Textos to javafx.fxml;
    exports org.example.ativalunojavafx.Arquivos;
    opens org.example.ativalunojavafx.Arquivos to javafx.fxml;
}