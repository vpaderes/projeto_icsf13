#ifndef PROTOTIPOS_PROJETO_H
#define PROTOTIPOS_PROJETO_H
#include "defines_projeto.h"

void preencheMatriz(Mapa *Cidade, int* onibus);
int *testeVizinhos(Mapa *Cidade, int* onibus, int* contagem_ciclos);
int escolheMovimento(Mapa *Cidade);
int defineDirecao(int *flag_obstaculo);
void movimentaOnibus(Mapa *Cidade, int mov, int* onibus, int *passageiros, int* contagem_ciclos); 
void imprimeMapa(Mapa *Cidade, int *passageiros, int *contagem_ciclos); 
void emFrente(Mapa *Cidade, int* onibus, int *passageiros, int* contagem_ciclos, int limite_ciclos);
void movAleat(Mapa *Cidade, int* onibus, int *passageiros, int* contagem_ciclos, int limite_ciclos);
void buscaInteligente(Mapa *Cidade, int* onibus, int *passageiros, int* contagem_ciclos, int limite_ciclos);
void mix(Mapa *Cidade, int* onibus, int *passageiros, int* contagem_ciclos, int limite_ciclos);
void mudaMapa(Mapa *Cidade, int* onibus, int* contagem_ciclos);
void escolheArquivoMapa(char *arquivoEscolhido);
int criaOnibus(Mapa *Cidade);
void escolheArquivoMapa(char *arquivoEscolhido);
void movNovosAleat(Mapa *Cidade, int onibus, int *antigo_onibus, int* passageiros, int* contagem_ciclos)

#endif

