#include <stdio.h>

int maior (int cima, int baixo, int esquerda, int direita)
{
    if(baixo > cima)
    {
        cima = baixo;
    }
    if(esquerda > cima)
    {
        cima = esquerda;
    }
    if(direita > cima)
    {
        cima = direita;
    }
    return cima;
}

int percorrendoLabirinto(int linhas, int colunas, char labirinto[linhas][colunas], int i, int j, int total)
{
    char aux;
    if(i < 0 || j < 0 || i >= linhas || j >= colunas || labirinto[i][j] == '#')
    {
        //printf("%d",total);
        return total;
    }

    if(labirinto[i][j] == 'b')
        total += 1;
    
    if(labirinto[i][j] == 'p')
        total += 5;
    
    if(labirinto[i][j] == 'o')
        total += 10;

    if(labirinto[i][j] == 'd')
        total += 50;

    //printf("%d\n",total);
    aux = labirinto[i][j];
    labirinto[i][j] = '#'; //preenchendo a primeira vez que passou no labirinto
    //printf("%d = i\n%d = j\n%d = total\n",i,j,total);    
    int cima = percorrendoLabirinto(linhas,colunas,labirinto,i-1,j,total); //cima
    int baixo = percorrendoLabirinto(linhas,colunas,labirinto,i+1,j,total); //baixo
    int esquerda = percorrendoLabirinto(linhas,colunas,labirinto,i,j-1,total); //esquerda
    int direita = percorrendoLabirinto(linhas,colunas,labirinto,i,j+1,total); //direita
    labirinto[i][j] = aux; //preenchendo o labirinto como ele era antes apï¿½s testar os caminhos
    return maior(cima,baixo,esquerda,direita);
}

int main ()
{
    int linhas, colunas, i, j, total, maior;
    scanf("%d%d",&linhas,&colunas);
    char visitados[linhas][colunas];
    char labirinto[linhas][colunas];

    //preenchendo uma matriz para gerar o labirinto
    for(i=0;i<linhas;i++)
    {
        scanf(" %s",labirinto[i]);
    }
    
    printf("%d",percorrendoLabirinto(linhas,colunas,labirinto,0,0,0));    //printf("%d",total);

    return 0;
}