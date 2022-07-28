
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height : ");
    }
    while (height > 8 || height <= 0);

    for (int i = 0 ; i < height ; i++)
    {
        for (int k = height - 1 ; k > i ; k--)
        {
            printf(" ");
        }
        for (int z = 0 ; z < i + 1 ; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}
