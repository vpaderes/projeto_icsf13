#include <stdio.h>
#include <stdlib.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void imprimeMapa(char matriz[MAXL][MAXC], int nL, int nC) {

    printf("\n\n\n");
    for (int i=0; i<nL; i++){
        for (int j=0; j<nC; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");

}