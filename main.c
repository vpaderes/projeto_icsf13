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
   int opcao, flag_encerramento = 100;
   int onibus[2], passageiros = 0;
   int ciclos, contagem_ciclos = 0;

   preencheMatriz(matriz, nL, nC, onibus);
   imprimeMapa(matriz, nL, nC, &passageiros, &contagem_ciclos);
   
   flag_encerramento = 100; // REMOVER APÓS O TESTE

   //while (flag_encerramento != 0){ // CRIAR CONDIÇÃO DE PARADA DE ACORDO COM A LÓGICA DOS CICLOS
   opcao = escolheMovimento(&ciclos);
   movimentaOnibus(matriz, opcao, nL, nC, onibus, &passageiros, ciclos, &contagem_ciclos);
   //ciclos
   flag_encerramento = 0;
   //}



   return 0;
}
