#include <stdio.h>
#include <stdlib.h>

/*Faça um algoritmo que mostre na tela todos (apenas) os números primos entre 5 e 5000.*/
int main()
{
    int primo;

    for(int n=5; n<=5000; n++)
    {
        primo=1;
        for(int d=2; d<n;d++)
            if(n%d==0)
            {
                primo=0;
            }
        if(primo==1)
        printf("\n%d", n);
    }

    return 0;
}