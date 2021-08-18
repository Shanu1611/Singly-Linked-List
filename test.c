#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};

int main()
{
    int num;
    struct node *start = NULL, *newnode;
    struct node *ptr1;
    printf("\n----Enter -1 to end the linked lists-------");
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
            ptr1 = start;
            while (ptr1->next != NULL)
                ptr1 = ptr1->next;
            ptr1->next = newnode;
            newnode->next = NULL;
        }
        printf("\nEnter the data : ");
        scanf("%d", &num);
    }

    ptr1 = start;
    printf("\n Linked Lists are : ");
    while (ptr1 != NULL)
    {
        printf("%d\t", ptr1->data);
        ptr1 = ptr1->next;
    }

    // to delete the linked list;
    ptr1 = start;
    while (start != NULL)
        start = start->next;

    printf("\nLinked List after deleted : ");
    ptr1 = start;
    while (ptr1 != NULL)
    {
        printf("%d\t", ptr1->data);
        ptr1 = ptr1->next;
    }

    return 0;
}