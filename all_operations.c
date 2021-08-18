// Write a program to create a linked list and perform insertions
// and deletions of all cases.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
struct node insert_at_beg(struct node *start)
{
    struct node *ptr;
    int val;
    printf("Enter the value you want to insert at the beginning : ");
    scanf("%d", &val);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;

    newnode->next = start;
    start = newnode;

    display(start);
}
struct node insert_at_end(struct node *start)
{
    struct node *ptr;
    ptr = start;
    int val;
    printf("Enter the value you want to insert at the end : ");
    scanf("%d", &val);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newnode;
    newnode->next = NULL;

    display(start);
}
struct node insert_after_a_node(struct node *start)
{

    int val, elem;
    printf("Enter the value you want to insert after a node  : ");
    scanf("%d", &val);
    printf("\nEnter the element after which you want to insert : ");
    scanf("%d", &elem);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;

    struct node *ptr;
    ptr = start;

    while (ptr->data != elem)
        ptr = ptr->next;

    newnode->next = ptr->next;
    ptr->next = newnode;

    display(start);
}
struct node insert_before_a_node(struct node *start)
{
    struct node *ptr, *preptr;
    preptr = ptr;
    ptr = start;
    int val, elem;
    printf("Enter the value you want to insert before a node : ");
    scanf("%d", &val);
    printf("\nEnter the element before which you want to insert : ");
    scanf("%d", &elem);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;

    while (ptr->data != elem)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    newnode->next = ptr;
    preptr->next = newnode;

    display(start);
}
struct node del_at_begin(struct node *start)
{
    struct node *ptr;
    ptr = start->next;
    free(start);
    start = ptr;

    display(start);
}
struct node del_at_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    preptr = ptr;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);

    display(start);
}
struct node del_after_a_node(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    preptr = ptr;
    int elem;
    printf("\nEnter the element after which you want to delete : ");
    scanf("%d", &elem);

    while (preptr->data != elem)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);

    display(start);
}
struct node del_list(struct node *start)
{
    struct node *ptr;
    ptr = start;

    while (start != NULL)
        start = start->next;
}

int main()
{

    //  -----------Creation of linked list---------------
    int num;
    struct node *start = NULL, *newnode;
    struct node *ptr;
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
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newnode;
            newnode->next = NULL;
        }
        printf("\nEnter the data : ");
        scanf("%d", &num);
    }
    int option;
    do
    {

        printf("\n\n---------Operations on the linked lists------------");
        printf("\n1. Display the linkied list");
        printf("\n2. Insert at beginning");
        printf("\n3. Insert at end");
        printf("\n4. Insert after a given node");
        printf("\n5. Insert before a given node");
        printf("\n6. Delete at beginning");
        printf("\n7. Delete at end");
        printf("\n8. Delete after the given node");
        printf("\n9. Delete the linked list!!");
        printf("\n10. EXIT!!!!!");

        printf("\n Choose any one operation from the above : ");
        scanf("%d", &option);
        printf("\n");

        switch (option)
        {
        case 1:
            printf("\nLinked lists are : ");
            display(start);
            break;
        case 2:
            insert_at_beg(start);
            break;

        case 3:
            insert_at_end(start);
            break;

        case 4:
            insert_after_a_node(start);
            break;

        case 5:
            insert_before_a_node(start);
            break;

        case 6:
            del_at_begin(start);
            break;

        case 7:
            del_at_end(start);
            break;

        case 8:
            del_after_a_node(start);
            break;
        case 9:
            del_list(start);
            break;
        }
    } while (option != 10);

    return 0;
}