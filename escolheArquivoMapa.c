#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_ARQUIVOS 50
#define TAM_NOME 50

// A função agora recebe um ponteiro onde o nome do arquivo escolhido será salvo
void escolheArquivoMapa(char *arquivoEscolhido) 
{
    DIR *Mapas;
    struct dirent *arquivo;
    char listaArquivos[MAX_ARQUIVOS][TAM_NOME];//Máximo de 50 mapas com nome de no máximo 50 tbm
    int contador = 0;
    int escolha;

    Mapas = opendir("./Mapas");
    if (Mapas == NULL)
    {
        printf("Erro ao abrir diretorio ./Mapas\n");
        arquivoEscolhido[0] = '\0'; // Retorna string vazia em caso de erro
        return;
    }

    printf("Mapas disponiveis:\n");

    // Lê o diretório e armazena os nomes no array
    while((arquivo = readdir(Mapas)) != NULL && contador < MAX_ARQUIVOS) 
    { //strcmp dá valor 0 se as strings forem iguais
        if (strcmp(arquivo->d_name, ".") != 0 && strcmp(arquivo->d_name, "..") != 0) { //compara o nome dos arquivos para evitar a pasta atual e a pasta anterior
            strcpy(listaArquivos[contador], arquivo->d_name);
            printf("[%d] %s\n", contador + 1, listaArquivos[contador]);
            contador++;
        }
    }
    closedir(Mapas);

    if (contador == 0) {//Verificação de erro na leitura dos mapas
        printf("Nenhum mapa encontrado na pasta.\n");
        arquivoEscolhido[0] = '\0';
        return;
    }

    // Pede para o usuário digitar um valor válido dentre o número de mapas disponíveis e retorna no loop se ele não digitar.
    do {
        printf("Escolha o mapa pelo numero (1 a %d): ", contador);
        scanf("%d", &escolha);
    } while (escolha < 1 || escolha > contador);

    // Copia o nome do arquivo correspondente para o vetor de arquivoEscolhido
    strcpy(arquivoEscolhido, listaArquivos[escolha - 1]);
}