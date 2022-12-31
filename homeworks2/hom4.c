#include <stdio.h>
#include <stdlib.h>
/*Elabore um programa que leia um conjunto A com 50 números reais e construa um conjunto B, onde os
elementos de ordem (posição) par são os elementos correspondentes de A divididos por 2, e os de
ordem (posição) ímpar correspondem aos elementos de B multiplicados por 3. Ao final, mostre os dois
conjuntos de números.*/

int main ()
{
    int x=50, z=2*x, j=1, k=1;
    double a[x], b[x],c[z];

    for(int i=1;i<=x;i++)
    {
        printf("Digite o %d numero do vetor a:\n", i);
        scanf("%lf", &a[i]);
    }
     
    for(int i=1;i<=x;i++)
    {
        printf("Digite o %d numero do vetor b:\n", i);
        scanf("%lf", &b[i]);
    }

    for(int i=1;i<=z;i++)
    {
        if(i%2==0){
        c[i]=(a[j])/2;
        j++;
        }
            else{
            c[i]=(b[k])*3;
            k++;
            }
        printf("%.2lf ",c[i]);
        
    }

    return 0;
}