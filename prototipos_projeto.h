#ifndef PROTOTIPOS_PROJETO_H
#define PROTOTIPOS_PROJETO_H
#include "defines_projeto.h"

void preencheMatriz(char matriz[MAXL][MAXC], int nL, int nC, int* onibus);
int *testeVizinhos(char matriz[MAXL][MAXC], int nL, int nC, int* onibus);
int escolheMovimento(int *ciclos);
int defineDirecao(int *flag_obstaculo);
void movimentaOnibus(char matriz[MAXL][MAXC], int mov, int nL, int nC, int* onibus, int *passageiros, int ciclos, int* contagem_ciclos, char matriz_memoria[MAXL][MAXC][MAXCICLOS]); 
void imprimeMapa(char matriz[MAXL][MAXC], int nL, int nC, int *passageiros, int *contagem_ciclos, char matriz_memoria[MAXL][MAXC][MAXCICLOS]); 
void emFrente(char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int ciclos, int* contagem_ciclos, char matriz_memoria[MAXL][MAXC][MAXCICLOS]);
void movAleat(char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int ciclos, int* contagem_ciclos, char matriz_memoria[MAXL][MAXC][MAXCICLOS]);
void buscaInteligente(char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int ciclos, int* contagem_ciclos, char matriz_memoria[MAXL][MAXC][MAXCICLOS]);
void mix (char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int ciclos, int* contagem_ciclos, char matriz_memoria[MAXL][MAXC][MAXCICLOS]);
void mudaMapa(char matriz[MAXL][MAXC], int nL, int nC, int* onibus);

#endif
