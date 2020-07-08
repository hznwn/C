// A program that computes the Coleman-Liau index to approximate grade level needed for comprehension.
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

//Global Declarataions
int count_words = 0, count_letters = 0, count_sentences = 0, count_char = 0;


int main(void)
{
    // Prompt user for their text
    string t = get_string("Enter your text: ");

    // Count number of words, letters and sentences up until NUL
    for (int i = 0, strlh = strlen(t); i < strlh; i++)
    {
        //Count letters based and exclude non-letter characters
        if (isalpha(t[i]))
        {
            count_letters++;
        }

        //Count sentences when a period, exclamation point or question mark appear
        if (t[i] == '.' || t[i] == '!' || t[i] == '?')
        {
            count_sentences++;
        }

        //Count words based on two characteristics: First letter is not an empty space, then keep checking and look for characters until next empty space.
        if ((i == 0 && t[i] != ' ') || (i != strlh - 1 && t[i] == ' ' && t[i + 1] != ' '))
        {
            count_words++;
        }
        //Count all characters that are not the end of array
        if (t[i] != '\0')
        {
            count_char++;
        }
    }

    //Print out counts
    printf("Character Count: %i\nWord Count: %i\nLetter Count: %i\nSentence Count: %i\n", count_char, count_words, count_letters,count_sentences);

    // Calculate: Average letters and sentences per 100
    float l = count_letters / (float) count_words * 100;
    float s = count_sentences / (float) count_words * 100;

    // Input: calculations using Coleman-Liau index formula
    int coleman_formula = round(0.0588 * l - 0.296 * s - 15.8);

    // Return text based on scoring and level computed
    if (coleman_formula < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (coleman_formula >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", coleman_formula);
    }
}