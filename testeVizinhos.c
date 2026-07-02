#include <stdio.h>
#include <stdlib.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

int *testeVizinhos(Mapa *Cidade, int* onibus, int* contagem_ciclos){

    int *posicao = malloc(2 * sizeof(int));
    posicao[0] = -1;
    posicao[1] = -1;
    int flag_sai_do_loop = 0;

    for (int l = onibus[0]-1; l<onibus[0]+2 && l<Cidade->nL; l++){ // Anda de linha -1 a linha +1 e verifica borda
        if (l<0) l=0;
        for (int c = onibus[1]-1; c<onibus[1]+2 && c<Cidade->nC; c++){ // Anda de Coluna -1 a Coluna +1 e verifica borda
            if (c<0) c=0;
            if (l==onibus[0] && c==onibus[1]) {
                continue;
            }
            if (Cidade->matriz[*contagem_ciclos][l][c] != '#'){
                posicao[0]=l;
                posicao[1]=c;
                flag_sai_do_loop = 1;
                break;
            }
        }
        
        if(flag_sai_do_loop == 1){
            break;
        }
    }
    
    if (posicao[0] == -1 && posicao[1] == -1) {
        printf("\n\nOnibus preso! Chame o guincho!\n\n");
        printf(
        "     _               \n"
        "    / |              \n"
        "   /  |       ____   \n"
        "  /   |     _|__  \\_ \n"
        " J    |____|    |   |\n"
        "      |____|____|___|\n"
        "      -(O)-------(O)-\n"
    );

    exit(1);
    }

    return posicao;
}
