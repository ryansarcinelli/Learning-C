#include <stdio.h>
#include <stdlib.h>
/*Considere um vetor VET com 30 elementos. Verificar se existe um elemento igual a K no vetor. Se existir
mostrar a posição em que se encontra, senão imprimir “não encontrei K no vetor”.*/

int main()
{
    int const x=30;
    int a[x], k;
    
    for(int i=0; i<=x; i++)
    {
        a[i]=i;
    }
    
    printf("Digite o numero que quer encontar:\n");
    scanf("%d", k);

    for(int i=0; i<= x; i++)
    {
        if(k==a[i])
        printf("K existe na posição %d", i);
        else
        printf("não encontrei K no vetor");
    }
    return 0;
}