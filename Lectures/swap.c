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
