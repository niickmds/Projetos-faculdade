package org.example.ativalunojavafx.Entidades;

import java.io.Serial;
import java.io.Serializable;

public class Disciplina implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;

    private final String nome;
    private final String codigo;
    private final double nota;

    public Disciplina (String nome, String codigo, double nota)  {
        this.nome = nome;
        this.codigo = codigo;
        this.nota = nota;
    }

    public String getNome() {
        return nome;
    }

    public double getNota() {
        return nota;
    }

    @Override
    public String toString() {
        return "Disciplina{" +
                "nome='" + nome + '\'' +
                ", codigo='" + codigo + '\'' +
                ", nota=" + nota +
                '}';
    }

    public String getCodigoDisciplina() {
        return codigo;
    }

}
