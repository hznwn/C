#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Iterate through candidates count.
    for (int i = 0; i < candidate_count; i++)
    {
        // Look for name match between strings using strcmp.
        if (strcmp(name, candidates[i].name) == 0)
        {
            // If match then add 1 to counter
            candidates[i].votes++;
            return true;
        }
    }
    // TODO end
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Declare total_votes int and set to "0".
    int total_votes = candidates[0].votes;
    // Iterate over candidates list and check votes amounts.
    for (int i = 0; i < candidate_count; i++)
    {
        // If that number is greater than the total_votes
        if (candidates[i].votes > total_votes)
        {
            // Update the total_votes to that value.
            total_votes = candidates[i].votes;
        }
    }
    // Iterate over the list of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == total_votes)
        {
            // Print candidate who has that total_votes number of votes.
            printf("%s\n", candidates[i].name);
        }
    }

    // TODO end
    return;
}

