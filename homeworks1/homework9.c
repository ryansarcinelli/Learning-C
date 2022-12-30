#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    Design an algorithm that generates and writes the odd numbers between 100 and 200.
    */

    int i;

    for (i=100; i<=200; i++)
    {

    if(i % 2 != 0)
    printf("\n%d", i);
    }

    return 0;
}
