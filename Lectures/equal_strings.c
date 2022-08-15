#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



bool equal(char *name1, char *name2);


int main(void)
{
    char *s = malloc(10*sizeof(char));
    char *m = malloc(10*sizeof(char));
    scanf("%s",s);
    scanf("%s",m);
    printf("%s\n",(equal(s,m))?"true":"false");
}

bool equal(char *name1, char *name2)
{
    int i = 0;
    while ((name1[i] == name2[i] || name1[i] == name2[i] - 32 || name1[i] == name2[i] + 32) && name1[i]!='\0' && name2[i]!='\0')
    {
        i++;
    }
    if (name1[i] == '\0' && name2[i] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
