#include <stdio.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"


void criaOnibus(Mapa *Cidade)
{
	int i, achou = 0, aleatL, aleatC;
	int novoOnibus[2];

	while(achou != 1)
	{
		aleatL = rand()%Cidade->nL;
		aleatC = rand()%Cidade->nC;

		if(Cidade->matriz[aleatL][aleatC] == B)
		{
			printf("Novo bloqueio detectado na cidade.");
			Cidade->matriz[aleatL][aleatC] = '#';
			achou = 1;
		}
		else if(Cidade->matriz[aleatL][aleatC] == V)
		{
			novoOnibus[0] = aleatL;
			novoOnibus[1] = aleatC;
			Cidade->matriz[aleatL][aleatC] = B;
			achou = 1;
		}
	}
}
