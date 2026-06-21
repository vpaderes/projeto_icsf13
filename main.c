#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"
// #include <windows.h>



int main()
{
   char matriz[MAXL][MAXC];
   int nL=20,nC=20,nCiclos=50;
   int opcao;
   int onibus[2], passageiros = 0;
   int ciclos, contagem_ciclos = 0;
   srand(time(NULL));

   preencheMatriz(matriz, nL, nC, onibus);
   imprimeMapa(matriz, nL, nC, &passageiros, &contagem_ciclos);
   
   opcao = escolheMovimento(&ciclos);
   movimentaOnibus(matriz, opcao, nL, nC, onibus, &passageiros, ciclos, &contagem_ciclos);



   return 0;
}
