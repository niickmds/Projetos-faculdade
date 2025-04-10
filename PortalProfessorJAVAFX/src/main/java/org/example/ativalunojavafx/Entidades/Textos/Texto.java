package org.example.ativalunojavafx.Entidades.Textos;

public class Texto {

    // Atributo da classe ou varáveis de instancia

    private String txt;


    public Texto(String txt){

        setTxt(txt);

        limpaEspacosExcedentes();

    }

    // setters e getters

    void setTxt(String t){

        this.txt = t;

    }

    public String getTxt(){

        return this.txt;

    }


    public String inverterTexto(){

        StringBuilder txtInvertido = new StringBuilder();

        if(!(this.txt == null || this.txt.isEmpty())){

            for (int i=this.txt.length()-1; i >= 0; i--){

                txtInvertido.append(this.txt.charAt(i));

            }

        } else {

            return null;

        }

        return txtInvertido.toString();

    }


    public int getQtdePalavras(){

        return (getTxt().split(" ").length);

    }

    private void limpaEspacosExcedentes(){

        // Elimina espacos do inicio e fim da string

        setTxt(this.txt.trim());

        // Elimina espacos excedentes do meio da string

        StringBuilder s = new StringBuilder();

        for (int i=0; i < this.txt.length(); i++){

            s.append(this.txt.charAt(i)); // pega o caractere da posicao

            if(this.txt.charAt(i) == ' '){

                while(this.txt.charAt(i+1) == ' '){ // avanca se tiver mais espacos

                    i++;

                }

            }

        }

        setTxt(s.toString());

    }

    @Override
    public String toString(){

        return(getTxt());

    }

}
