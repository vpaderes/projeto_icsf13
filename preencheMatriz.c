#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void preencheMatriz(char matriz[MAXL][MAXC], int nL, int nC, int* onibus)
{

    for(int i = 0; i < MAXL; i++)
    {
        for (int j = 0; j < MAXC; j++)
        {
            matriz[i][j] = V;
        }
    }

    matriz[0][0] = 'P';
    matriz[0][2] = 'P';
    matriz[1][2] = '#';
    matriz[1][3] = '#';
    matriz[1][4] = '#';
    matriz[2][1] = 'P';
    matriz[2][11] = 'P';
    matriz[2][16] = '#';
    matriz[4][6] = 'P';
    matriz[6][6] = 'P';
    matriz[6][19] = 'P';
    matriz[11][3] = 'P';
    matriz[11][11] = 'P';
    matriz[12][19] = 'P';
    matriz[13][7] = '#';
    matriz[14][7] = '#';
    matriz[14][14] = 'P';
    matriz[15][7] = '#';
    matriz[16][3] = 'P';
    matriz[16][16] = 'P';
    matriz[16][19] = 'P';
    matriz[19][1] = 'P';
    matriz[19][6] = 'P';
    matriz[19][10] = 'P';
    matriz[nL-1][nC-1] = 'B';

    //loop abaixo analisa o mapa da matriz e marca no vetor onibus as posições iniciais de linha e coluna do busão
    for (int i=0; i<nL; i++){
        for(int j=0; j<nC; j++){
            if (matriz[i][j] == B) {
                onibus[0] = i;
                onibus[1] = j;
            }
        }
    }

}