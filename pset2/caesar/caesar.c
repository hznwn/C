// A program that encrypts messages using Caesar’s cipher from plaintext to "ciphertext" using Ci = (Pi + K) % 26
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Check that the program was run with only a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //Iterate over the provided argument to make sure characters are only alphanumeric
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //Convert command-line argument from a string to an int
    int posinput = atoi(argv[1]);
    // Check if command-line argument is positive
    if (posinput < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //Prompt user to enter plaintext
        string plaintext = get_string("Plaintext: ");

        printf("ciphertext: ");
        //Iterate over each character of the plaintext:
        for (int i = 0, length = strlen(plaintext); i < length; i++)
        {
            //Check if char is upper/upper case and convert to ASCII while account for 0/1 placement difference
            if isupper(plaintext[i])
            {
                printf("%c", (((plaintext[i] + posinput) - 65) % 26) + 65);
            }
            else if islower(plaintext[i])
            {
                printf("%c", (((plaintext[i] + posinput) - 97) % 26) + 97);
            }
            //Skip conversion if neither lower/upper case and print
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
    }
}