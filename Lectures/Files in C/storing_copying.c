#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    char *buffer = malloc(100 * sizeof(char));
    char *data = malloc(100 * sizeof(char));
    FILE *input;
    FILE *output;
    int character;

    input = fopen("line.txt","w");

    printf("STORE DATA INTO THE FILE: ");
    scanf("%[^(\n)]%*c",data);

    fprintf(input,"%s",data);

    fclose(input);

    input = fopen("line.txt","r");
    output = fopen("linee.txt","w");

    while ((character = getc(input)) != EOF)
    {
        putc(character,output);

    }
    fclose(output);

    output = fopen("linee.txt","r");
    
    if (fgets(buffer,30,output) != NULL)
    {
        while(*buffer != '\0')
        {
            putchar(*buffer++);
        }
    }
    printf("\n");

    fclose(input);
    fclose(output);
    free(data);

}
