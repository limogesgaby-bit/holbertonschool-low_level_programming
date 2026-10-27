#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
main -print whether a random number is positive, zero or negative 

return : always 0 (succes)
*/

int main(void)
{
    int n;

    srand(time(0));
    n = rand() - RAND_MAX / 2;
    if (n > 0)
        printf("%d is positive\n", n);
    else if (n == 0)
        printf("%d is negative\n", n);
    else 
        printf("%d is negative\n", n);
    return (0);
}