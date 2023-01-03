#include <stdio.h>
#include <stdlib.h>
/*Escreva um programa que leia duas matrizes reais A e B de dimensões 3x5 e 5x3, respectivamente,
calcule e imprima o produto delas. */

int main()
{
    int p=0, q=0, m=0, n=0;
    int a[10][10], b[10][10], res[10][10];

    printf("Digite as dimensoes da primeira matriz\n");
    scanf("%d%d", & m, & n);
    printf("Digite as dimensoes da segunda matriz\n");
    scanf("%d%d", & p, & q);

    printf("Digite os valores da matriz A (%dx%d):\n", m, n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("Digite os valores da matriz B (%dx%d):\n", p, q);
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<q;j++)
        {
            res[i][j] = 0;
            for(int k=0;k<p;k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("A matriz resultante e: \n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<q;j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}