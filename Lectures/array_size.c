/* This how to determine the size of an array */

// sizeof(array) return a long int that presents how many bytes reserved for the array int the memory 

// In this case sizeof(arr) == 40 bytes and sizeof(arr[0])==sizeof(int)==4 bytes --- > which gives by division 10 

// A pointer variables holds an address, yes. So no matter what is stored at the bytes beginning at that address, the actual address is 8 bytes.

/* char *name = "here's a really long string!";  
   - > sizeof(name) will be 8
   char name[] = "here's a really long string!";
   - > sizeof(name) will be 29
   -------> In both cases, strlen(name) will be 28 */


#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 3, 8, 9, 8, 47, 66, 789, 2};
    printf("%li\n", sizeof(arr) / sizeof(arr[0]) );
}
