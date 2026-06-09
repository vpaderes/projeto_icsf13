#include <stdio.h>
#include <stdlib.h>
// #include <windows.h>
#include <time.h>
:
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
//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////Inicio dos prototipos ou definições /////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void preencheMatriz(...);//completar com os parametros sendo passados
int escolheMovimento(...);//completar com os parametros sendo passados
int defineDirecao(...);//completar com os parametros sendo passados
void movimentaOnibus(...); //completar com os parametros sendo passados
void imprimeMapa(...); //completar com os parametros sendo passados
//incluir os outros protótipos necessários

int main()
{

   // atenção utilizar as macros definidas no início do programa
   char mat[MAXL][MAXC];

   int nL=20,nC=20,nCiclos=50; //ou fornecidos pelo usuario
   int mov; //opcao fornecida pelo usuario para o tipo de movimento

   //completar aqui o solicitado em cada etapa


   return 0;
}

void preencheMatriz(char matriz[MAXL][MAXC])
{
    char a[20][20];

    a[0][0] = 'P';
    a[0][2] = 'P';
    a[1][2] = '#';
    a[1][3] = '#';
    a[1][4] = '#';
    a[2][1] = 'P';
    a[2][11] = 'P';
    a[2][16] = '#';
    a[4][6] = 'P';
    a[6][6] = 'P';
    a[6][19] = 'P';
    a[11][3] = 'P';
    a[11][11] = 'P';
    a[12][19] = 'P';
    a[13][7] = '#';
    a[14][7] = '#';
    a[14][14] = 'P';
    a[15][7] = '#';
    a[16][3] = 'P';
    a[16][16] = 'P';
    a[16][19] = 'P';
    a[19][1] = 'P';
    a[19][6] = 'P';
    a[19][10] = 'P';
    a[19][19] = 'B';


    for(int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if(a[i][j] != 'P' && a[i][j] != '#' && a[i][j] != 'B')
                a[i][j] = '.';
        }
    }

}

void imprimeMapa(char m[MAXL][MAXC])
{
     for(int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            printf("%2c", a[i][j]);
        }
        printf("\n");
    }

}

int escolheMovimento(int mov)
{
    if (mov == EMFRENTE)
        return EMFRENTE;
    else if (mov == ALEAT)
        return ALEAT;
    else if (mov == BUSCINTEL)
        return BUSCINTEL;
    else
        return MIX;

}
int defineDirecao(...){
  //implementar os comandos necessários

}

void movimentaOnibus(...){

    //incluir o laço de repetição e completar o que for necessário para o movimento do ônibus


        //incluir os comandos ou funções para atualizar o mapa com o movimento do ônibus

        imprimeMapa(...);
        DORME(...); //definir o tempo que segura a tela no vídeo
        LIMPATELA();



     //fim do laço


}
// incluir aqui as definições das outras funções necessárias
