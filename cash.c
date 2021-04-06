#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // initialise a dollars variable with a default value of 0
    float dollars = 0;

    // prompt user for change required in dollars until value is positive
    do
    {
        dollars = get_float("Change required ($): \n");
    }
    while (dollars <= 0);
    
    // convert change required to cents as an integer (and round to negate effect of floating point imprecision)
    int cents = round(dollars * 100);
    
    // initialise a coins variable with a default value of 0

    int coins = 0;
    
    // work out number of coins required:
    // if change left is more than the largest coin available, reduce change left by that amount and increment coins by one
    // else do the same for next largest coin and so on
    // repeat until change left is 0
    do
    {
        if (cents >= 25)
        {
            cents -= 25;
            coins++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            coins++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            coins++;
        }
        else
        {
            cents -= 1;
            coins++;
        }
    }
    while (cents > 0);
    
    // print coins required
    printf("%i\n", coins);
}