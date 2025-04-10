package org.example.ativalunojavafx.Entidades;

import java.io.Serial;
import java.io.Serializable;
import java.util.List;

public class Aluno extends Pessoa implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;
    private final String ra;
    private final int semestre; // Alteração 1
    private final List<Disciplina> disciplinas;
    private int listaIndex;

    public Aluno(String nome, int idade, String rg, String ra, int semestre, List<Disciplina> disciplinas)
    {
        super(nome, idade, rg);
        this.ra = ra;
        this.semestre = semestre;
        this.disciplinas = disciplinas;
    }

    public String getRa() {
        return ra;
    }
    public int getSemestre() { // Atualização 1
        return semestre;
    }

    public List<Disciplina> getDisciplinas() {
        return disciplinas;
    }

    public int getListaIndex() {
        return listaIndex;
    }

    public void setListaIndex(int index) {
        this.listaIndex = index;
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("Posição na lista: ").append(getListaIndex()).append("\n");
        stringBuilder.append("Nome: ").append(getNome()).append("\n");
        stringBuilder.append("Idade: ").append(getIdade()).append("\n");
        stringBuilder.append("RG: ").append(getRg()).append("\n");
        stringBuilder.append("RA: ").append(ra).append("\n");
        stringBuilder.append("Semestre: ").append(semestre).append("\n");
        stringBuilder.append("Disciplinas: \n");
        for (Disciplina disciplina : disciplinas) {
            stringBuilder.append("- ").append(disciplina).append("\n");
        }
        return stringBuilder.toString();
    }


}
