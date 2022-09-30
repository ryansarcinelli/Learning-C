





#include <stdio.h>
#include <stdlib.h>

int main()
{
    float cpf, horas, ex_horas, salario_total, salario_exedente;

    printf("Digite seu Cpf:");
    scanf("%f", &cpf);
    printf("Digite as horas trabalhadas:");
    scanf("%f", &horas);

    printf("Cpf: %f", cpf);

    if(horas<=50)
    {
        salario_total = (horas*10);
        printf("\nSeu salario:%f", salario_total);
    }
    else
        if(horas >= 50)
    {
        ex_horas = (horas-50);
        salario_exedente = ((ex_horas)*20);
        salario_total = (((horas-ex_horas)*10) + (salario_exedente));
        printf("\nSeu salario total:%f", salario_total);
        printf("\nSeu salario exedente:%f", salario_exedente);

    }

    return 0;
}