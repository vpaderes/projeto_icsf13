#include <stdio.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

int defineDirecao(int *flag_obstaculo){
    int opcao = 0;
    if ((*flag_obstaculo) == 0){
        printf("Digite a direcao do onibus:\n");
        printf("(1)N  (2)S  (3)L  (4)O\n(5)NE  (6)NO  (7)SE  (8)SO\n\n");
        scanf("%d", &opcao);

        // Verifica se a entrada do usuário foi feita com valores válidos
        while (opcao < 1 || opcao > 8) {
            printf("Opcao invalida! Digite novamente:\n");
            printf("(1)N  (2)S  (3)L  (4)O\n(5)NE  (6)NO  (7)SE  (8)SO\n\n");
            scanf("%d", &opcao);
        }
    } else if ((*flag_obstaculo) == 1) {
        printf("Encontramos um obstaculo! Digite nova direcao:\n");
        printf("(1)N  (2)S  (3)L  (4)O\n(5)NE  (6)NO  (7)SE  (8)SO\n\n");
        scanf("%d", &opcao);
        (*flag_obstaculo) = 0;
    }
        
return opcao;}