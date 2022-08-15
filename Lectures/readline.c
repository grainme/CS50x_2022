#include <stdio.h>

void readline(char buffer[]);

int main(void)
{
    char line[81];
    for (int i = 0 ; i < 3 ; i++)
    {
        
        readline(line);
        printf("%s\n",line);
    }
    return 0;
}


void readline(char buffer[])
{
    char character;
    int i = 0;
    do
    {
        character = getchar();
        buffer[i] = character;
        i++;
    }
    while(character != '\n');

    buffer[i-1] = '\0';
}

# This is a function similar to gets function, it reads full line from the terminal
