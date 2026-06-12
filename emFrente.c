#include <stdio.h>
#include <stdlib.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void emFrente(char matriz[MAXL][MAXC], int opcao, int nL, int nC, int* onibus, int *passageiros){


    // Controlo as direções do onibus pelos laços "for", de maneira que sempre usamos a matriz no modo "matriz[linhas][colunas]" para facilitar o entendimento e edição
    // As linhas sempre serão controladas por [i] e as colunas sempre serão controladas por [j]
    for (int j=onibus[1]; j>=0; j--){
        for(int i=onibus[0]; i>=0; i--){
            if (matriz[i][j] == P){ //Verifica se é passageiro

                *passageiros=*passageiros+1;
                printf("\n\nPassageiros: %d\n\n", *passageiros);

            }
            if (matriz[i+1][j]== B) matriz[i+1][j] = V; // Muda a célula anterior da posição do onibus para vazio
            if (matriz[i][j] != '#') matriz[i][j] = B; // Verifica se for obstáculo, só move o ônibus se não for
            imprimeMapa(matriz, nL, nC);
        }
        if (matriz[0][j]== B) matriz[0][j] = V; // Muda a célula anterior da posição do onibus para vazio quando chega na última linha
    }

}