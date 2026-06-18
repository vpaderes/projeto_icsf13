#include <stdio.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void movimentaOnibus(char matriz[MAXL][MAXC], int mov, int nL, int nC, int* onibus, int *passageiros) {
    int flag_obstaculo = 0;
    int opcao = 0;
    int nCiclos = 0;

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

            // Chamada da função do movimento
            emFrente(matriz, opcao, nL, nC, onibus, passageiros, &flag_obstaculo);
            
            while (flag_obstaculo == 1) {
                printf("Encontramos um obstaculo! Digite nova direcao:\n");
                printf("(1)N  (2)S  (3)L  (4)O\n(5)NE  (6)NO  (7)SE  (8)SO\n\n");
                scanf("%d", &opcao);
                emFrente(matriz, opcao, nL, nC, onibus, passageiros, &flag_obstaculo);
            }
            break;

        case ALEAT:
            printf("\nMovimento Aleatorio selecionado.\n");
            printf("Digite a quantidade de ciclos para o movimento: ");
            scanf("%d", &nCiclos); // Captura nCiclos localmente para satisfazer o parâmetro
            
            movAleat(matriz, nL, nC, onibus, passageiros, nCiclos);
            break;

        case BUSCINTEL:
            printf("\nBusca Inteligente selecionada.\n");
            buscaInteligente(matriz, nL, nC, onibus, passageiros);
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