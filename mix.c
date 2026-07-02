#include <stdio.h>
#include <stdlib.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void mix(Mapa *Cidade, int* onibus, int *passageiros, int* contagem_ciclos, int limite_ciclos){

    int mov = rand()%3+1; //Define o tipo de movimento
    int rodadas_aleatorias = rand()%30+1;
    int ciclos_temporario;

    while ((*contagem_ciclos) < Cidade->nCiclos)
    {
        mov = rand()%3+1;
        rodadas_aleatorias = rand()%30+1;

        if ((*contagem_ciclos)+rodadas_aleatorias<Cidade->nCiclos){
            ciclos_temporario = rodadas_aleatorias+(*contagem_ciclos);
        } else ciclos_temporario = Cidade->nCiclos;

        switch (mov) {
            case EMFRENTE:
                printf("\nSeguir em frente selecionado\n");
                emFrente(Cidade, onibus, passageiros, contagem_ciclos, ciclos_temporario);
                break;

            case ALEAT:
                printf("\nMovimento Aleatorio selecionado.\n");
                movAleat(Cidade, onibus, passageiros, contagem_ciclos, ciclos_temporario);
                break;

            case BUSCINTEL:
                printf("\nBusca Inteligente selecionada.\n");
                buscaInteligente(Cidade, onibus, passageiros, contagem_ciclos, ciclos_temporario);
                break;

            default:
                printf("\nErro! Opcao de movimento desconhecida.\n");
                break;
        }
    }

}