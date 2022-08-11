/* This how to determine the size of an array */

// sizeof(array) return a long int that presents how many bytes reserved for the array int the memory 

// In this case sizeof(arr) == 40 bytes and sizeof(arr[0])==sizeof(int)==4 bytes --- > which gives by division 10 


#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 3, 8, 9, 8, 47, 66, 789, 2};
    printf("%li\n", sizeof(arr) / sizeof(arr[0]) );
}
