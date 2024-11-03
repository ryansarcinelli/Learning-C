#include <stdio.h>
#include <stdlib.h>
/*Escreva um programa que leia duas matrizes bidimensionais reais MAT1 e MAT2 de dimensões 3x5
cada, calcule e imprima a matriz soma MSOMA. */

int main()
{
    int l=3, c=5;
    int mat1[l][c], mat2[l][c], msoma[l][c];

    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("Digite  o numero da posicao %d %d da matriz 1:\n", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("Digite  o numero da posicao %d %d da matriz 2:\n", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c;j++)
        {
            msoma[i][j] = mat1[i][j] + mat2[i][j];
            printf("%d ", msoma[i][j]);
        }
        printf("\n");
    }

    return 0;
}