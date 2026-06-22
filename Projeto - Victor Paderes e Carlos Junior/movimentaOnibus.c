#include <stdio.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void movimentaOnibus(char matriz[MAXL][MAXC], int mov, int nL, int nC, int* onibus, int *passageiros, int ciclos, int* contagem_ciclos, char matriz_memoria[MAXL][MAXC][MAXCICLOS]) {
    int flag_obstaculo = 0;
    
    switch (mov) {
        case EMFRENTE:
            printf("\nSeguindo em frente\n");
            emFrente(matriz, nL, nC, onibus, passageiros, ciclos, contagem_ciclos, matriz_memoria);
            break;

        case ALEAT:
            printf("\nMovimento Aleatorio selecionado.\n"); 
            movAleat(matriz, nL, nC, onibus, passageiros, ciclos, contagem_ciclos, matriz_memoria);
            break;

        case BUSCINTEL:
            printf("\nBusca Inteligente selecionada.\n");
            buscaInteligente(matriz, nL, nC, onibus, passageiros, ciclos, contagem_ciclos, matriz_memoria);
            break;

        case MIX:
            printf("\nMovimento Mix selecionado.\n");
            mix(matriz, nL, nC, onibus, passageiros, ciclos, contagem_ciclos, matriz_memoria);
            break;

        default:
            printf("\nOpcao de movimento desconhecida.\n");
            break;
    }
}
