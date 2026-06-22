#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void movAleat(char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int ciclos, int* contagem_ciclos, char matriz_memoria[MAXL][MAXC][MAXCICLOS])
{
    int flag_mudamapa = 100;
    while((*contagem_ciclos)<ciclos)
    {
        //Sorteia o numero para a direção
        int direcao = rand() % 8 + 1; 
        //Cria variáveis para calcular e verificar a próxima casa
        int proximo_l = onibus[0];
        int proximo_c = onibus[1];

        // Associa a cada número uma direção
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

        // Verifica as boradas
        if(proximo_l >= 0 && proximo_l < nL && proximo_c >= 0 && proximo_c < nC)
        {
            // Verifica se não é obstáculo
            if(matriz[proximo_l][proximo_c] != '#') 
            {
                // Se for passageiro, embarca
                if(matriz[proximo_l][proximo_c] == P)
                {
                    (*passageiros)++;
                    printf("\n\nPassageiros: %d\n\n", *passageiros);
                }

                // Já que não é nem borda e nem obstáculo, move o ônibus
                matriz[onibus[0]][onibus[1]] = V; // Limpa a posição antiga
                matriz[proximo_l][proximo_c] = B; // Move para nova posição
                onibus[0] = proximo_l;
                onibus[1] = proximo_c;
                
            }
        } else continue; //Se não for livre, roda mais um loop para achar a casa livre
        
        (*contagem_ciclos)++; //Conta ciclo
        flag_mudamapa = rand()&100+1;//3% de chance de aparecerem objetos e passajeiros aleatórios
        if (flag_mudamapa <= 3) mudaMapa(matriz, nL, nC, onibus);
        imprimeMapa(matriz, nL, nC, passageiros, contagem_ciclos, matriz_memoria);
    }    
}
