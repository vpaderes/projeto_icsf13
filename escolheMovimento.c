#include <stdio.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"


int escolheMovimento(int *ciclos){
    int opcao = 0;

    while (opcao<1 || opcao>4){
    
        printf("\nMenu de Movimentações\nDigite sua opcao:\n");
        printf("Em Frente: 1\n");
        printf("Movimento aleatorio: 2\n");
        printf("Busca Inteligente: 3\n");
        printf("Mix: 4\n\n");
        scanf("%d", &opcao);
        
        if(opcao<1 || opcao>4) printf("Opcao invalida! Digite novamente:\n");
    }

    *ciclos = -1;
    while ((*ciclos)<0 || (*ciclos)>MAXC*MAXL){
        printf("Digite a quantidade de ciclos:\n");
        scanf("%d", ciclos);
        if((*ciclos)<0 || (*ciclos)>MAXC*MAXL) printf("Opcao invalida! Digite novamente:\n");
    }


return opcao;}