#include <stdio.h>
#include <stdlib.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

// a opcao aqui é definida no menu de tipo de movimento e significa a direção N S L O, etc
void emFrente(char matriz[MAXL][MAXC], int opcao, int nL, int nC, int* onibus, int *passageiros){

    int ciclos = 0, posicao_livre = 1;

    // Controlo as direções do onibus pelos "if" dentro do laço, de maneira que o onibus andará no máximo uma vez por casa, controlando com a variável "ciclos"
    // As linhas sempre serão controladas por [l] e as colunas sempre serão controladas por [c]
    
    int l =onibus[0], c =onibus[1];
    while(ciclos <nL*nC){

        ciclos++;
        
        if (matriz[l][c] != '#') {
            if (matriz[l][c] == P){ //Verifica se é passageiro

            *passageiros=*passageiros+1;
            printf("\n\nPassageiros: %d\n\n", *passageiros);

            }
            matriz[l][c] = B; // Verifica se for obstáculo, só move o ônibus se não for
            matriz[onibus[0]][onibus[1]] = V; // limpa a célula da posição anterior  para vazio
            onibus[0]=l; // Muda a célula da posição do onibus
            onibus[1]=c;

        }
        imprimeMapa(matriz, nL, nC);
        if(ciclos == nL*nC){ //Ao final, printa a quantidade de ciclos e a quantidade de passageiros
            printf("\n\nPassageiros: %d\n\n", *passageiros);
            printf("\n\nCiclos: %d\n\n", ciclos);
        }
        if(opcao == 1){// NORTE
            l--;
            if(l<0){
                l = nL-1;
                c++;
                if (c>=nC){
                c=0;
                }
            }

        }

        if(opcao == 2){// SUL
            l++;
            if(l==nL){
                l=0;
                c++;
                if(c==nC){
                    c=0;
                }
            }
        }

        if(opcao == 3){// LESTE
            c++;
            if(c==nC){
                c=0;
                l++;
                if(l==nL){
                    l=0;
                }
            }
        }
        if(opcao == 4){// OESTE
            c--;
            if(c==0){
                c=nC-1;
                l++;
                if(l==nL){
                    l=0;
                }
            }
        }

    }

}