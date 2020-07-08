// Build "Mario" pyramid based on height
#include <cs50.h>
#include <stdio.h>

//declare
int get_pos_int(void);

int main(void)
{
    //Set height from positive integer checker
    int height = get_pos_int();

    for (int i = 0; i < height; i++)
    {
        //Left Print Spaces
        for (int j = height - i; j > 1; j--)
        {
            printf(" ");
        }
        //Left Print Hash
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        //Print Gap
        int l = 0;
        do
        {
            printf("  ");
        }
        while (l > i);
        //Right Print Hashes
        for (int m = 0; m <= i; m++)
        {
            printf("#");
        }
        //Print new line
        printf("\n");
    }
}

// Function for prompting for and validating positive integer
int get_pos_int(void)
{
    int x;
    do
    {
        // Prompt user for Height
        x = get_int("Insert a height between 1-8: ");
    }
    while (x < 1 || x > 8);
    return x;
}