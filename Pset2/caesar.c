// Declaring libraries
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Functions prototype
bool only_digits(string arg);
char rotate(char c, int k);
bool is_alpha(char s);


// Main function
int main(int argc, string argv[])
{
    // if User typed more than two words in the cmd line
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else
    {
        if (only_digits(argv[1]))
        {
            // Converting string to long
            long k = atol(argv[1]);
            // assuring that the number is positive
            if (k >= 0)
            {
                string plaintext = get_string("plaintext: ");
                printf("ciphertext: ");
                for (int i = 0 ; i < strlen(plaintext) ; i++)
                {
                    if (is_alpha(plaintext[i]))
                    {
                        if (isupper(plaintext[i]))
                        {
                            // To use rotate function we need lower char, so we need to convert it back to upper
                            printf("%c", toupper(rotate(tolower(plaintext[i]), k)));
                        }
                        else
                        {
                            printf("%c", rotate(plaintext[i], k));
                        }
                    }
                    else
                    {
                        printf("%c", plaintext[i]);
                    }

                }
                printf("\n");
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    return 0;
}




// If a character from the argv is not a digit, it shouldn't be accepted
bool only_digits(string arg)
{
    for (int i = 0 ; i < strlen(arg) ; i++)
    {
        if (arg[i] > '9' || arg[i] < '0')
        {
            return false;
        }
    }
    return true;
}

// Rotating the character by k "places"
char rotate(char c, int k)
{
    if (c <= 'z' && c >= 'a')
    {
        c = c  - 'a';
    }
    return (c + k) % 26 + 'a';
}

// Assuring the char is an alphabet
bool is_alpha(char s)
{
    bool res = false;
    if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
    {
        res = true;
    }
    return res;
}
