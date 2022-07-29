#include <stdio.h>
#include <cs50.h>

int len(long long cc_number);
bool check_validty(long long card_number);
bool check_sum(long long card_number);
void print_result(long cc_number);


int main(void)
{
    long long card;
    do
    {
        card = get_long("Number: ");
    }
    while (card < 0);

    if (check_validty(card))
    {
        print_result(card);
    }
    else
    {
        printf("INVALID\n");
    }
}

//length of the credit card number

int len(long long cc_number)
{
    int length;
    for (length = 0 ; cc_number != 0 ; length++)
    {
        cc_number /= 10;
    }
    return length;
}
// check if sum algo is working properly
bool check_sum(long long card_number)
{
    int sum =0;
    int digit;
    for (int i = 0 ; card_number != 0 ; i++)
    {
        if (i % 2 == 0)
        {
            sum += card_number % 10;
        }
        else
        {
            digit = 2 * (card_number % 10);
            sum += (digit / 10) + (digit % 10);
        }
        card_number /= 10;
    }
    return sum % 10 == 0;
}

//Check if cc_number is valid

bool check_validty(long long card_number)
{
    return (len(card_number) == 13 || len(card_number) == 15 ||  len(card_number) == 16) && check_sum(card_number);
}

//Function that print the Brand's name
void print_result(long cc_number)
{
    if ((cc_number >= 34e13  && cc_number < 35e13) || (cc_number >= 37e13  && cc_number < 38e13))
    {
        printf("AMEX\n");
    }
    else if (cc_number >= 51e14 && cc_number < 56e14)
    {
        printf("MASTERCARD\n");
    }
    else if ((cc_number >= 4e15 && cc_number < 5e15) || (cc_number >= 4e12 && cc_number < 5e12))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
