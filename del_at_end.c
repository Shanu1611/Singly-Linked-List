// to delete the node at the end-------------

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

    ptr = start;
    struct node *preptr;
    preptr=ptr;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    

    ptr = start;
    printf("\nAfter deleting at the end, elements of linked list are : \n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}