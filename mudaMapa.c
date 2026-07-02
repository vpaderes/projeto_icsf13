#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void mudaMapa(Mapa *Cidade, int* onibus, int* contagem_ciclos)
{
    int celula;

    for(int i = 0; i < Cidade->nL; i++)
    {
        for (int j = 0; j < Cidade->nC; j++)
        {
            if (Cidade->matriz[*contagem_ciclos][i][j] != B){
                celula = rand()%100+1;

                if (celula>=1 && celula <16) Cidade->matriz[*contagem_ciclos][i][j] = P;
                else if (celula>=41 && celula < 51) Cidade->matriz[*contagem_ciclos][i][j] = '#';
                else Cidade->matriz[*contagem_ciclos][i][j] = V;
            }
        }
    }

}

