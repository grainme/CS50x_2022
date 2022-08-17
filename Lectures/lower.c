// Lower uppercase characters in a string
------------------------------------------------------------------------------
/* Linux Command = valgrind ./lower
==32432== Memcheck, a memory error detector
==32432== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==32432== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==32432== Command: ./string
==32432== 
Marouane
marouane
==32432== 
==32432== HEAP SUMMARY:
==32432==     in use at exit: 0 bytes in 0 blocks
==32432==   total heap usage: 3 allocs, 3 frees, 2,068 bytes allocated
==32432== 
==32432== All heap blocks were freed -- no leaks are possible
==32432== 
==32432== For lists of detected and suppressed errors, rerun with: -s
==32432== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lower_str(char *str);

int main(void)
{
    char *name = malloc(20 * sizeof(char));
    scanf("%s",name);
    lower_str(name);
    printf("%s\n",name);
    free(name);
}


void lower_str(char *str)
{
    for (int i = 0 ; i < strlen(str) ;i++)
    {
        if ('A'<= *(str+i) && *(str+i) <= 'Z') // Note that we cannot use in C "a <= z <= b"
        {
            *(str+i) += 'a' - 'A';
        }
    }
}
