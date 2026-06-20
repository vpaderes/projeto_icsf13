#include <stdio.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void movimentaOnibus(char matriz[MAXL][MAXC], int mov, int nL, int nC, int* onibus, int *passageiros, int *ciclos) {
    int flag_obstaculo = 0;
    int opcao = 0;
    int contagem = 0;
    
    switch (mov) {
        case EMFRENTE:
            printf("\nSeguindo em frente\n");
            printf("Digite a direcao do onibus:\n");
            printf("(1)N  (2)S  (3)L  (4)O\n(5)NE  (6)NO  (7)SE  (8)SO\n\n");
            scanf("%d", &opcao);

            // Verifica se a entrada do usuário foi feita com valores válidos
            while (opcao < 1 || opcao > 8) {
                printf("Opcao invalida! Digite novamente:\n");
                printf("(1)N  (2)S  (3)L  (4)O\n(5)NE  (6)NO  (7)SE  (8)SO\n\n");
                scanf("%d", &opcao);
            }

            // Chamada da função do movimento em frente
            contagem = emFrente(matriz, opcao, nL, nC, onibus, passageiros, &flag_obstaculo, ciclos);
            *ciclos-=contagem;
            
            //A flag de obstáculo serve para prender o onibus nesse loop de movimento caso ele não consiga ir em frente
            while (flag_obstaculo == 1) {
                *ciclos-=contagem;
                printf("Encontramos um obstaculo! Digite nova direcao:\n");
                printf("(1)N  (2)S  (3)L  (4)O\n(5)NE  (6)NO  (7)SE  (8)SO\n\n");
                scanf("%d", &opcao);
                contagem = emFrente(matriz, opcao, nL, nC, onibus, passageiros, &flag_obstaculo, ciclos);
            }
            break;

        case ALEAT:
            printf("\nMovimento Aleatorio selecionado.\n"); 
            movAleat(matriz, nL, nC, onibus, passageiros, ciclos);
            break;

        case BUSCINTEL:
            printf("\nBusca Inteligente selecionada.\n");
            buscaInteligente(matriz, nL, nC, onibus, passageiros, ciclos);
            break;

        case MIX:
            printf("\nMovimento Mix selecionado.\n");
            // Adicione a chamada para a lógica do MIX aqui. 
            // Como o arquivo mix.c não foi fornecido, este é o espaço reservado.
            break;

        default:
            printf("\nOpcao de movimento desconhecida.\n");
            break;
    }
}
