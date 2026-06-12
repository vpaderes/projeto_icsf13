#include <stdio.h>
#include <stdlib.h>
// #include <windows.h>
#include <time.h>

#define EMFRENTE 1
#define ALEAT 2
#define BUSCINTEL 3
#define MIX 4

#define N 1
#define S 2
#define L 3
#define W 4
#define NE 5
#define NO 6
#define SE 7
#define SO 8

#define B 'B'
#define P 'P'
#define V '.'


void escolheMovimento(int mov)
{
    int moveu = 100;

    while (moveu != 0)
    {

        switch(mov)
        {
            case EMFRENTE:
                //movimentaOnibus();
                moveu = 0;
                break;
            case ALEAT:
                //movAleatorio();
                moveu = 0;
                break;
            case BUSCINTEL:
                //buscaIntel();
                moveu = 0;
                break;
            case MIX:
                //movMix();
                moveu = 0;
                break;
            default:
                printf("Opcao invalida!\nDigite novamente\n");
                scanf("%d", &mov);
        }
    }   
}

int main(void)
{
    char a[20][20];
    int mov = 1, opcao = 1;
    
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
            a[i][j] = '.';

    a[0][0] = 'P';
    a[0][2] = 'P';
    a[1][2] = '#';
    a[1][3] = '#';
    a[1][4] = '#';
    a[2][1] = 'P';
    a[2][11] = 'P';
    a[2][16] = '#';
    a[4][6] = 'P';
    a[6][6] = 'P';
    a[6][19] = 'P';
    a[11][3] = 'P';
    a[11][11] = 'P';
    a[12][19] = 'P';
    a[13][7] = '#';
    a[14][7] = '#';
    a[14][14] = 'P';
    a[15][7] = '#';
    a[16][3] = 'P';
    a[16][16] = 'P';
    a[16][19] = 'P';
    a[19][1] = 'P';
    a[19][6] = 'P';
    a[19][10] = 'P';
    a[19][19] = 'B';

    for(int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            printf("%2c", a[i][j]);
        }
        printf("\n");
    }
    

    // criar funcao para o menu e colocar no while da main
    printf("Menu de Movimentações\n");
    printf("Digite 1 para N\nDigite 2 para S\nDigite 3 para L\nDigite 4 para W\nDigite 5 para NE\nDigite 6 para NO\nDigite 7 para SE\nDigite 8 para SO\n");
    scanf("%d", &opcao);

    return 0;
}

