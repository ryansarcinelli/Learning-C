#include <stdio.h>
#include <stdlib.h>
/*Calcule e imprima a soma dos elementos situados abaixo da diagonal principal da matriz A (dimensões
10x10), incluindo os elementos da própria diagonal. */

int main()
{
    int size=10, m1[size][size], total=0;

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("Digite o valor da posicao %d, %d da matriz:\n", i, j);
            scanf("%d", &m1[i][j]);
            if(i==j)
            total = total + m1[i][j];
        }
    }
    printf("O valor da soma da diagonal principal e: %d", total);
    return 0;
}