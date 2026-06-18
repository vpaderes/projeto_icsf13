#include <stdio.h>
#include <stdlib.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

// opcao: 1 = NORTE, 2 = SUL, 3 = LESTE, 4 = OESTE
// opcao: 5 = NORDESTE, 6 = SUDESTE, 7 = SUDOESTE, 8 = NOROESTE
void emFrente(char matriz[MAXL][MAXC], int opcao, int nL, int nC, int* onibus, int *passageiros, int*flag_obstaculo) {
    int ciclos = 0;
    int l = onibus[0];
    int c = onibus[1];

    *flag_obstaculo = 0;

    while (ciclos<nL*nC) {
        int proximo_l = l;
        int proximo_c = c;

        // 1. Projeta a próxima posição
        if (opcao == 1) { // NORTE
            proximo_l--;
        } else if (opcao == 2) { // SUL
            proximo_l++;
        } else if (opcao == 3) { // LESTE
            proximo_c++;
        } else if (opcao == 4) { // OESTE
            proximo_c--;
        } else if (opcao == 5) { // NORDESTE
            proximo_l--;
            proximo_c++;
        } else if (opcao == 6) { // SUDESTE
            proximo_l++;
            proximo_c++;
        } else if (opcao == 7) { // SUDOESTE
            proximo_l++;
            proximo_c--;
        } else if (opcao == 8) { // NOROESTE
            proximo_l--;
            proximo_c--;
        }

        // 2. Verifica limites da matriz
        if (proximo_l < 0 || proximo_l >= nL || proximo_c < 0 || proximo_c >= nC) {
            *flag_obstaculo = 1;
            break; 
        }

        // 3. Verifica colisão com obstáculos
        if (matriz[proximo_l][proximo_c] == '#') {
            *flag_obstaculo = 1;
            break; 
        }

        // 4. Executa o movimento
        ciclos++;
        l = proximo_l;
        c = proximo_c;

        if (matriz[l][c] == P) { 
            (*passageiros)++;
        }

        // Atualização visual e ponteiros
        matriz[onibus[0]][onibus[1]] = V; 
        matriz[l][c] = B;                 
        
        onibus[0] = l;
        onibus[1] = c;

        imprimeMapa(matriz, nL, nC);
    }

    printf("\n\nPassageiros totais: %d\n", *passageiros);
    
    printf("Ciclos percorridos: %d\n\n", ciclos);

}