#include <stdio.h>
#include <cs50.h>

int main(int argc,string argv[])
{
    int num = 0;

    if (argc == 2)
    {
        for (int i = 0 ; argv[1][i]!='\0' ; i++ )
        {
            num = num * 10 + (argv[1][i] - 48);
        }
        printf("%i\n",num);
        return 0;
    }
    else
    {
        printf("Revise command line-args\n");
        return 1;
    }
}

// Method 2:

#include <stdio.h>
#include <cs50.h>




int main(void)
{
    int num = 0;
    char number[10] = "123";
    for (int i = 0 ; number[i]!='\0' ; i++ )
    {
        num = num * 10 + (number[i] - 48);
    }

    printf("%i\n",num);
    return 0;
}
