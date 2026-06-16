#include <stdio.h>
#include <stdlib.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

int *testeVizinhos(char matriz[MAXL][MAXC], int nL, int nC, int* onibus){

    int posicao_livre[2] = {-1,-1}, flag_sai_do_loop =0;

    for (int l = onibus[0]-1; l<onibus[0]+2 && l<nL; l++){
        if (l<0) l=0;
        for (int c = onibus[1]-1; c<onibus[1]+2 && c<nC; c++){
            if (c<0) c=0;
            if (l==onibus[0] && c==onibus[1]) {
                c++;
            }
            if (matriz[l][c] != '#'){
                posicao_livre[0]=l;
                posicao_livre[1]=c;
                flag_sai_do_loop =1;
                break;
            }
        }
        if(flag_sai_do_loop=1){
            break;
        }
    }
    if (posicao_livre[0] == -1 && posicao_livre[1] == -1) {
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

return posicao_livre;}