// delete a node after the given node-------------
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct node
    {
        int data;
        struct node *next;
    };

    struct node *start = NULL;
    struct node *ptr;
    struct node *newnode;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data : ");
    scanf("%d", &num);
    while (num != -1)
    {

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;

        if (start == NULL)
        {
            newnode->next = NULL;
            start = newnode;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newnode;
            newnode->next = NULL;
        }

        printf("\nEnter the data : ");
        scanf("%d", &num);
    }

    ptr = start;
    printf("\nElements of linked list are : \n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }

    int elem;
    printf("\nEnter the element after which node will be deleted : ");
    scanf("%d", &elem);

    ptr = start;
    struct node *preptr;
    preptr=ptr;
    while (preptr->data != elem)
    {
        preptr=ptr;
        ptr = ptr->next;
    }
    free(ptr);

    preptr->next=ptr->next;


    ptr = start;
    printf("\nAfter deleting after a given node, elements of linked list are : \n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}