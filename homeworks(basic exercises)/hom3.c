#include <stdio.h>
#include <stdlib.h>
/*Faça um programa para ler um conjunto de 10 inteiros e escreve-los na ordem inversa à ordem de
leitura.*/

int main()
{
    int c=0,x=10,a[x];

    for(int i=0; i<=x; i++)
    {
        printf("Digite o %d numero:\n", i);
        scanf("%d", &a[i]);
    }

    printf("O vetor e: ");

    for(int i=x; i>=0; i--)
    {
        printf("%d ",a[i]);
    }

    return 0;
}