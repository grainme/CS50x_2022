#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{

    FILE *file;
    FILE *output;
    file = fopen("from","r");
    output = fopen("to","w");

    char *buffer = malloc(80 * sizeof(char));
    int num_read, num_write;

    num_read = fread(buffer,sizeof(char),80,file);
    num_write = fwrite(buffer,sizeof(char),num_read,output);

    fprintf(stdout,"%i\n",num_write);

    fclose(file);

}


/*

in the “stdio.h” header file included *EOF , NULL, stdin, stdout,
 stderr and FILE*

size_t fread (buffer, size, n, filePtr);

reads n items of data from the identified file into buffer.
Each item of data is size bytes in length. For example, the call

numread = fread (text, sizeof (char), 80, in_file);

 reads 80 characters from the file identified by in_file and stores 
them into the array pointed to by text. The function returns the number
 of data items successfully read.

*/
