#include <stdio.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void movimentaOnibus(char matriz[MAXL][MAXC], int mov, int nL, int nC, int* onibus, int *passageiros) {

    int flag_obstaculo = 0;
    // o "if" abaixo verifica o tipo de movimento
    if (mov == 1) {
        int opcao = 0;
        printf("\nSeguindo em frente\n"); // Está decidido que vamos seguir em frente, o menu abaixo capta a opção de direção, se é N S L O, etc

        printf("Digite a direção do onibus:\n");
        printf("(1)N  (2)S  (3)L  (4)O\n(5)NE  (6)NO  (7)SE  (8)SO\n\n");
        scanf("%d", &opcao);

        // O "while" verifica se a entrada do usuário foi feita com valores válidos
        while(opcao<1 || opcao>8) {
            if(opcao<1||opcao>8) {
                printf("Opcao invalida! Digite novamente:\n");
                printf("(1)N  (2)S  (3)L  (4)O\n(5)NE  (6)NO  (7)SE  (8)SO\n\n");
                scanf("%d", &opcao);
            }
        }

        // Após a verificação de entrada válida, chamamos a função do movimento específico
        emFrente(matriz, opcao, nL, nC, onibus, passageiros, &flag_obstaculo);
        while (flag_obstaculo ==1)
        {
            printf("Encontramos um obstaculo! Digite nova direcao:\n");
            printf("(1)N  (2)S  (3)L  (4)O\n(5)NE  (6)NO  (7)SE  (8)SO\n\n");
            scanf("%d", &opcao);
            emFrente(matriz, opcao, nL, nC, onibus, passageiros, &flag_obstaculo);
        }
        

    }
}