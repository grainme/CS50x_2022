#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{

    string paragraph = get_string("Text: ");
    int l = count_letters(paragraph);
    int w = count_words(paragraph);
    int s = count_sentences(paragraph);
    float L = (100 * l) / (float)w ;
    float S = (100 * s) / (float) w ;
    int result = round(((0.0588 * L) - (0.296 * S)) - 15.8);

    
    if (result > 16)
    {
        printf("Grade 16+\n");
    }
    else if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", result);
    }

}


int count_letters(string text)
{
    int letters_amount = 0;

    for (int i = 0, n = strlen(text) ; i < n ; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters_amount += 1;
        }
    }
    return letters_amount;
}


int count_words(string text)
{
    int words_amount = 1;
    for (int i = 0, n = strlen(text) ; i < n ; i++)
    {
        if (text[i] == ' ')
        {
            words_amount += 1;
        }
    }
    return words_amount;
}


int count_sentences(string text)
{
    int sen_amount = 0;
    // We use strlen function to count the text length
    for (int i = 0, n = strlen(text) ; i < n ; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sen_amount += 1;
        }
    }
    return sen_amount ;
}
