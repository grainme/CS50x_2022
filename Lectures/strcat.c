// Goal : Concatenate two strings
----------------------------------------------------------------------
/*
linux command : valgrind ./strcat
==31282== Memcheck, a memory error detector
==31282== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==31282== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==31282== Command: ./strcat
==31282== 
Hello, Marouane
==31282== 
==31282== HEAP SUMMARY:
==31282==     in use at exit: 0 bytes in 0 blocks
==31282==   total heap usage: 2 allocs, 2 frees, 1,044 bytes allocated
==31282== 
==31282== All heap blocks were freed -- no leaks are possible
==31282== 
==31282== For lists of detected and suppressed errors, rerun with: -s
==31282== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0) */

  
 // 
  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *str_cat(char *s1, char *s2);

int main(void)
{
    char *s1 = "Hello, ";
    char *s2 = "Marouane";
    char *test = str_cat(s1, s2);
    printf("%s\n",test);
    free(test);
}



char *str_cat(char *s1, char *s2)
{
    int i=0,j=0;
    char *result = malloc(20 * sizeof(char));
    while (s1[i] != '\0')
    {
        result[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0')
    {
        result[i+j] = s2[j];
        j++;
    }
    result[i+j] = '\0';
    return result;
    
}
