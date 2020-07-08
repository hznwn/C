// A program that informs how many coins to return based on "change" input from user
#include <cs50.h>
#include <math.h>
#include <stdio.h>


int main(void)
{
    //declare
    float dollars;
    int qc = 0, dc = 0, nc = 0, pc = 0, cents;
    //Receive change input
    do
    {
        dollars = get_float("Change owed: ");
    }
    //Ensure value is above 0 and round value
    while (dollars <= 0);
    cents = round(dollars * 100);
    //Iterate from large coins to small coins and count coins
    if (cents >= 25)
    {
        qc = cents / 25;
        cents = cents % 25;
        printf("Quarters: %i\n", qc);
    }
    if (cents >= 10)
    {
        dc = cents / 10;
        cents = cents % 10;
        printf("Dimes: %i\n", dc);
    }
    if (cents >= 5)
    {
        nc = cents / 5;
        cents = cents % 5;
        printf("Nickels: %i\n", nc);
    }
    if (cents >= 1)
    {
        pc = cents / 1;
        cents = cents % 1;
        printf("Pennies: %i\n", pc);
    }
    printf("%i\n", (qc + dc + nc + pc));
}
