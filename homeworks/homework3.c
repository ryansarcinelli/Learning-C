#include <stdio.h>
#include <stdlib.h>

/*
Write an algorithm that reads an integer and displays a message indicating whether this number is even
or odd, and whether it is positive or negative.
*/


int main()
{
int divisor, divid, rest;

printf("Type your nuber.\n");
scanf("%d", &divisor);

divid=2;
rest = (divisor % divid);

if(rest ==0)
    printf("Your nuber is even.\n");
else
    printf("Your number is odd.\n");

if(divisor>0)
    printf("Your number is positive.\n");
else
    printf("Your nuber is positive.\n");
 return 0; 
}
