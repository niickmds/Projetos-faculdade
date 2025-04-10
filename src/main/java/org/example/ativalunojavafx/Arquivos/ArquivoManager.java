package org.example.ativalunojavafx.Arquivos;

import org.example.ativalunojavafx.Entidades.Aluno;

import java.io.*;
import java.util.List;

public class ArquivoManager {

    // Método estático para salvar uma lista de objetos Aluno em um arquivo
    public static void saveToFile(List<Aluno> alunos, File file) {
        // Verifica se a lista de alunos ou o arquivo são nulos e lança uma exceção se forem
        if (alunos == null || file == null) {
            throw new IllegalArgumentException("A lista de alunos e o arquivo não podem ser nulos.");
        }
        // Usa um bloco try-with-resources para garantir que o ObjectOutputStream seja fechado corretamente
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(file))) {
            // Escreve a lista de alunos no arquivo
            oos.writeObject(alunos);
        } catch (IOException e) {
            // Trata exceções de entrada/saída, imprimindo o stack trace
            e.printStackTrace();
        }
    }

    // Método estático para carregar uma lista de objetos Aluno de um arquivo
    public static List<Aluno> loadFromFile(File file) throws IOException, ClassNotFoundException {
        // Verifica se o arquivo é nulo e lança uma exceção se for
        if (file == null) {
            throw new IllegalArgumentException("O arquivo não pode ser nulo.");
        }
        // Usa um bloco try-with-resources para garantir que o ObjectInputStream seja fechado corretamente
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(file))) {
            // Lê a lista de alunos do arquivo e a retorna
            return (List<Aluno>) ois.readObject();
        } catch (FileNotFoundException e) {
            // Trata a exceção se o arquivo não for encontrado, lançando-a novamente
            throw e;
        } catch (IOException | ClassNotFoundException e) {
            // Trata exceções de entrada/saída e de classe não encontrada, imprimindo o stack trace e lançando a exceção novamente
            e.printStackTrace();
            throw e;
        }
    }
}
