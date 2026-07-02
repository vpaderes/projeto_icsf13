#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void movAleat(Mapa *Cidade, int* onibus, int *passageiros, int* contagem_ciclos, int limite_ciclos)
{
    int flag_mudamapa = 100;
    while((*contagem_ciclos)<limite_ciclos)
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
        if(proximo_l >= 0 && proximo_l < Cidade->nL && proximo_c >= 0 && proximo_c < Cidade->nC)
        {
            // Verifica se não é obstáculo
            if(Cidade->matriz[*contagem_ciclos][proximo_l][proximo_c] != '#') 
            {
                (*contagem_ciclos)++; //Conta ciclo

                // Se for passageiro, embarca
                if(Cidade->matriz[*contagem_ciclos][proximo_l][proximo_c] == P)
                {
                    (*passageiros)++;
                    printf("\n\nPassageiros: %d\n\n", *passageiros);
                }

                // Já que não é nem borda e nem obstáculo, move o ônibus
                Cidade->matriz[*contagem_ciclos][onibus[0]][onibus[1]] = V; // Limpa a posição antiga
                Cidade->matriz[*contagem_ciclos][proximo_l][proximo_c] = B; // Move para nova posição
                onibus[0] = proximo_l;
                onibus[1] = proximo_c;
                
            }
        } else continue; //Se não for livre, roda mais um loop para achar a casa livre

        transitoEmergencial(Cidade, contagem_ciclos);
        
        
        flag_mudamapa = rand()%100+1;//5% de chance de aparecerem objetos e passajeiros aleatórios
        if (flag_mudamapa <= 5) mudaMapa(Cidade, onibus, contagem_ciclos);
        imprimeMapa(Cidade, passageiros, contagem_ciclos);
    }    
}
