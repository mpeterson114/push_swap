#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void print_list(t_stack **head) {

    while (*head != NULL) {
        printf("%d\n", (*head)->value);
        (*head) = (*head)->next;
    }
}

/* Without using double pointer:
void print_list(t_stack * head) 
{
    t_stack * current = head;

    while (current != NULL) {
    printf("%d\n", current->val);
    current = current->next;
    }
}          
*/

int main()
{
    t_stack *head = NULL;
    head = (t_stack *) malloc(sizeof(t_stack));
    head->value = 1;
    head->next = (t_stack *) malloc(sizeof(t_stack));
    head->next->value = 2;
    head->next->next = NULL;
    print_list(&head);     //calling by reference with double pointer, no & if using single pointer
    return 0;
}