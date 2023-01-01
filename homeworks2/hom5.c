#include <stdio.h>
#include <stdlib.h>
/*Elabore um programa que utilize dois vetores V1 e V2, formados de números reais com 20 posições
cada um, e efetue neles as operações indicadas no vetor OP, cujos elementos são caracteres que
indicam as quatro operações aritméticas básicas (+, -, *, /). O resultado obtido das operações deve ser
colocado num vetor resultante VR e mostrado ao final do programa.*/

int main()
{
    const int x=3;
    float soma=0;
    int operacao;
    double a[x], b[x],op[x];

    for(int i=1;i<=x;i++)
    {
        printf("Digite o %d numero do vetor a:\n", i);
        scanf("%lf", &a[i]);
        printf("Digite o %d numero do vetor b:\n", i);
        scanf("%lf", &b[i]);
    }

    printf("Diga a sua operacao (+, -, *, /)(1, 2, 3, 4)\n");
    scanf("%d", &operacao);
    //scanf("%d");
    switch (operacao)
    {
        case 1:
        for(int i=1;i<=x;i++)
        {
            op[i]=(a[i])+(b[i]);
        }
        break;

        case 2:
        for(int i=1;i<=x;i++)
        {
            op[i]=(a[i])-(b[i]);
        }
        break;

        case 3:
        for(int i=1;i<=x;i++)
        {
            op[i]=(a[i])*(b[i]);
        }
        break;

        case 4:
        for(int i=1;i<=x;i++)
        {
            op[i]=(a[i])/(b[i]);
        }
        break;
    }
    
    printf("O vetor final e: ");
    
    for(int i=1;i<=x;i++)
    {
        if(i<x)
        printf("%.2lf, ", op[i]);
        else
        printf("%.2lf", op[i]);
        soma = soma + op[i];
    }
    
    printf("\nSoma e %.2f", soma);

    return 0;
}