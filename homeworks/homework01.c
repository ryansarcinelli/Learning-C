#include <stdio.h>
#include <stdlib.h>

int main()
{
/*
Write a program that determines how obese a person is, given the weight and
person's height. The degree of obesity is determined by the body mass index - BMI (Mass = Weight/Height2)through the following indices:
A. Below 19.9: You are underweight.
B. Between 20.0 and 24.9: Congratulations! you are at your normal weight!
C. Between 25.0 and 29.9: You are overweight (overweight).
D. Between 30.0 and 34.9: Moderate obesity (grade I).
E. Between 35.0 and 39.9: Severe obesity (grade II).
f. 40.0 and above: Morbid obesity (grade III).
*/

float we, he, c;

printf("\nType your weight(in kilos):");
scanf("%f", &we);

printf("\nType your height(in meters):");
scanf("%f", &he);

c = (we/(he*he));

    if (c>=40.0)
        printf("\nYou have morbid obesity (grade III).");
        else if(c>=35.0 && c<=39.9)
            printf("\nYou have severe obesity (grade II).");
            else if(c>=30 && c<=34.9)
                printf("\nYou have moderate obesity (grade I).");
                else if(c>=25 && c<=29.9)
                    printf("\nYou are overweight (overweight).");
                    else if(c>=20 && c<=24.9)
                        printf("\nCongratulations! you are at your normal weight!");
                            else if(c<=10.9)
                            printf("\nYou are underweight.");
    return 0;
}
