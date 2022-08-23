// copying data from a file to another using fopen, fclose, getc and putc.


#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    FILE *in;
    FILE *out;
    char *input = malloc(20 * sizeof(char));
    char *output = malloc(20 * sizeof(char));
    int c;

    // Prompting the user for the name of the source file!
    printf("Source File: ");
    scanf("%s",input);

    // Check if the file exist!
    if ((in = fopen(input,"r")) == NULL)
    {
        printf("No data available!\n");
        return 1;
    }
    
    // Prompting the user for the name of the receiver file!
    printf("Where to copy the file: ");
    scanf("%s",output);

    if ((out = fopen(output,"w")) == NULL)
    {
        printf("FILE DOES NOT EXIST!\n");
        return 1;
    }

    // Copying the content from the input to output file untill EOF is encountered!
    while ((c = getc(in)) != EOF)
    {
        putc(c,out);
    }

    // Closing the files
    fclose(in);
    fclose(out);

    // Free the memory reserved for the strings!
    free(input);
    free(output);

    printf("File succesfuly copied!\n");

    return 0;
}
