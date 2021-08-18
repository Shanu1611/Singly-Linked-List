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

    int val, elem;
    ;
    printf("\nEnter the data to be inserted : ");
    scanf("%d", &val);
    printf("\nEnter the element before which you want to insert : ");
    scanf("%d", &elem);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;

    ptr = start;
    struct node *preptr;
    preptr = ptr;
    while (ptr->data != elem)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    newnode->next = ptr;
    preptr->next = newnode;

    ptr = start;
    printf("\nAfter inserting before a node, elements of linked list are : \n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}