package org.example.ativalunojavafx.Cadastros;

import org.example.ativalunojavafx.Entidades.Aluno;

import java.util.ArrayList;
import java.util.List;

public class Cadastro {
    // Lista de alunos que será gerenciada por esta classe
    private final List<Aluno> alunos;

    // Construtor que inicializa a lista de alunos como um ArrayList vazio
    public Cadastro() {
        this.alunos = new ArrayList<>();
    }

    // Método para inserir um aluno na lista
    public void inserirAluno(Aluno aluno) {
        // Verifica se o aluno já está na lista para evitar duplicatas
        if (!alunos.contains(aluno)) {
            alunos.add(aluno); // Adiciona o aluno à lista se ele ainda não estiver presente
        } else {
            System.out.println("Aluno já inserido!"); // Imprime uma mensagem se o aluno já estiver na lista
        }
    }

    // Método para remover um aluno da lista pelo seu RA (Registro Acadêmico)
    public void removerAluno(String ra) {
        Aluno alunoToRemove = null;
        // Procura o aluno na lista pelo RA
        for (Aluno aluno : alunos) {
            if (String.valueOf(aluno.getRa()).equals(ra)) {
                alunoToRemove = aluno; // Guarda o aluno a ser removido
                break;
            }
        }
        // Se o aluno for encontrado, remove-o da lista
        if (alunoToRemove != null) {
            alunos.remove(alunoToRemove);
        } else {
            System.out.println("Aluno não encontrado!"); // Imprime uma mensagem se o aluno não for encontrado
        }
    }

    // Método para verificar se um aluno com um dado RA existe na lista
    public boolean existeAluno(String ra) {
        // Percorre a lista de alunos e verifica se algum deles tem o RA especificado
        for (Aluno aluno : alunos) {
            if (String.valueOf(aluno.getRa()).equals(ra)) {
                return true; // Retorna true se encontrar o aluno
            }
        }
        return false; // Retorna false se não encontrar o aluno
    }

    // Método para buscar e retornar um aluno pelo RA
    public Aluno buscarAluno(String ra) {
        // Percorre a lista de alunos e retorna o aluno com o RA especificado
        for (Aluno aluno : alunos) {
            if (String.valueOf(aluno.getRa()).equals(ra)) {
                return aluno; // Retorna o aluno encontrado
            }
        }
        return null; // Retorna null se não encontrar o aluno
    }

    // Método para obter uma cópia da lista de alunos
    public List<Aluno> getAlunos() {
        // Retorna uma nova lista contendo os mesmos alunos para evitar modificações externas
        return new ArrayList<>(alunos);
    }

    // Método para definir a lista de alunos
    public void setAlunos(List<Aluno> novosAlunos) {
        alunos.clear(); // Limpa a lista atual de alunos
        alunos.addAll(novosAlunos); // Adiciona todos os novos alunos à lista
    }
}
