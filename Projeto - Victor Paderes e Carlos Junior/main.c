#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"
// #include <windows.h>



int main()
{
   char matriz[MAXL][MAXC];
   char matriz_memoria[MAXL][MAXC][MAXCICLOS];
   int nL,nC;
   printf("\nDigite a quantidade de linhas da matriz:\n");
   scanf("%d", &nL);
   printf("\nDigite a quantidade de colunas da matriz:\n");
   scanf("%d", &nC);
   int opcao;
   int onibus[2], passageiros = 0;
   int ciclos, contagem_ciclos = 0;
   srand(time(NULL));

   preencheMatriz(matriz, nL, nC, onibus);
   opcao = escolheMovimento(&ciclos);
   imprimeMapa(matriz, nL, nC, &passageiros, &contagem_ciclos, matriz_memoria);
   movimentaOnibus(matriz, opcao, nL, nC, onibus, &passageiros, ciclos, &contagem_ciclos, matriz_memoria);

   int opcao_de_encerramento, consulta;
   printf("\nFim do simulador de transporte urbano.\n");
   printf("\nVocê gostaria de:");
   printf("\n(1).Sair     (2). Consultar o mapa em um ciclo específico\n");
   scanf("%d", &opcao_de_encerramento);

   if(opcao_de_encerramento == 2){
      printf("\nVoce gostaria de consultar qual ciclo?: ");
      scanf("%d", &consulta);
      consulta--;
      LIMPATELA();
      printf("Mapa no ciclo %d", consulta+1);
      printf("\n\n\n");
      for (int i=0; i<nL; i++){
        for (int j=0; j<nC; j++){
            printf("%c ", matriz_memoria[i][j][consulta]);
        }
        printf("\n");
      }
   } else printf("Encerrando o simulador. Obrigado!\n");



   return 0;
}
