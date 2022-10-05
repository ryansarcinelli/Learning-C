#include <stdio.h>
#include <stdlib.h>

int main()
{

/*
Design two algorithms, one using composite selections and the other using multiple selections) that
given the age of a swimmer, classify him into one of the following categories:
A Infant A = 5 to 7 years
B. Infant B = 8 to 11 years
C. Juvenile A = 12 to 13 years
D. Juvenile B = 14 to 17 years old
E. Adults = Over 18 years old
*/

int age, age2;

printf("Type your age:\n");
scanf("%d", &age);

if (age >= 18)
    printf("You're an Adult.\n");
else if (age >= 14 && age <=17)
    printf("You're an Juvenile B.\n");
else if (age >= 12 && age <=13)
    printf("You're an Juvenile A.\n");
else if (age >= 8 && age <=11)
    printf("You're an Infant B.\n");
else if (age >= 5 && age <=7)
    printf("You're an Infant A.\n");
/*
printf("Type your age:\n");
scanf("%d", &age2);

switch (age2)
{
    case >= 18:
    printf("You're an Adult.\n");
        break;
    case >= 14 && <=17:
    printf("You're an Juvenile B.\n");
        break;
    case >= 12 && <=13:
    printf("You're an Juvenile A.\n");
        break;
    case >= 8 && <=11:
    printf("You're an Infant B.\n");
        break;
    case >= 5 && <=7:
    printf("You're an Infant A.\n");
        break;
        */
}

    return 0;
}
