
#ifndef PROTOTIPOS_PROJETO_H
#define PROTOTIPOS_PROJETO_H
#include "defines_projeto.h"

//PROTOTIPOS


void preencheMatriz(char matriz[MAXL][MAXC], int nL, int nC, int* onibus);
int escolheMovimento();
int defineDirecao();
void movimentaOnibus(char matriz[MAXL][MAXC], int mov, int nL, int nC, int* onibus, int *passageiros); 
void imprimeMapa(char matriz[MAXL][MAXC], int nL, int nC); 
void emFrente(char matriz[MAXL][MAXC], int opcao, int nL, int nC, int* onibus, int *passageiros);

#endif