
#ifndef DEFINES_PROJETO_H
#define DEFINES_PROJETO_H
//Macros para os movimentos (mov)
#define EMFRENTE 1
#define ALEAT 2
#define BUSCINTEL 3
#define MIX 4


//Macros para as direcoes (dir)
#define N 1
#define S 2
#define L 3
#define W 4
#define NE 5
#define NO 6
#define SE 7
#define SO 8

//o trecho abaixo define as macros para onibus (B), Passageiro (P) e celula vazia (V)
#define B 'B'
#define P 'P'
#define V '.'

//Tamanhos maximos de linhas e colunas para a matriz
#define MAXL 100
#define MAXC 100
#define MAXCICLOS 100

//Verificacao de sistema operacional para a utilizacao da funcao DORME e LIMPATELA
#ifdef _WIN32
    #include <windows.h>
    #define DORME(a) Sleep((a)*1000)
    #define LIMPATELA() system("cls")
#else
    #include <unistd.h>
    #define DORME(a) sleep(a)
    #define LIMPATELA() system("clear")
#endif
#endif

// Struct para mapas
#define TAM 256
typedef struct Mapa
{
	char nomeCidade[TAM];
	int nCiclos, nL, nC;
	char ***matriz;
    int onibus_inimigo[30][2]; // Armazena linha e coluna para até 30 ônibus
    int inimigo_ativo[30]; // Guarda se estão ativos ou não
}Mapa;
