#include <stdio.h>
#include <stdlib.h>

int main()
{

/*
Make an algorithm called Calculator, where the user provides two values ​​and the operator (one of
+, -, * and /), and the program does the math.
*/

float a, b, c;
int d;

printf("Type the first number:\n");
scanf("%f", &a);

printf("Type the second number:\n");
scanf("%f", &b);

printf("Type the operation:\n");
printf("\nType 1 to +:\n");
printf("\nType 2 to -:\n");
printf("\nType 3 to *:\n");
printf("\nType 4 to /:\n");
scanf("%d", &d);

switch(d)
{
    case 1:
        c = a+b;
        printf("Your result is: %.2f", c);
        break;

     case 2:
        c = a-b;
        printf("Your result is: %.2f", c);
        break;

     case 3:
        c = a*b;
        printf("Your result is: %.2f", c);
        break;

     case 4:
        c = a/b;
        printf("Your result is: %.2f", c);
        break;
}
    return 0;
}
