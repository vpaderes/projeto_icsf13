#include <stdio.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void movimentaOnibus(Mapa *Cidade, int mov, int* onibus, int *passageiros, int* contagem_ciclos) {
    int flag_obstaculo = 0;
    
    switch (mov) {
        case EMFRENTE:
            printf("\nSeguindo em frente\n");
            emFrente(Cidade, onibus, passageiros, contagem_ciclos, Cidade->nCiclos);
            break;

        case ALEAT:
            printf("\nMovimento Aleatorio selecionado.\n"); 
            movAleat(Cidade, onibus, passageiros, contagem_ciclos, Cidade->nCiclos);
            break;

        case BUSCINTEL:
            printf("\nBusca Inteligente selecionada.\n");
            buscaInteligente(Cidade, onibus, passageiros, contagem_ciclos, Cidade->nCiclos);
            break;

        case MIX:
            printf("\nMovimento Mix selecionado.\n");
            mix(Cidade, onibus, passageiros, contagem_ciclos, Cidade->nCiclos);
            break;

        default:
            printf("\nOpcao de movimento desconhecida.\n");
            break;
    }
}
