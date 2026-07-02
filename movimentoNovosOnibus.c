#include <stdio.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"


void movimentoNovosOnibus(Mapa *Cidade, int *onibus, int* passageiros, int* contagemCiclos)
{
	int i, j, segundo_onibus[2], contagem_temporaria;


	for(i = 0; i < Cidade->nL; i++)
		for(j = 0; j < Cidade->nC; j++)
		{
			if(i == onibus[0] && j == onibus[1]);
			{
				continue;
		    }else if (Cidade->matriz[contagemCiclos][i][j] == B){  
                segundo_onibus[0] = i;
                segundo_onibus[1] = j;

                contagem_temporaria = Cidade->nCiclos - 1;
                movAleat(&Cidade, segundo_onibus, passageiros, contagem_temporaria);

            }
	}	}
}