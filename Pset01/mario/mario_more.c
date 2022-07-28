#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        //prompt the user for an input
        height = get_int("Height: ");

    }
    // check validty of the input
    while (height <= 0 || height > 8);
    // rows
    for (int i = 0 ; i < height ; i++)
    {
        for (int k = height ; k > i + 1 ; k--)
        {
            //add spaces
            printf(" ");
        }
        for (int z = 0 ; z < i + 1 ; z++)
        {
            //add hashes
            printf("#");
        }
        // bridge between the pyramids
        printf("  ");
        for (int j = 0 ; j < i + 1 ; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
