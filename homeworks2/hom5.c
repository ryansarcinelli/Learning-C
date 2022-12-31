#include <stdio.h>
#include <stdlib.h>
/*Elabore um programa que utilize dois vetores V1 e V2, formados de números reais com 20 posições
cada um, e efetue neles as operações indicadas no vetor OP, cujos elementos são caracteres que
indicam as quatro operações aritméticas básicas (+, -, *, /). O resultado obtido das operações deve ser
colocado num vetor resultante VR e mostrado ao final do programa.*/

int main()
{
    const int x=2;
    int a[x], b[x],op[x], soma=0;
    char operacao;

    for(int i=1;i<=x;i++)
    {
        printf("Digite o %d numero do vetor a:\n", i);
        scanf("%d", &a[i]);
        printf("Digite o %d numero do vetor b:\n", i);
        scanf("%d", &b[i]);
    }

    printf("Diga a sua operacao (+, -, *, /)\n");
    scanf("%s", &operacao);

    switch (operacao)
    {
        case '+':
        for(int i=1;i<=x;i++)
        {
            op[i]=(a[i])+(b[i]);
        }
        break;

        case '-':
        for(int i=1;i<=x;i++)
        {
            op[i]=(a[i])-(b[i]);
        }
        break;

        case '*':
        for(int i=1;i<=x;i++)
        {
            op[i]=(a[i])*(b[i]);
        }
        break;

        case '/':
        for(int i=1;i<=x;i++)
        {
            op[i]=(a[i])/(b[i]);
        }
        break;
    }
    
    for(int i=1;i<=x;i++)
    {
        printf("%d ", op[i]);
        soma = soma + op[i];
    }
    
    printf("\nSoma e e %d", soma);

    return 0;
}