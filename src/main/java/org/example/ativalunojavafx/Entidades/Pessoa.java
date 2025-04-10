package org.example.ativalunojavafx.Entidades;

public class Pessoa {
    private final String nome;
    private final int idade;
    private final String rg;

    public Pessoa(String nome, int idade, String rg) {
        this.nome = nome;
        this.idade = idade;
        this.rg = rg;
    }
    public String getNome() {
        return nome;
    }

    public int getIdade() {
        return idade;
    }

    public String getRg() {
        return rg;
    }
}
