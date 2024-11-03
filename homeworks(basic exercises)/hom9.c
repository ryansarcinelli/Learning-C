#include <stdio.h>
/*Dada uma matriz A de dimensões 5x4 formada de elementos numéricos reais, calcule e mostre sua matriz transposta T.*/

int main()
{
    int p=0, q=0, m=0, n=0;
    int a[10][10], transpo[10][10];

    printf("Digite as dimensoes da primeira matriz\n");
    scanf("%d%d", & m, & n);

    printf("Digite os valores da matriz A (%dx%d):\n", m, n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            transpo[i][j] = 0;
            transpo[i][j] = a[j][i];
        }
    }
    
    printf("A matriz rinicial e: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("A matriz transposta e: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ", transpo[i][j]);
        }
        printf("\n");
    }
    return 0;
}