#include <stdio.h>
#include <stdlib.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void mix (char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int ciclos, int* contagem_ciclos, char matriz_memoria[MAXL][MAXC][MAXCICLOS]){

    int mov = rand()%3+1; //Define o tipo de movimento
    int rodadas_aleatorias = rand()%30+1;
    int ciclos_temporario;

    while ((*contagem_ciclos) < ciclos)
    {
        mov = rand()%3+1;
        rodadas_aleatorias = rand()%30+1;

        if ((*contagem_ciclos)+rodadas_aleatorias<ciclos){
            ciclos_temporario = rodadas_aleatorias+(*contagem_ciclos);
        } else ciclos_temporario = ciclos;

        switch (mov) {
            case EMFRENTE:
                printf("\nSeguir em frente selecionado\n");
                emFrente(matriz, nL, nC, onibus, passageiros, ciclos_temporario, contagem_ciclos, matriz_memoria);
                break;

            case ALEAT:
                printf("\nMovimento Aleatorio selecionado.\n");
                movAleat(matriz, nL, nC, onibus, passageiros, ciclos_temporario, contagem_ciclos, matriz_memoria);
                break;

            case BUSCINTEL:
                printf("\nBusca Inteligente selecionada.\n");
                buscaInteligente(matriz, nL, nC, onibus, passageiros, ciclos_temporario, contagem_ciclos, matriz_memoria);
                break;

            default:
                printf("\nErro! Opcao de movimento desconhecida.\n");
                break;
        }
    }

}