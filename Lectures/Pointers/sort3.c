/* Write a function called sort3() to sort three integers into ascending
order. (This function is not to be implemented with arrays.) */

#include <stdio.h>

void sort3(int *arr,int size);
void swap(int *a , int *b);

int main(void)
{
    int arr[] = {1,5,2,6,9,3,0};
    sort3(arr,7);
    for (int k = 0 ; k < 7 ; k++)
    {
        printf("%i ",arr[k]);
    }
    printf("\n");
}

// check if ptr1>ptr2 and *ptr1<*ptr2 , if so swap! [first Idea!]

void sort3(int *arr, int size)
{
    const int *arr_end = arr + size;
    int *ptr;
    for(; arr < arr_end ;arr++)
    {
        for(ptr = arr + 1 ; ptr < arr_end ;ptr++)
        {
            if (*ptr < *arr)
            {
                swap(ptr, arr);
            }
        }
    }
}

void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// {1,3,2} --> {1,2,3}
