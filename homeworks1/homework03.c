#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Write an algorithm that determines the largest of N numbers read. The stop condition is the input of
a value of 0, that is, the algorithm must be calculating the largest until the input is equal to 0 (ZERO)*/

    float numbermax = 0, number;
    do
     {
    printf("Enter a number: \n");
    scanf("%f", &number);
    if(numbermax < number)
        numbermax = number;
        printf("Max number is:\n%0.2f \n", numbermax);
    }
    while(number != 0);
    return 0;
}
