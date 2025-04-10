    package org.example.ativalunojavafx.Cadastros;

    import javafx.fxml.FXML;
    import javafx.fxml.FXMLLoader;
    import javafx.geometry.Insets;
    import javafx.scene.Parent;
    import javafx.scene.Scene;
    import javafx.scene.control.*;
    import javafx.scene.layout.VBox;
    import javafx.stage.FileChooser;
    import javafx.stage.Stage;
    import org.example.ativalunojavafx.Entidades.Aluno;
    import org.example.ativalunojavafx.Entidades.Disciplina;
    import org.example.ativalunojavafx.Entidades.Textos.ListaAlunosController;

    import java.io.*;
    import java.util.ArrayList;
    import java.util.List;
    import java.util.Optional;

    public class CadastroAluno {

        @FXML
        private Label welcomeText;
        @FXML
        private TextField nomeField;
        @FXML
        private TextField idadeField;
        @FXML
        private TextField rgField;
        @FXML
        private TextField raField;
        @FXML
        private TextField semestreField;
        @FXML
        private TextArea listaAlunosArea;
        @FXML
        private Button inserirButton;
        @FXML
        private Button removerButton;
        @FXML
        private Button listarButton;
        @FXML
        private Button sairButton;
        @FXML
        private Button removerDisciplinaButton;
        @FXML
        private Button adicionarDisciplineButton;
        @FXML
        private Button buscarButton;
        @FXML
        private Button gravarButton;
        @FXML
        private Button lerButton;
        @FXML
        private VBox cadastroBox;

        private Cadastro cadastro;

        @FXML
        public void initialize() {
            cadastro = new Cadastro();
            welcomeText.setText("Bem vindo ao portal!");
            cadastroBox.getChildren().clear(); // Limpeza do VBox que contém os campos de cadastro

            // Definição de validações para os campos numéricos
            idadeField.setTextFormatter(new TextFormatter<>(change -> {
                if (!change.getControlNewText().matches("\\d*")) {
                    return null;
                }
                return change;
            }));

            rgField.setTextFormatter(new TextFormatter<>(change -> {
                if (!change.getControlNewText().matches("\\d*")) {
                    return null;
                }
                return change;
            }));

            raField.setTextFormatter(new TextFormatter<>(change -> {
                if (!change.getControlNewText().matches("\\d*")) {
                    return null;
                }
                return change;
            }));

            semestreField.setTextFormatter(new TextFormatter<>(change -> {
                if (!change.getControlNewText().matches("\\d*")) {
                    return null;
                }
                return change;
            }));

            // Definição de validação para permitir apenas letras no campo de texto do nome
            nomeField.textProperty().addListener((observable, oldValue, newValue) -> {
                if (!newValue.matches("[\\p{L} ]*")) {
                    nomeField.setText(oldValue);
                }
            });
        }

        @FXML
        public void Inserir() {
            try {
                String nome = nomeField.getText();
                String idadeText = idadeField.getText();
                String rg = rgField.getText();
                String raText = raField.getText();
                String semestreText = semestreField.getText();

                // Verificar se algum dos campos obrigatórios está vazio
                if (nome.isEmpty() || idadeText.isEmpty() || rg.isEmpty() || raText.isEmpty() || semestreText.isEmpty()) {
                    listaAlunosArea.setText("Preencha todos os campos obrigatórios.");
                    return;
                }

                int idade = Integer.parseInt(idadeText);
                int semestre = Integer.parseInt(semestreText);

                // Verificar se há pelo menos uma disciplina adicionada
                if (cadastroBox.getChildren().isEmpty() || cadastroBox.getChildren().size() % 3 != 0) {
                    listaAlunosArea.setText("Nenhuma disciplina adicionada, coloque pelo menos uma.");
                    return;
                }
                // Verificar se o RA já existe na lista de alunos
                if (cadastro.existeAluno(raText)) {
                    listaAlunosArea.setText("RA já inserido, tente novamente.");
                    return;
                }

                // Crie uma lista vazia de disciplinas para o novo aluno
                List<Disciplina> disciplinas = new ArrayList<>();

                // Obtenha os dados da disciplina adicionada
                for (int i = 0; i < cadastroBox.getChildren().size(); i += 3) {
                    if (cadastroBox.getChildren().get(i) instanceof TextField &&
                            cadastroBox.getChildren().get(i + 1) instanceof TextField &&
                            cadastroBox.getChildren().get(i + 2) instanceof TextField) {

                        String nomeDisciplina = ((TextField) cadastroBox.getChildren().get(i)).getText();
                        String codigoDisciplina = ((TextField) cadastroBox.getChildren().get(i + 1)).getText();
                        String notaString = ((TextField) cadastroBox.getChildren().get(i + 2)).getText();

                        // Verificar se algum dos campos da disciplina está vazio
                        if (nomeDisciplina.isEmpty() || codigoDisciplina.isEmpty() || notaString.isEmpty()) {
                            listaAlunosArea.setText("Preencha todos os campos para a disciplina.");
                            return;
                        }

                        double notaDisciplina = Double.parseDouble(notaString);

                        disciplinas.add(new Disciplina(nomeDisciplina, codigoDisciplina, notaDisciplina));
                    }
                }

                // Limpe os campos da disciplina após a coleta dos dados
                cadastroBox.getChildren().clear();

                // Crie um novo aluno com os dados coletados
                Aluno aluno = new Aluno(nome, idade, rg, raText, semestre, disciplinas);

                // Insira o aluno na lista
                cadastro.inserirAluno(aluno);

                // Atualize a área de texto para indicar que o aluno foi inserido com sucesso
                listaAlunosArea.setText("Aluno inserido com sucesso!");

                // Limpe os campos após a inserção
                limparCampos();

            } catch (NumberFormatException e) {
                listaAlunosArea.setText("Erro: Tipo de dado inserido incorreto!");
            }
        }

        @FXML
        public void Remover() {
            if (cadastro.getAlunos().isEmpty()) {
                listaAlunosArea.setText("Nenhum aluno inserido!");
                return;
            }

            TextInputDialog dialog = new TextInputDialog();
            dialog.setTitle("Remover Aluno");
            dialog.setHeaderText(null);
            dialog.setContentText("Digite o RA do aluno a ser removido:");

            Optional<String> result = dialog.showAndWait();
            result.ifPresent(ra -> {
                if (ra.isEmpty()) {
                    listaAlunosArea.setText("RA não fornecido");
                    return;
                }

                boolean alunoExiste = cadastro.existeAluno(ra);
                if (alunoExiste) {
                    cadastro.removerAluno(ra);
                    listaAlunosArea.setText("Aluno removido com sucesso!");
                } else {
                    listaAlunosArea.setText("Aluno com o RA fornecido não encontrado!");
                }
            });
        }

        @FXML
        public void Listar() {
            if (cadastro.getAlunos().isEmpty()) {
                listaAlunosArea.setText("Nenhum aluno inserido!");
                return;
            }

            FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/ativalunojavafx/ver-lista.fxml"));
            try {
                Parent root = loader.load();
                ListaAlunosController listaAlunosController = loader.getController();
                listaAlunosController.setAlunos(cadastro.getAlunos());

                Stage stage = new Stage();
                stage.setTitle("Lista de Alunos");
                stage.setScene(new Scene(root));
                stage.show();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        @FXML
        public void Sair() {
            Stage stage = (Stage) sairButton.getScene().getWindow();
            stage.close();
        }

        @FXML
        public void AdicionarDisciplina() {
            // Criar campos de texto para nome, código e nota da disciplina
            TextField nomeDisciplinaField = new TextField();
            nomeDisciplinaField.setPromptText("Nome da disciplina");

            TextField codigoDisciplinaField = new TextField();
            codigoDisciplinaField.setPromptText("Código da disciplina");

            TextField notaDisciplinaField = new TextField();
            notaDisciplinaField.setPromptText("Nota da disciplina");

            // Definir validação para permitir apenas letras no campo de texto do nome da disciplina
            nomeDisciplinaField.textProperty().addListener((observable, oldValue, newValue) -> {
                if (!newValue.matches("\\p{L}*")) {
                    nomeDisciplinaField.setText(oldValue);
                }
            });

            // Definir validação para permitir apenas letras no campo de texto do código da disciplina
            codigoDisciplinaField.textProperty().addListener((observable, oldValue, newValue) -> {
                if (!newValue.matches("\\p{L}*")) {
                    codigoDisciplinaField.setText(oldValue);
                }
            });

            // Definir validação para permitir apenas números no campo de texto da nota da disciplina
            notaDisciplinaField.setTextFormatter(new TextFormatter<>(change -> {
                if (!change.getControlNewText().matches("\\d*\\.?\\d*")) {
                    return null;
                }
                return change;
            }));

            // Adicionar os campos de texto ao VBox
            cadastroBox.getChildren().addAll(nomeDisciplinaField, codigoDisciplinaField, notaDisciplinaField);

            // Definir margens para os campos de texto
            VBox.setMargin(nomeDisciplinaField, new Insets(5));
            VBox.setMargin(codigoDisciplinaField, new Insets(5));
            VBox.setMargin(notaDisciplinaField, new Insets(5));
        }

        @FXML
        public void RemoverDisciplina() {
            // Verifica se há disciplinas adicionadas
            if (cadastroBox.getChildren().isEmpty()) {
                listaAlunosArea.setText("Nenhuma disciplina adicionada!");
                return;
            }

            // Remove os últimos três campos de disciplina adicionados
            cadastroBox.getChildren().remove(cadastroBox.getChildren().size() - 1);
            cadastroBox.getChildren().remove(cadastroBox.getChildren().size() - 1);
            cadastroBox.getChildren().remove(cadastroBox.getChildren().size() - 1);
        }

        @FXML
        public void Buscar() {
            // Verifica se há alunos inseridos na lista
            if (cadastro.getAlunos().isEmpty()) {
                listaAlunosArea.setText("Nenhum aluno inserido");
                return;
            }

            // Cria um diálogo de entrada de texto para obter o RA do aluno a ser buscado
            TextInputDialog dialog = new TextInputDialog();
            dialog.setTitle("Buscar Aluno");
            dialog.setHeaderText(null);
            dialog.setContentText("Digite o RA do aluno a ser buscado:");

            // Exibe o diálogo e processa a entrada do usuário
            Optional<String> result = dialog.showAndWait();
            result.ifPresent(ra -> {
                // Busca o aluno com o RA fornecido na lista de alunos
                Aluno aluno = cadastro.buscarAluno(ra);
                if (aluno != null) {
                    listaAlunosArea.setText("Aluno encontrado: \n" + aluno);
                } else {
                    listaAlunosArea.setText("Aluno com o RA fornecido não encontrado!");
                }
            });
        }

        @FXML
        public void Gravar() {
            // Cria um seletor de arquivo para salvar a lista de alunos em um arquivo de texto
            FileChooser fileChooser = new FileChooser();
            fileChooser.setTitle("Salvar Lista de Alunos");
            fileChooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("Arquivo Texto", "*.txt"));
            File file = fileChooser.showSaveDialog(gravarButton.getScene().getWindow());

            // Se um arquivo foi selecionado
            if (file != null) {
                try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
                    // Escreve os dados dos alunos e suas disciplinas no arquivo
                    for (Aluno aluno : cadastro.getAlunos()) {
                        writer.write("Aluno");
                        writer.newLine();
                        writer.write(aluno.getNome());
                        writer.newLine();
                        writer.write(String.valueOf(aluno.getIdade()));
                        writer.newLine();
                        writer.write(aluno.getRg());
                        writer.newLine();
                        writer.write(aluno.getRa());
                        writer.newLine();
                        writer.write(String.valueOf(aluno.getSemestre()));
                        writer.newLine();
                        for (Disciplina disciplina : aluno.getDisciplinas()) {
                            writer.write("Disciplina");
                            writer.newLine();
                            writer.write(disciplina.getNome());
                            writer.newLine();
                            writer.write(disciplina.getCodigoDisciplina());
                            writer.newLine();
                            writer.write(String.valueOf(disciplina.getNota()));
                            writer.newLine();
                        }
                        writer.write("Fim do Aluno");
                        writer.newLine();
                    }
                    listaAlunosArea.setText("Lista de alunos salva com sucesso!");
                } catch (IOException e) {
                    listaAlunosArea.setText("Erro ao salvar a lista de alunos: " + e.getMessage());
                    e.printStackTrace();
                }
            }
        }

        @FXML
        public void Ler() {
            // Cria um seletor de arquivo para abrir a lista de alunos a partir de um arquivo de texto
            FileChooser fileChooser = new FileChooser();
            fileChooser.setTitle("Abrir Lista de Alunos");
            fileChooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("Arquivo Texto", "*.txt"));
            File file = fileChooser.showOpenDialog(lerButton.getScene().getWindow());

            // Se um arquivo foi selecionado
            if (file != null) {
                // Se o arquivo selecionado é um arquivo de texto
                if (file.getName().endsWith(".txt")) {
                    abrirArquivoNoBlocoDeNotas(file);
                } else {
                    listaAlunosArea.setText("Erro: Por favor, selecione um arquivo de texto (.txt).");
                }
            }
        }

        private void abrirArquivoNoBlocoDeNotas(File file) {
            try {
                // Usa Runtime para abrir o arquivo no bloco de notas padrão
                Runtime.getRuntime().exec("notepad.exe " + file.getAbsolutePath());
            } catch (IOException e) {
                e.printStackTrace();
                listaAlunosArea.setText("Erro ao abrir o arquivo: " + e.getMessage());
            }
        }

        private void limparCampos() {
            // Limpa os campos de entrada de texto
            nomeField.clear();
            idadeField.clear();
            rgField.clear();
            raField.clear();
            semestreField.clear();
        }

    }
