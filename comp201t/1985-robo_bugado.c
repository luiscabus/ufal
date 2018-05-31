#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// void percorrendoLabirinto(int x, int y, int *maior, char direcao[], int cont, int n, int atual)
// {
//     //printf("%d = cont\n",cont);
//     int aux;
//     if(x == 0 && y == 0 && cont != 0)
//     {
//         //printf("%d",total);
//         if(cont > *maior)
//         {
//           *maior = cont;
//         }
//         return;
//     }
//     if(cont == n)
//     {
//         return;
//     }
//     if(direcao[cont] == 'U')
//     {
//         percorrendoLabirinto(x, y + 1,maior,direcao,cont+1,n,atual); //cima
//     }
//     if(direcao[cont] == 'D')
//     {
//         percorrendoLabirinto(x,y-1,maior,direcao,cont+1,n,atual); //baixo
//     }
//     if(direcao[cont] == 'L')
//     {
//         percorrendoLabirinto(x-1,y,maior,direcao,cont+1,n,atual); //esquerda
//     }
//     if(direcao[cont] == 'R')
//     {
//         percorrendoLabirinto(x+1,y,maior,direcao,cont+1,n,atual); //direita
//     }
//  }

int main ()
{
    int n;
    scanf("%d ",&n);
    char direcao[n];
    int i, total = 0, contU = 0, contD = 0, contL = 0, contR = 0;

    scanf("%s",direcao);
    for(i=0;i<n;i++)
    {
        if(direcao[i] == 'U')
            contU++;
        if(direcao[i] == 'D')
            contD++;
        if(direcao[i] == 'L')
            contL++;
        if(direcao[i] == 'R')
            contR++;
    }
    //printf("%d\n",total);
    if(contU >= contD)
    {
        total += contD * 2;
    }
    else
    {
        total += contU * 2;
    }
    if(contL >= contR)
    {
        total += contR * 2;
    }
    else
    {
        total += contL * 2;
    }
    //percorrendoLabirinto(0,0,&maior,direcao,0,n,0);

    printf("%d",total);

    return 0;
}