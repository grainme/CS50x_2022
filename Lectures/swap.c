#include <stdio.h>

void swap(int *a , int *b);

int main(void)
{

    int x , y;
    int *p = &x;
    int *q = &y;
    scanf("%i",p);
    scanf("%i",q);
    printf("x = %i y = %i\n",*p,*q);
    swap(p,q);
    printf("x= %i y = %i\n",*p,*q);
    return 0;
}

void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// SWAP STRINGS

#include <stdio.h>
#include <stdlib.h>

void swap(char *a , char *b);

int main(void)
{

    char *nickname = malloc(12 * sizeof(char));
    char *name = malloc(12 * sizeof(char));
    printf("name = ");
    scanf("%s",name);
    printf("\n");
    printf("nickname = ");
    scanf("%s",nickname);
    printf("name = %s nickname = %s\n",name,nickname);
    swap(name,nickname);
    printf("name= %s nickname = %s\n",name,nickname);
    free(nickname);
    free(name);
    return 0;
}

void swap(char *a , char *b)
{
    for (int i = 0 ; i < (12 * sizeof(char)) ; i++)
    {
        char temp = *(a+i);
        *(a+i) = *(b+i);
        *(b+i) = temp;

    }
    
}
