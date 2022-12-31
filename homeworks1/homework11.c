#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*A queen requested the services of a monk and told him that she would pay any price. the monk,
needing food, he asked the queen about the payment, if it could be made with grains of wheat
arranged on a chessboard (has 64 frames), such that the first frame should
contain only one grain and subsequent frames twice the previous frame. The queen found the
cheap labor and asked for the service to be performed, not realizing that it would be impossible to
The payment. Make an algorithm to calculate the number of grains the monk expected to receive.*/

    const  int numquad = 64;
    float grains = 0.5;
    for (int i = 1; i <=numquad; i++)
    {
        grains = (grains*2);
        printf("Q%d - %.0f\n", i, grains);
    }
    return 0;
}
