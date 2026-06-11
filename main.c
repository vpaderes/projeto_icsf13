#include <stdio.h>
#include <stdlib.h>
// #include <windows.h>
#include <time.h>


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

//PROTOTIPOS

void preencheMatriz(char matriz[MAXL][MAXC], int nL, int nC);
int escolheMovimento();
int defineDirecao();
void movimentaOnibus(); 
void imprimeMapa(char matriz[MAXL][MAXC], int nL, int nC); 


int main()
{


   char matriz[MAXL][MAXC];


   int nL=20,nC=20,nCiclos=50;
   int mov, flag_encerramento = 100;

   preencheMatriz(matriz, nL, nC);
   imprimeMapa(matriz, nL, nC);
   
   while (flag_encerramento != 0){
    //ciclos
    flag_encerramento = 0;
   }



   return 0;
}

void preencheMatriz(char matriz[MAXL][MAXC], int nL, int nC)
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
    matriz[19][19] = 'B';

}

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