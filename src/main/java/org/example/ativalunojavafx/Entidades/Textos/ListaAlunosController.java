package org.example.ativalunojavafx.Entidades.Textos;

import javafx.fxml.FXML;
import javafx.scene.control.ListView;
import javafx.scene.control.TextArea;
import org.example.ativalunojavafx.Entidades.Aluno;
import org.example.ativalunojavafx.Entidades.Disciplina;

import java.util.List;

public class ListaAlunosController {
    @FXML
    private ListView<String> listaAlunosListView;
    @FXML
    private TextArea listaAlunosTextArea;

    private List<Aluno> alunos;

    // Instância da classe Texto para acessar os métodos
    private final Texto texto = new Texto("");

    // Instância da classe NomePessoa para acessar os métodos
    private final NomePessoa nomePessoa = new NomePessoa("Nome Completo Aqui");

    public void setAlunos(List<Aluno> alunos) {
        this.alunos = alunos;
        listaAlunosListView.getItems().clear();
        for (Aluno aluno : alunos) {
            listaAlunosListView.getItems().add(aluno.getNome() + " - " + aluno.getRa());
        }
    }

    @FXML
    private void ClicarLista() {
        String selectedItem = listaAlunosListView.getSelectionModel().getSelectedItem();
        if (selectedItem != null) {
            String ra = selectedItem.split(" - ")[1]; // Obtém o RA do item selecionado
            Aluno alunoSelecionado = encontrarAlunoPorRA(ra);
            if (alunoSelecionado != null) {
                String informacoesAluno = formatarInformacoesAluno(alunoSelecionado);
                listaAlunosTextArea.setText(informacoesAluno);
            }
        }
    }

    private Aluno encontrarAlunoPorRA(String ra) {
        for (Aluno aluno : alunos) {
            if (aluno.getRa().equals(ra)) {
                return aluno;
            }
        }
        return null;
    }

    // Método para exibir o nome normalmente
    @FXML
    private void exibirNomeNormal() {
        String nomeSelecionado = listaAlunosListView.getSelectionModel().getSelectedItem();
        if (nomeSelecionado != null) {
            String nome = nomeSelecionado.split(" - ")[0]; // Obtém apenas o nome da pessoa
            listaAlunosTextArea.setText(nome);
        }
    }

    @FXML
    private void inverterTexto() {
        String nomeSelecionado = listaAlunosListView.getSelectionModel().getSelectedItem();
        if (nomeSelecionado != null) {
            String nome = nomeSelecionado.split(" - ")[0];
            texto.setTxt(nome); // Define o texto como o nome da pessoa
            String textoInvertido = texto.inverterTexto();
            listaAlunosTextArea.setText(textoInvertido); // Exibe o texto invertido na área de texto
        }
    }

    // Método para obter o nome bibliográfico
    @FXML
    private void nomeBibliografico() {
        String nomeSelecionado = listaAlunosListView.getSelectionModel().getSelectedItem();
        if (nomeSelecionado != null) {
            String nome = nomeSelecionado.split(" - ")[0];
            String nomeBiblio = nomePessoa.getNomeBiblio(nome);
            listaAlunosTextArea.setText(nomeBiblio);
        }
    }

    private String formatarInformacoesAluno(Aluno aluno) {
        StringBuilder info = new StringBuilder();
        info.append("Nome: ").append(aluno.getNome()).append("\n");
        info.append("Idade: ").append(aluno.getIdade()).append("\n");
        info.append("RG: ").append(aluno.getRg()).append("\n");
        info.append("RA: ").append(aluno.getRa()).append("\n");
        info.append("Semestre: ").append(aluno.getSemestre()).append("\n");
        info.append("Disciplinas:\n");
        for (Disciplina disciplina : aluno.getDisciplinas()) {
            info.append("- Nome: ").append(disciplina.getNome()).append("\n");
            info.append("  Código: ").append(disciplina.getCodigoDisciplina()).append("\n");
            info.append("  Nota: ").append(disciplina.getNota()).append("\n");
        }
        return info.toString();
    }
}
