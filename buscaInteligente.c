#include <stdio.h>
#include <stdlib.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void buscaInteligente(char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int ciclos) {
    int l_onibus = onibus[0];
    int c_onibus = onibus[1];
    int alvo_l = -1, alvo_c = -1;
    int encontrou = 0;
    int aux = ciclos;
    

    while(ciclos >= 0) {
        encontrou = 0;
        // 1. Busca pelo passageiro em um raio de 1 até 3
        for (int raio = 1; raio <= 3 && encontrou!=1; raio++) {
            for (int i = l_onibus - raio; i <= l_onibus + raio && encontrou !=1; i++) {
                for (int j = c_onibus - raio; j <= c_onibus + raio && encontrou !=1; j++) {
                    
                    if (i < 0 || i >= nL || j < 0 || j >= nC) continue;

                    if (abs(i - l_onibus) == raio || abs(j - c_onibus) == raio) {
                        if (matriz[i][j] == P) {
                            alvo_l = i;
                            alvo_c = j;
                            encontrou = 1;
                        }
                    }
                }
            }
        }

        // Se não encontrou passageiro no raio, encerra a função
        if (encontrou == 0) {

            movAleat(matriz, nL, nC, onibus, passageiros, ciclos);
        }

        // 2. Loop de movimentação até a coordenada do passageiro
        while (onibus[0] != alvo_l || onibus[1] != alvo_c) {
            int proximo_l = onibus[0];
            int proximo_c = onibus[1];

            // Determina o próximo passo ideal (reduz a distância em linha e coluna)
            if (alvo_l < onibus[0]) proximo_l--;
            else if (alvo_l > onibus[0]) proximo_l++;

            if (alvo_c < onibus[1]) proximo_c--;
            else if (alvo_c > onibus[1]) proximo_c++;

            // 3. Verifica colisão com limites da matriz ou obstáculos no caminho ideal
            if (proximo_l < 0 || proximo_l >= nL || proximo_c < 0 || proximo_c >= nC || matriz[proximo_l][proximo_c] == '#') {
                
                // Invoca a função criada para buscar alternativa livre
                int* casa_livre = testeVizinhos(matriz, nL, nC, onibus);
                
                if (casa_livre != NULL) {
                    proximo_l = casa_livre[0];
                    proximo_c = casa_livre[1];
                    free(casa_livre);
                } else {
                    // Preso completamente: obstáculo à frente e nenhuma casa vazia ao redor
                    break; 
                }
            }

            // 4. Executa o movimento
            int l_antigo = onibus[0];
            int c_antigo = onibus[1];

            onibus[0] = proximo_l;
            onibus[1] = proximo_c;

            // Se o espaço para o qual andamos contém o passageiro
            if (matriz[onibus[0]][onibus[1]] == P) { 
                (*passageiros)++;
            }

            // Atualização visual e ponteiros na matriz
            matriz[l_antigo][c_antigo] = V; 
            matriz[onibus[0]][onibus[1]] = B; // B representa a posição atual do ônibus
            
            imprimeMapa(matriz, nL, nC);
        }
            ciclos--;
    }
    


    printf("\n\nPassageiros totais: %d\n", *passageiros);
    printf("Ciclos percorridos: %d\n\n", aux);
}

