/*
The Environment Department that controls the pollution index maintains 3 groups of industries that are
highly polluting the environment. The acceptable pollution index ranges from 0.05 to 0.25. If the
index rises to 0.3 the 1st group industries are ordered to suspend their activities, if the index
to grow to 0.4 the 1st and 2nd group industries are ordered to suspend their activities if the
index reaches 0.5 all groups must be notified to stop their activities. Make one
algorithm that reads the measured pollution index and issues the appropriate notification to the different groups of
companies.
*/

#include <stdio.h>
#include <stdlib.h>

float a;

printf("Type the pollution index.\n");
scanf("%f",&a);

if (0.5<=a)
  printf("All companies must close.\n");
else if (0.4<=a) 
  printf("Only companies from the 1st and 2nd group must close.\n");
else if (0.3<=a)
  printf("Only companies from the 1st group must close..\n");
else
  printf("The pollution index is acceptable.\n");
