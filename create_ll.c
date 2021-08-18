// ------------Creation & traversal of linked list-----------------

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *start = NULL;

    struct node *ptr, *new_node;
    printf("\nEnter -1 to end !!!");
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
        {
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("\n Enter the data: ");
        scanf("%d", &num);
    }

    // to print and count the number of nodes in the linked list----------
    int count = 0;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
        count++;
    }
    printf("\nNo. of nodes in the linked list are : %d", count);

    // to search any number from the linked list------------
    int n;
    printf("\nEnter the number to be searched : ");
    scanf("%d", &n);

    ptr = start;
    int pos = 1;
    while (ptr != NULL)
    {
        if (n == ptr->data)
            printf("\nPosition of the %d is %d", n, pos);
        ptr = ptr->next;
        pos++;
    }

    return 0;
}