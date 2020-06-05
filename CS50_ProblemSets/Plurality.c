//Solution of the problem "Plurality" from the Problem Set 3 of the CS50 Harvard OpenCourseWare
//For more information on the problem, go to: https://cs50.harvard.edu/x/2020/psets/3/plurality/


//This is a program that runs a plurality election
//Every voter gets to vote for one candidate.
//At the end of the election, whichever candidate has the
//greatest number of votes is declared the winner of the election


//Include useful libraries
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <math.h>


//Definition of some constants

#define MAX 9 //represents the number of candidates

typedef struct //each candidate will have a name and a number of votes
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX]; //array of candidates of the type 'candidate'

int candidate_count; //Number of candidates


//Function prototypes that are declared after main
bool vote(string name);
void print_winner(void);



//Begin of the main function
int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1; //number of inputs minus the first (filename)
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
        if (vote(name) == false)
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
    int res = 1;
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes = candidates[i].votes + 1;
            res = 0;
            break;

        }
    }

    if (res == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
//End of the main function


//Begin the declaraation of functions

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max = 0;
    int candidateNumber = 0;
    int tmp = 0;
    int tie[MAX];

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max)
        {
            max = candidates[i].votes;
            candidateNumber = i;
        }
        else if (candidates[i].votes == max)
        {
            tie[tmp] = i;
            tmp ++;
        }
    }

    if (tmp > 0)
    {
        printf("%s\n", candidates[candidateNumber].name);
        for (int i = 0; i < tmp; i++)
        {
            int number = tie[i];
            printf("%s\n", candidates[number].name);
        }
    }
    else
    {
        printf("%s\n", candidates[candidateNumber].name);
    }

    return;
}

//End of code
