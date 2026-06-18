#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

// Adicionado nCiclos como parâmetro, já que era usado na função original
void movAleat(char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int nCiclos)
{
    do
    {
        // 1. Sorteia a direção a CADA passo
        int direcao = rand() % 8 + 1; 
        
        int proximo_l = onibus[0];
        int proximo_c = onibus[1];

        // 2. Define o deslocamento com base na direção
        switch(direcao)
        {
            case 1: proximo_l--; break;              // NORTE
            case 2: proximo_l++; break;              // SUL
            case 3: proximo_c++; break;              // LESTE
            case 4: proximo_c--; break;              // OESTE
            case 5: proximo_l--; proximo_c++; break; // NORDESTE
            case 6: proximo_l++; proximo_c++; break; // SUDESTE
            case 7: proximo_l++; proximo_c--; break; // SUDOESTE
            case 8: proximo_l--; proximo_c--; break; // NOROESTE
        }

        // 3. Verifica limites da matriz (bordas)
        if(proximo_l >= 0 && proximo_l < nL && proximo_c >= 0 && proximo_c < nC)
        {
            // 4. Verifica colisão com obstáculo
            if(matriz[proximo_l][proximo_c] != '#') 
            {
                // Se for passageiro, embarca
                if(matriz[proximo_l][proximo_c] == P)
                {
                    (*passageiros)++;
                    printf("\n\nPassageiros: %d\n\n", *passageiros);
                }

                // Executa o movimento na matriz
                matriz[onibus[0]][onibus[1]] = V; // Limpa a posição antiga
                matriz[proximo_l][proximo_c] = B; // Desenha o ônibus na nova posição
                
                // Atualiza o vetor do ônibus
                onibus[0] = proximo_l;
                onibus[1] = proximo_c;
            }
        }
        
        nCiclos--;
        imprimeMapa(matriz, nL, nC);
        
    } while(nCiclos > 0);
}