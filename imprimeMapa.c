#include <stdio.h>
#include <stdlib.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void imprimeMapa(Mapa *Cidade, int *passageiros, int *contagem_ciclos) {

    LIMPATELA();
    printf("\n\n\n");
    for (int i=0; i<Cidade->nL; i++){
        for (int j=0; j<Cidade->nC; j++){
            printf("%c ", Cidade->matriz[i][j]);
        }
        printf("\n");
    }

    
    for (int i=0; i<nL; i++){
        for (int j=0; j<nC; j++){
           matriz_memoria[(*contagem_ciclos)][i][j] = matriz[i][j];
        }
    }
    
    printf("\nPassageiros: %d", *passageiros);
    printf("\nCiclos percorridos: %d", *contagem_ciclos);
    printf("\n\n");
    DORME(1);
}