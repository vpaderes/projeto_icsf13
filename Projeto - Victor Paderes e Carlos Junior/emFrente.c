#include <stdio.h>
#include <stdlib.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

// opcao: 1 = NORTE, 2 = SUL, 3 = LESTE, 4 = OESTE
// opcao: 5 = NORDESTE, 6 = SUDESTE, 7 = SUDOESTE, 8 = NOROESTE
void emFrente(char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int ciclos, int* contagem_ciclos, char matriz_memoria[MAXL][MAXC][MAXCICLOS]) {
    int l = onibus[0];
    int c = onibus[1];
    int proximo_l = onibus[0];
    int proximo_c = onibus[1];

    int flag_obstaculo = 0, flag_mudamapa = 100;

    int opcao = defineDirecao(&flag_obstaculo);

    while ((*contagem_ciclos)<ciclos) {

        proximo_l = onibus[0];
        proximo_c = onibus[1];

        // Salva qual será a proxima posição
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
        } else if (opcao == 7) { // SUDESTE
            proximo_l++;
            proximo_c++;
        } else if (opcao == 8) { // SUDOESTE
            proximo_l++;
            proximo_c--;
        } else if (opcao == 6) { // NOROESTE
            proximo_l--;
            proximo_c--;
        }

        // Verifica se é borda
        if (proximo_l < 0 || proximo_l >= nL || proximo_c < 0 || proximo_c >= nC) {
            flag_obstaculo = 1;
            opcao = defineDirecao(&flag_obstaculo); //Se é borda, pede nova direção
            continue; 
        } // Verifica se é obstáculo
        if (matriz[proximo_l][proximo_c] == '#') {
            flag_obstaculo = 1;
            opcao = defineDirecao(&flag_obstaculo); // Se é obstáculo pede nova direção e pula o resto do programa, incluindo a contagem
            continue; 
        }

        // Se for livre, executa o movimento
        (*contagem_ciclos)++;
        l = proximo_l;
        c = proximo_c;

        if (matriz[l][c] == P) { // Pega passageiro
            (*passageiros)++;
        }

        // Atualizao onibus na planilha
        matriz[onibus[0]][onibus[1]] = V; 
        matriz[l][c] = B;                 
        
        onibus[0] = l; // salva o vetor do onibus em novas posições
        onibus[1] = c;

        flag_mudamapa = rand()&100+1; //3% de chance de aparecerem objetos e passajeiros aleatórios
        if (flag_mudamapa <= 3) mudaMapa(matriz, nL, nC, onibus);

        imprimeMapa(matriz, nL, nC, passageiros, contagem_ciclos, matriz_memoria);
    }
}