#include <stdio.h>
/*Dada uma matriz B formada por números inteiros com 10 linhas por 15 colunas, determinar o elemento
de maior valor algébrico. Mostre tal elemento e sua posição na matriz (linha e coluna).*/

int main()
{
    int m=10,n=15;
    int b[m][n], x=0, y=0, z=0;

    printf("Digite os valores da matriz B (%dx%d)\n",m, n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &b[i][j]);
            if(x<x)
            {
                scanf("%d", &x);
                x=x;
            }
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(x<b[i][j])
            {
                x = b[i][j];
                y=i;
                z=j;
            }
        }
    }
    y++;
    z++;
    printf("O maior valor da matriz e: %d, na cordenada(%dx%d).", x, y, z);
    printf("\n");
    printf("\nSe quiser conferir aqui esta a matriz");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }


    return 0;
}