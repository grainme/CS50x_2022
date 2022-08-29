// Basic Implementation of Linked List concept
#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int number;
    struct node *next;
}node;



int main(void)
{
    node *list = NULL;

    // Add number
    node *n = malloc(sizeof(node));

    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;

    list = n;

    // Add as second number

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;

    list->next = n;


    // Add a third number

    n = malloc(sizeof(node));
    if(n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    
    }
    n->number = 3;
    n->next = NULL;

    list->next->next = n;


    // Displaying the numbers
    for(node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        fprintf(stdout,"%i\n",tmp->number);
    }

    // Freeing the heap
    while(list != NULL)
    {
        node *tmp;
        tmp = list->next;
        free(list);
        list = tmp;
    }


}
