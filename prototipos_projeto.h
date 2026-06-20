#ifndef PROTOTIPOS_PROJETO_H
#define PROTOTIPOS_PROJETO_H
#include "defines_projeto.h"

// PROTOTIPOS

void preencheMatriz(char matriz[MAXL][MAXC], int nL, int nC, int* onibus);
int *testeVizinhos(char matriz[MAXL][MAXC], int nL, int nC, int* onibus);
int escolheMovimento(int *ciclos);
int defineDirecao();
void movimentaOnibus(char matriz[MAXL][MAXC], int mov, int nL, int nC, int* onibus, int *passageiros, int *ciclos); 
void imprimeMapa(char matriz[MAXL][MAXC], int nL, int nC); 
int emFrente(char matriz[MAXL][MAXC], int opcao, int nL, int nC, int* onibus, int *passageiros, int*flag_obstaculo, int *ciclos);

// Adições necessárias para a integração no movimentaOnibus.c
void movAleat(char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int *ciclos);
void buscaInteligente(char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int *ciclos);

#endif
