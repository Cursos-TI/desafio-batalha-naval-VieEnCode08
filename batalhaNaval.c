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

        // Navio Horizontal
        int tamanhoNavio = 3;
        int coluna1= 5;
        int linha1 = 3;
        
        // Navio Vertical
        int coluna2 = 3;
        int linha2 = 6;

        // Mini Menu
        printf ("=====Bem-Vindo ao Jogo Batalha Naval=====\n");
        printf ("\n");

        for (int i = 0; i < 10; i++) { // Responsavel por percorrer as linha 
           for (int j = 0; j < 10; j++) { // Responsavel por percorrer as colunas 
                if (i == linha1 && j >= coluna1 && j < coluna1 + tamanhoNavio) {  // Lógica responsavel por colocar o navio na horizontal
                    agua[i][j] = 3; // Faz imprimir o numero "3" no tabuleiro caso a lógica seja verdadeira
                } else {
                    agua [i][j]; // Imprime "0" se a lógica for falsa
                }
           }
        }

        for (int i = 0; i < 10; i++) { // Responsavel por percorrer as linha 
            for (int j = 0; j < 10; j++) { // Responsavel por percorrer as colunas 
                if (j == coluna2 && i >= linha2 && i < linha2 + tamanhoNavio) {  // Lógica responsavel por colocar o navio na vertical
                   agua[i] [j] = 3; // Faz imprimir o numero "3" no tabuleiro caso a lógica seja verdadeira
                } else {
                    agua[i] [j]; // Imprime "0" se a lógica for falsa
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