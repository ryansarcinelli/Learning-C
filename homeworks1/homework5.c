#include <stdio.h>
#include <stdlib.h>

int main()
{

/*
Design an algorithm in C (using the concepts seen in this chapter) to read a
numeric variable N and show it only if it is greater than 100, otherwise show it with the
zero value.
*/

float n;

printf("Type your number.\n");
scanf("%f", &n);

if(n>100)
    printf("%.3f.", n);
else
    printf("0.");
    return 0;
}
