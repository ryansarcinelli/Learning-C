#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    /*
    Develop one that:
    A. Read 4 numbers;
    B. Calculate the square of each;
    C. If the resulting value of the third square is >= 1000, show it and finish;
    D. Otherwise, most of the values read and their respective squares.
    */
    
    float a, b, c, d, a2, b2, c2, d2;

    printf("Type the first number.\n");
    scanf("%f",&a);
    a2 = (a*a);

    printf("Type the second number.\n");
    scanf("%f",&b);
    b2 = (b*b);

    printf("Type the third number.\n");
    scanf("%f",&c);
    c2 = (c*c);

    printf("Type the fourth number.\n");
    scanf("%f",&d);
    d2 = (d*d);


    if(c2>=1000)

        printf("\n%.2f squared is %.2f", c, c2);
    else
    {
        printf("\n%.2f squared is %.2f", a, a2);
        printf("\n%.2f squared is %.2f", b, b2);
        printf("\n%.2f squared is %.2f", c, c2);
        printf("\n%.2f squared is %.2f", d, d2);
    }
    return 0;
}
