#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defines_projeto.h"
#include "prototipos_projeto.h"

void preencheMatriz(Mapa *Cidade, int* onibus)
{

    Cidade->nCiclos = -1;
    while (Cidade->nCiclos<=0 || Cidade->nCiclos>MAXCICLOS){
        printf("\nDigite a quantidade de ciclos para percorrer na cidade:\n");
        scanf("%d", &Cidade->nCiclos);
        if(Cidade->nCiclos<=0 || Cidade->nCiclos>MAXCICLOS) printf("Opcao invalida! Deve ser entre 1 e 100. Digite novamente:\n");
    }
    
    char nomeDoMapa[256]; // Vetor para guardar qual é o nome do mapa escolhido
    escolheArquivoMapa(nomeDoMapa);

    if (nomeDoMapa[0] != '\0') {//Verifica se deu certo de pegar algum nome de mapa
        printf("Voce escolheu abrir o arquivo: ./Mapas/%s\n", nomeDoMapa);
    } else {
        printf("\n Erro na escolha do mapa. Encerrando o programa.\n"); // Se não deu certo encerra o programa
        exit(1);
    }
    char caminhoCompleto[512];
    snprintf(caminhoCompleto, sizeof(caminhoCompleto), "./Mapas/%s", nomeDoMapa);

    //Colocar chamada da função de ler o arquivo do mapa e salvar na nossa matriz

    FILE *mapa_csv = fopen(caminhoCompleto, "r");
    if (mapa_csv == NULL) { // Tratamento de erros
        printf("\nErro ao abrir o mapa");
        exit(1);
    }

    char linha_do_arquivo[10]; // Char par aler as strings do mapa
    int contagem_de_linhas = 0;
    int linha_csv, coluna_csv;
    char item_csv;

    while (fgets(linha_do_arquivo, sizeof(linha_do_arquivo), mapa_csv) != NULL) {

        if(contagem_de_linhas == 0){
            sscanf(linha_do_arquivo, "%d,%d", &Cidade->nL, &Cidade->nC); //Lê a quantidade de linhas e colunas

            // Aloca espaço para a matriz
            Cidade->matriz = malloc(Cidade->nCiclos * sizeof(char**));
            for (int i = 0; i<Cidade->nCiclos; i++){
                Cidade->matriz[i] = malloc(Cidade->nL * sizeof(char*));
                for (int j = 0; j<Cidade->nL; j++){
                    Cidade->matriz[i][j] = malloc(Cidade->nC* sizeof(char));
                }
            }

            for(int i=0;i<Cidade->nCiclos; i++){
                for(int j=0; j<Cidade->nL;j++){
                    for(int k=0; k<Cidade->nC;k++){
                        Cidade->matriz[i][j][k] = V;
                    }
                }
            }


        } else {
            
            if (sscanf(linha_do_arquivo, "%d,%d,%c", &linha_csv, &coluna_csv, &item_csv) == 3) {
            Cidade->matriz[0][linha_csv][coluna_csv] = item_csv;
            }
        }
        contagem_de_linhas++;
    }

    fclose(mapa_csv);

    for (int i = 0; i < Cidade->nL; i++)
    {
        for (int j = 0; j < Cidade->nC; j++)
        {
            if (Cidade->matriz[0][i][j] == B){
                onibus[0] = i;
                onibus[1] = j;
            }
        }
        
    }


}
