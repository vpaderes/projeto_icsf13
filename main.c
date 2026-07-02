#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"
//#include <windows.h>



int main()
{

   Mapa Cidade;
   
   int opcao;
   int onibus[2], passageiros = 0;
   int contagem_ciclos = 0;
   srand(time(NULL));

   preencheMatriz(&Cidade, onibus);
   opcao = escolheMovimento(&Cidade);
   imprimeMapa(&Cidade, &passageiros, &contagem_ciclos);
   movimentaOnibus(&Cidade, opcao, onibus, &passageiros, &contagem_ciclos);

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
      for (int i=0; i<Cidade.nL; i++){
        for (int j=0; j<Cidade.nC; j++){
            printf("%c ", Cidade.matriz[consulta][i][j]);
        }
        printf("\n");
      }
   } else printf("Encerrando o simulador. Obrigado!\n");

   for (int i = 0; i<Cidade.nCiclos; i++){
      for (int j = 0; j< Cidade.nL; j++){
         free(Cidade.matriz[i][j]);
      }
      free(Cidade.matriz[i]);
   }
   free(Cidade.matriz);



   return 0;
}
