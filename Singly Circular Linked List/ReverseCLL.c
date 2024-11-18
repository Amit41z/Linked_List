#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *tail = 0, *newnode;

void create()
{
    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if (tail == 0)
        {
            tail = newnode;
            tail->next = newnode;
        }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
        printf("Do you want to continue(0,1)?\n");
        scanf("%d", &choice);
    }
}
void display()
{
    struct node *temp;
    printf("\nThe elements in the linked list are:\n");
    if (tail == 0)
    {
        printf("List is empty!");
    }
    else
    {
        temp = tail->next;
        while (temp->next != tail->next)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("%d\t", temp->data);
    }
}

void reverse()
{
    struct node *prevnode, *currnode, *nextnode;
    currnode = tail->next;
    nextnode = currnode->next;
    if (tail == 0)
    {
        printf("List is empty!");
    }
    else
    {
        while (currnode != tail)
        {
            prevnode = currnode;
            currnode = nextnode;
            nextnode = currnode->next;
            currnode->next = prevnode;
        }
        nextnode->next = tail;
        tail = nextnode;
    }
}

void display_reverse()
{
    struct node *temp;
    printf("\nThe elements in the linked list are:\n");
    if (tail == 0)
    {
        printf("List is empty!");
    }
    else
    {
        temp = tail->next;
        while (temp->next != tail->next)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("%d\t", temp->data);
    }
}

int main()
{
    create();
    display();
    reverse();
    display_reverse();
}
