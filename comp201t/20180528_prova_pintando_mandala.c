#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void printMandala (int linhas, int colunas, char mandala[][colunas + 1])
{
    //printf("LINHAS: %d\nCOlunas: %d\n", linhas, colunas);   
    int i, j;      
    for(i=0;i<linhas;i++)
    {
        for(j=0;j<colunas;j++)
        {
            printf("%c", mandala[i][j]);
        }
        printf("\n");
    }
}

void pintandoMandala (int linhas, int colunas, char mandala[][100], int i, int j, char cor)
{
    if ( (i < 0 || i >= linhas || j < 0 || j >= colunas ) || (mandala[i][j] == cor || mandala[i][j] == '#') )
    {
        return;
    }
    mandala[i][j] = cor;
    pintandoMandala(linhas,colunas,mandala,i-1,j,cor); //cima
    pintandoMandala(linhas,colunas,mandala,i+1,j,cor); //baixo
    pintandoMandala(linhas,colunas,mandala,i,j-1,cor); //esquerda
    pintandoMandala(linhas,colunas,mandala,i,j+1,cor); //direita;
}

int main ()
{
    int linhas, colunas;
    char mandala[100][100];
    scanf("%d%d",&linhas,&colunas);
    int i, j, t, cont;
    char cor;
    for(i=0;i<linhas;i++)
    {
        for(j=0;j<colunas;j++)
        {
            scanf(" %c",&mandala[i][j]);
        }
    }
    //printMandala(linhas,colunas,mandala);
    scanf("%d",&t);
    //  printf("%d",t);
    for(cont=0;cont<t;cont++)
    {
        scanf("%d%d %c",&i,&j,&cor);
        //printf("%d %d %c\n", i, j, cor);
        pintandoMandala(linhas,colunas,mandala,i,j,cor);
        
        for (i = 0; i < linhas; i++)
        {
            for (j = 0; j < colunas; j++)
            {
                printf("%c", mandala[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        //printMandala(linhas,colunas,mandala);
        //printf("\n");
    }

    //printf(" CU\n");    
    return 0;
}