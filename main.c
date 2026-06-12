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
   int mov, flag_encerramento = 100;
   int onibus[2], passageiros = 0;

   preencheMatriz(matriz, nL, nC, onibus);
   imprimeMapa(matriz, nL, nC);
   
   flag_encerramento = 100; // REMOVER APÓS O TESTE

   while (flag_encerramento != 0){ // CRIAR CONDIÇÃO DE PARADA DE ACORDO COM A LÓGICA DOS CICLOS
    mov = escolheMovimento();
    movimentaOnibus(matriz, mov, nL, nC, onibus, &passageiros);
    //ciclos
    flag_encerramento = 0;
   }



   return 0;
}
