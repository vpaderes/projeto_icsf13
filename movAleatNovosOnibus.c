#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void movNovosAleat(Mapa *Cidade, int onibus, int *antigo_onibus, int* passageiros, int* contagem_ciclos)
{
    int flag_mudamapa = 100;
    while((*contagem_ciclos)<Cidade->ciclos)
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

        // Verifica as beiradas
        if(proximo_l >= 0 && proximo_l < Cidade->nL && proximo_c >= 0 && proximo_c < Cidade->nC)
        {
            // Verifica se não é obstáculo
            if(Cidade->matriz[proximo_l][proximo_c] != '#') 
            {
                // Se for passageiro, embarca
                if(Cidade->matriz[proximo_l][proximo_c] == P)
                	(*passageiros)++;

                // Já que não é nem borda e nem obstáculo, move o ônibus
		if(Cidade->matriz[proximo_l][proximo_c] == B && Cidade->matriz[proximo_l][proximo_c] != Cidade->matriz[antigo_onibus[0]][antigo_onibus[1])
		{
			printf("Novo bloqueio detectado na cidade.");
			Cidade->matriz[proximo_l][proximo_c] = '#';
		}
                
            }
        } else continue;
        
        (*contagem_ciclos)++; //Conta ciclo
        flag_mudamapa = rand()%100+1;//5% de chance de aparecerem objetos e passajeiros aleatórios
        if (flag_mudamapa <= 5) mudaMapa(matriz, nL, nC, onibus);
        imprimeMapa(Cidade->matriz, Cidade->nL, Cidade->nC, passageiros, contagem_ciclos);
    }    
}
