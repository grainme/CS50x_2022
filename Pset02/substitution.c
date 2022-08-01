#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


bool is_valid(string word);

int main(int argc, string argv[])
{
    // check if the command line-args are composed of two words
    if (argc == 2)
    {
        // is_valid is a custom function
        // goal : check the validty of the key
        if (is_valid(argv[1]))
        {
            string plaintext = get_string("plaintext:  ");
            printf("ciphertext: ");
            for (int i = 0 ; plaintext[i] != '\0' ; i++)
            {
                if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
                {
                    // make sure to output the letter depending on the lowercase style in the original plaintext
                    // include ctype library to use "toupper" function
                    printf("%c", toupper(argv[1][plaintext[i] - 'A']));
                }
                else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
                {
                    printf("%c", toupper(argv[1][plaintext[i] - 32 - 'A']) + 32);
                }
                else
                {
                    printf("%c", plaintext[i]);
                }
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

// Check Condition of validation
bool is_valid(string word)
{
    bool result = true;

    // Check if the length is indeed 26
    if (strlen(word) != 26)
    {
        result = false;
    }

    // Check if all the characters in the string are alphabets
    for (int i = 0 ; i < strlen(word) ; i++)
    {
        if (isalpha(word[i]) == false)
        {
            result = false;
            break;
        }
    }
    // Brute force solution: Check if there are duplicates
    for (int i = 0; i < strlen(word) ; i++)
    {
        for (int k = i + 1; k < strlen(word) ; k++)
        {
            if (toupper(word[k]) == toupper(word[i]))
            {
                result = false;
                break;
            }
        }
    }
    return result;
}
