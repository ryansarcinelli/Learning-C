#include <stdio.h>
#include <stdlib.h>
/* Elabore um programa que leia dois vetores inteiros de 20 elementos cada, depois some seus elementos,
gerando um terceiro vetor. Ao final, mostre o novo vetor gerado. */

int main()
{
    const int x=20;
    int a[x], b[x], c[x], d;

    for(int i=0; i<=x; i++)
    {
        a[i]=i;
        b[i]=i;
    }
    for(int i=0; i<=x; i++)
    {
        c[i]=a[i]+b[i];
        printf("%d, ", c[i]);
    }
    return 0;
}