#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Comparing both scores
    // Player with more Points wins the match
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    // if both players have same points amount, they tie!
    else
    {
        printf("Tie!\n");
    }
}

// Function that computes points

int compute_score(string word)
{
    // Declaring variable called "sum" which is the final score
    int i, sum = 0;

    for (i = 0 ; i < strlen(word) ; i++)
    {
        if (isupper(word[i]))
        {
            sum += POINTS[(word[i] - 'A')];
        }
        else if (islower(word[i]))
        {
            // we can use also word[i] - 32 instead of toupper(word[i])
            sum += POINTS[(toupper(word[i]) - 'A')];
        }
    }

    return sum;

}
