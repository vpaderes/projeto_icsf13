#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void preencheMatriz(char matriz[MAXL][MAXC], int nL, int nC, int* onibus)
{
    int celula;

    for(int i = 0; i < MAXL; i++)
    {
        for (int j = 0; j < MAXC; j++)
        {
            celula = rand()%100+1;

            if (celula>=1 && celula <16) matriz[i][j] = P;
            else if (celula>=41 && celula < 51) matriz[i][j] = '#';
            else matriz[i][j] = V;

        }
    }

    onibus[0] = rand()%nL;
    onibus[1] = rand()%nC;
    matriz[onibus[0]][onibus[1]] = B;

}
