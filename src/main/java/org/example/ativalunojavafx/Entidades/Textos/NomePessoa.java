    package org.example.ativalunojavafx.Entidades.Textos;

    public class NomePessoa {

        private Texto nome;

        // Construtores
        public NomePessoa(String nome){
            setNome(nome);
        }

        public String getNome() {
            return this.nome.getTxt();
        }


        protected void setNome(String nome) {
            this.nome = new Texto(nome);
        }

        public int getQtdePalavras(){
            return this.nome.getQtdePalavras();
        }

        public String getNomeInvertido(){
            return this.nome.inverterTexto();
        }

        // Método para obter o nome bibliográfico
        public String getNomeBiblio(String nome) {
            // Separa as palavras
            String[] vts = nome.split(" ");
            int qtd = vts.length;

            StringBuilder sBib = new StringBuilder();

            // Adiciona apenas o último sobrenome seguido por uma vírgula
            sBib.append(vts[qtd - 1]).append(", ");

            // Monta o texto
            for (int i = 0; i < (qtd - 1); i++) {
                String pal = vts[i].toLowerCase(); // pega palavra
                if (!verificaStr(pal)) { // Se não for preposição concatena a inicial em maiúscula
                    sBib.append(vts[i].toUpperCase().charAt(0)).append(". ");
                }
            }
            return sBib.toString();
        }
        private boolean verificaStr(String s){
            // Vetor de strings a serem retiradas
            final String[] sRet ={"da", "de", "do", "di", "das", "dos", "e",};

            for (String string : sRet) {
                if (string.equals(s)) {
                    return true;
                }
            }
            return false;
        }
    }