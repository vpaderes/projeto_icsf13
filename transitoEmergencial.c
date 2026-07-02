#include <stdio.h>
#include <stdlib.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void transitoEmergencial(Mapa *Cidade, int* contagem_ciclos) {
    // Surgimento aleatório 5% de chance de ocorrer
    if ((rand() % 100 + 1) <= 5) {
        int qtd_novos = (rand() % 30) + 1; // Sorteia entre 1 e 30 ônibus

        for (int k = 0; k < qtd_novos; k++) {
            // Procura um espaço livre no vetor para registrar o novo ônibus
            int slot_livre = -1;
            for (int i = 0; i < 30; i++) {
                if (Cidade->inimigo_ativo[i] == 0) {
                    slot_livre = i;
                    break;
                }
            }

            // Se achou espaço na memória, tenta colocar no mapa
            if (slot_livre != -1) { // Se o espaço no array está ocupado por um onibus
                // Limite de 50 tentativas
                for (int tentativas = 0; tentativas < 50; tentativas++) {
                    int aleatL = rand() % Cidade->nL;
                    int aleatC = rand() % Cidade->nC;

                    if (Cidade->matriz[*contagem_ciclos][aleatL][aleatC] == V) {
                        Cidade->onibus_inimigo[slot_livre][0] = aleatL;
                        Cidade->onibus_inimigo[slot_livre][1] = aleatC;
                        Cidade->matriz[*contagem_ciclos][aleatL][aleatC] = B;
                        Cidade->inimigo_ativo[slot_livre] = 1;
                        break; // Deu certo, sai do loop de tentativas e vai pro próximo ônibus
                    } 
                    else if (Cidade->matriz[*contagem_ciclos][aleatL][aleatC] == B) { //Verifica se já  é um onibus no local
                        printf("\nNovo bloqueio detectado na cidade.\n");
                        Cidade->matriz[*contagem_ciclos][aleatL][aleatC] = '#';
                        break; // Desiste desse ônibus e ele vira bloqueio -  N~ao coloca nada nos indidces
                    }
                }
            }
        }
    }

    // Movimentação dos ônibus secundários ativos
    // Vê todos os 30 espaços e movimenta apenas os ativos
    for (int i = 0; i < 30; i++) {
        if (Cidade->inimigo_ativo[i] == 1) {
            int direcao = rand() % 8 + 1;
            int proximo_l = Cidade->onibus_inimigo[i][0];
            int proximo_c = Cidade->onibus_inimigo[i][1];

            switch(direcao) {
                case 1: proximo_l--; break;
                case 2: proximo_l++; break;
                case 3: proximo_c++; break;
                case 4: proximo_c--; break;
                case 5: proximo_l--; proximo_c++; break;
                case 6: proximo_l++; proximo_c++; break;
                case 7: proximo_l++; proximo_c--; break;
                case 8: proximo_l--; proximo_c--; break;
            }

            // Verifica se está dentro das bordas
            if(proximo_l >= 0 && proximo_l < Cidade->nL && proximo_c >= 0 && proximo_c < Cidade->nC) {
                char destino = Cidade->matriz[*contagem_ciclos][proximo_l][proximo_c];

                if(destino != '#') {
                    if(destino == B) { 
                        // Ocorre a colisão e vira bloqueio fixo
                        printf("\nNovo bloqueio detectado na cidade.\n");
                        Cidade->matriz[*contagem_ciclos][proximo_l][proximo_c] = '#';
                        Cidade->matriz[*contagem_ciclos][Cidade->onibus_inimigo[i][0]][Cidade->onibus_inimigo[i][1]] = V;
                        Cidade->inimigo_ativo[i] = 0; // Inativa o ônibus
                        Cidade->onibus_inimigo[i][0] = -1;
                    } else if (destino == V) { 
                        // Movimento bem-sucedido para casa livre
                        Cidade->matriz[*contagem_ciclos][Cidade->onibus_inimigo[i][0]][Cidade->onibus_inimigo[i][1]] = V;
                        Cidade->matriz[*contagem_ciclos][proximo_l][proximo_c] = B;
                        Cidade->onibus_inimigo[i][0] = proximo_l;
                        Cidade->onibus_inimigo[i][1] = proximo_c;
                    }
                }
            }
        }
    }
}