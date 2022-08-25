// Program to copy one file to another — version 2
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *input;
    FILE *output;

    int character;

    if (argc != 3)
    {
        fprintf(stdout,"Not enough arguments!\n");
        exit(EXIT_FAILURE);
    }
    input = fopen(argv[1],"r");
    output = fopen(argv[2],"w");

    if ( input == NULL )
    {
        fprintf (stderr, "Can't read %s.\n", argv[1]);
        return 2;
    }

    if ( output == NULL )
    {
        fprintf (stderr, "Can't write %s.\n", argv[2]);
        return 3;
    }


    while((character = fgetc(input)) != EOF)
    {
        fputc(character, output);
    }

    return 0;
}
