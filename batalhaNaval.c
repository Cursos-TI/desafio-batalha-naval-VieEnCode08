#include <stdio.h>

    int main () {
        // Variavel que representa o tabuleiro 
        int agua [10] [10] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };
 
        // Linha Horizontal do Tabuleiro
        char tabela [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

        // Linha vertical do Tabuleiro
        int lateral [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        // Navio
        int tamanhoNavio = 3;

        // Navio Horizontal
        int linhaHorizontal = 3;
        int colunaHorizontal = 5;
        
        // Navio Vertical
        int linhaVertical = 6;
        int colunaVertical = 3;

        // Navio Diagonal
        int linhaDiagonal1 = 0;
        int colunaDiagonal1 = 0;

        int linhaDiagonal2 = 6;
        int colunaDiagonal2 = 6;

        // Mini Menu
        printf ("=====Bem-Vindo ao Jogo Batalha Naval=====\n");
        printf ("\n");

        for (int i = 0; i < 10; i++) { // Responsavel por percorrer as linha 
           for (int j = 0; j < 10; j++) { // Responsavel por percorrer as colunas 
                if (i == linhaHorizontal && j >= colunaHorizontal && j < colunaHorizontal + tamanhoNavio) {  // Lógica responsavel por colocar o navio na horizontal
                    agua[i][j] = 3; // Faz imprimir o numero "3" no tabuleiro caso a lógica seja verdadeira
                } else {
                    agua [i][j]; // Imprime "0" se a lógica for falsa
                }
           }
        }

        for (int i = 0; i < 10; i++) { // Responsavel por percorrer as linha 
            for (int j = 0; j < 10; j++) { // Responsavel por percorrer as colunas 
                if (j == colunaVertical && i >= linhaVertical && i < linhaVertical + tamanhoNavio) {  // Lógica responsavel por colocar o navio na vertical
                   agua[i][j] = 3; // Faz imprimir o numero "3" no tabuleiro caso a lógica seja verdadeira
                } else {
                    agua[i][j]; // Imprime "0" se a lógica for falsa
                }
            }
        }

        for (int k = 0; k < tamanhoNavio; k++) {
            int i = linhaDiagonal1 + k;
            int j = colunaDiagonal1 + k;
        if (i < 10 && j < 10) {
            agua[i][j] = 3;
        }
    }
        for (int k = 0; k < tamanhoNavio; k++) {
            int i = linhaDiagonal2 + k;
            int j = colunaDiagonal2 + k;
        if (i < 10 && j < 10) {
            agua[i][j] = 3;
        }
    }

        // MATRIZES DE HABILIDADE 5x5
        int cone[5][5];
        int cruz[5][5];
        int oct[5][5];

        // CONE (topo estreito -> base larga)
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(j >= 2-i && j <= 2+i) cone[i][j] = 1;
                else cone[i][j] = 0;
            }
        }

        // CRUZ
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(i == 2 || j == 2) cruz[i][j] = 1;
                else cruz[i][j] = 0;
            }
        }

        // OCTAEDRO
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(abs(i-2) + abs(j-2) <= 2) oct[i][j] = 1;
                else oct[i][j] = 0;
            }
        }

        // ORIGENS DAS HABILIDADES
        int linCone = 1, colCone = 1;
        int linCruz = 4, colCruz = 4;
        int linOct  = 7, colOct  = 7;

        // APLICA CONE NO TABULEIRO
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                int li = linCone + (i - 2);
                int co = colCone + (j - 2);

                if(li >= 0 && li < 10 && co >= 0 && co < 10){
                    if(cone[i][j] == 1 && agua[li][co] != 3){
                        agua[li][co] = 5;
                    }
                }
            }
        }

        // APLICA CRUZ
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                int li = linCruz + (i - 2);
                int co = colCruz + (j - 2);

                if(li >= 0 && li < 10 && co >= 0 && co < 10){
                    if(cruz[i][j] == 1 && agua[li][co] != 3){
                        agua[li][co] = 5;
                    }
                }
            }
        }

        // APLICA OCTAEDRO
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                int li = linOct + (i - 2);
                int co = colOct + (j - 2);

                if(li >= 0 && li < 10 && co >= 0 && co < 10){
                    if(oct[i][j] == 1 && agua[li][co] != 3){
                        agua[li][co] = 5;
                    }
                }
            }
        }

        printf ("   "); // Pra dar um espaço entre as linhas e colunas
        
        for (int i = 0; i < 10; i++) { // Esse for é responsavel por imprimir o cabeçalho do tabuleiro
            printf ("%c ", tabela[i]);
        }

        printf ("\n");
        
        for (int i = 0; i < 10; i++) { // Esse for de fora é responsavel por imprimir os numeros que ficam na lateral do tabuleiro
            printf ("%2d ", lateral[i]);
            for (int j = 0; j < 10; j++) { // Esse for de dentro é responsavel pro preencher o interior do tabuleiro com 0
            printf ("%d ", agua[i][j]);
        }
            printf ("\n");
        }
        return 0;
    }