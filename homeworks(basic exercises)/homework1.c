#include <stdio.h>
#include <stdlib.h>

int main()
{
 
/*
    Develop an algorithm that reads the CPF (ID) and the number of hours worked by a worker. Calculate salary
    knowing that he earns R$ 10.00 per hour. When the number of hours exceeds 50, calculate the
    overpayment by storing it in another variable, otherwise reset that variable. the time
    surplus work is worth R$ 20.00. At the end of processing show the total salary and salary
    worker surplus.
*/
    
    float cpf, hours, total_salary, surplus;

    printf("Type your Cpf:");
    scanf("%f", &cpf);
    printf("Type your worked hours:");
    scanf("%f", &hours);

    printf("\nCpf: %.0f", cpf);

    if(hours<=50)
    {
        total_salary = (hours*10);
        printf("\nYour salary:%.0f", total_salary);
    }
    else
    {
        total_salary = (500 + (hours-50)*20);
        surplus = total_salary - 500;
        printf("\nYour total salary is:%.0f", total_salary);
        printf("\nYour surplus salary is:%.0f", surplus);    
    }
    return 0;
}
