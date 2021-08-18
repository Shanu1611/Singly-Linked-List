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
    
    printf("\nEnter the data to be inserted : ");
    scanf("%d", &val);
    printf("\nEnter the element after which you want to insert : ");
    scanf("%d", &elem);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;

    ptr = start;
    while (ptr->data != elem)
        ptr = ptr->next;

    newnode->next = ptr->next;
    ptr->next = newnode;

    ptr = start;
    printf("\nAfter inserting after a node, elements of linked list are : \n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}