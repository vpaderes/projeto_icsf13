#ifndef PROTOTIPOS_PROJETO_H
#define PROTOTIPOS_PROJETO_H
#include "defines_projeto.h"

void preencheMatriz(Mapa *Cidade, int* onibus);
int *testeVizinhos(char matriz[MAXL][MAXC], int nL, int nC, int* onibus);
int escolheMovimento(Mapa *Cidade);
int defineDirecao(int *flag_obstaculo);
void movimentaOnibus(char matriz[MAXL][MAXC], int mov, int nL, int nC, int* onibus, int *passageiros, int ciclos, int* contagem_ciclos, char matriz_memoria[MAXCICLOS][MAXL][MAXC]); 
void imprimeMapa(Mapa *Cidade, int *passageiros, int *contagem_ciclos); 
void emFrente(char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int ciclos, int* contagem_ciclos, char matriz_memoria[MAXCICLOS][MAXL][MAXC]);
void movAleat(char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int ciclos, int* contagem_ciclos, char matriz_memoria[MAXCICLOS][MAXL][MAXC]);
void buscaInteligente(char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int ciclos, int* contagem_ciclos, char matriz_memoria[MAXCICLOS][MAXL][MAXC]);
void mix (char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int ciclos, int* contagem_ciclos, char matriz_memoria[MAXCICLOS][MAXL][MAXC]);
void mudaMapa(char matriz[MAXL][MAXC], int nL, int nC, int* onibus);
void escolheArquivoMapa(char *arquivoEscolhido);
int criaOnibus(Mapa *Cidade);
void escolheArquivoMapa(char *arquivoEscolhido);
void movNovosAleat(Mapa *Cidade, int onibus, int *antigo_onibus, int* passageiros, int* contagem_ciclos)

#endif

