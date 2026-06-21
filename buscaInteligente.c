#include <stdio.h>
#include <stdlib.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void buscaInteligente(char matriz[MAXL][MAXC], int nL, int nC, int* onibus, int *passageiros, int ciclos, int* contagem_ciclos) {
    int l_onibus;
    int c_onibus;
    int alvo_l = -1, alvo_c = -1;
    int encontrou = 0;
    

    while((*contagem_ciclos)<ciclos) {
        l_onibus = onibus[0];
        c_onibus = onibus[1];
        encontrou = 0;
        // Os loops abaixo buscam pelo passageiro em um raio de 1 até 3
        for (int raio = 1; raio <= 3 && encontrou!=1; raio++) {
            for (int i = l_onibus - raio; i <= l_onibus + raio && encontrou !=1; i++) { //Testa cada uma das linhas de l_onibus - 3  até l_onibus + 3 
                for (int j = c_onibus - raio; j <= c_onibus + raio && encontrou !=1; j++) { //Testa cada uma das colunas de c_onibus - 3  até c_onibus + 3 
                    
                    if (i < 0 || i >= nL || j < 0 || j >= nC) continue; //Não vefifica além das bordas

                    if (abs(i - l_onibus) == raio || abs(j - c_onibus) == raio) {
                        if (matriz[i][j] == P) {
                            alvo_l = i;
                            alvo_c = j;
                            encontrou = 1; //Muda a flag "encontrou" para a condição de parada.
                        }
                    }
                }
            }
        }

        
        if (encontrou == 0) { //Se não encontrou passageiros, chama a função move aleatório com 1 ciclo
            int contagem_ciclos_temporaria = 0;
            movAleat(matriz, nL, nC, onibus, passageiros, 1, &contagem_ciclos_temporaria);
            (*contagem_ciclos)++;
            continue;; // sai desse loop.
        } else {

            // Caso encontrar um passageiro, executa o código abaixo:
            while ((onibus[0] != alvo_l || onibus[1] != alvo_c) && (*contagem_ciclos)<ciclos) {
                //Cria inicializa para calcular e checar qual é o proximo passo
                int proximo_l = onibus[0];
                int proximo_c = onibus[1];

                // Os if-else abaixo movem as variáveis de próximo passo
                if (alvo_l < onibus[0]) proximo_l--; //Norte
                else if (alvo_l > onibus[0]) proximo_l++;//Sul
                if (alvo_c < onibus[1]) proximo_c--;//Oeste
                else if (alvo_c > onibus[1]) proximo_c++;//Leste

                // O bloco abaixo verifica se as variáveis de próximo passo não vão bater em um obstáculo ou borda
                if (proximo_l < 0 || proximo_l >= nL || proximo_c < 0 || proximo_c >= nC || matriz[proximo_l][proximo_c] == '#') {
                    
                    // Se não for uma casa livre, chama a função de testar vizinhos
                    int* casa_livre = testeVizinhos(matriz, nL, nC, onibus);
                    
                    if (casa_livre[0] != -1 && casa_livre[1] != -1) { //Verifica se há alguma casa livre que a função retornou. Se nçao  houver, ela retorna -1
                        proximo_l = casa_livre[0];
                        proximo_c = casa_livre[1];
                    } else {
                        exit(1); 
                    }
                }

                // Guarda os valores da ultima casa para limpar mais tarde.
                int l_antigo = onibus[0];
                int c_antigo = onibus[1];
                //Move o onibus para a proxima casa
                onibus[0] = proximo_l;
                onibus[1] = proximo_c;

                // Pega o passageiro, se for o caso
                if (matriz[onibus[0]][onibus[1]] == P) { 
                    (*passageiros)++;
                }

                //Move o onibus na matriz e limpa casa anterior
                matriz[l_antigo][c_antigo] = V; 
                matriz[onibus[0]][onibus[1]] = B; 
                (*contagem_ciclos)++;
                imprimeMapa(matriz, nL, nC, passageiros, contagem_ciclos);
            }
            
        }
    }
}

