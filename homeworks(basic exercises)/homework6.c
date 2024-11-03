#include <stdio.h>
#include <stdlib.h>

int main()
{

/*
Having as input data the height and gender of a person, build an algorithm that calculates his
ideal weight, using the following formulas:
The. For men: (72.7*HEIGHT) - 58
B. For women: (62.1*HEIGHT) - 44.7
*/

int hei;
char gen;
float wei;


printf("Type your gender (m for men) (w for women):\n");
scanf("%c", &gen);
printf("Type your height:\n");
scanf("%d", &hei);
if(gen == 'm')
{
    wei = (72.7*hei) - 58;
    printf("Your ideal weight is: %.2f", wei);
}
else
{
    wei = (62.1*hei) - 44.7;
    printf("Your ideal weight is: %.2f", wei);
}
    return 0;
}
