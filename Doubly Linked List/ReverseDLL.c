#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};
struct node *head = NULL, *tail, *newnode;

void create()
{
    int choice;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        newnode->prev = 0;
        if (head == 0)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("Do you want to continue(0,1)?");
        scanf("%d", &choice);
    }
}
void reverse()
{
    struct node *currnode, *nextnode;
    currnode = head;
    while (currnode != NULL)
    {
        nextnode = currnode->next;
        currnode->next = currnode->prev;
        currnode->prev = nextnode;
        currnode = nextnode;
    }
    currnode = head;
    head = tail;
    tail = currnode;
}
void display()
{
    struct node *temp;
    temp = head;
    printf("The elements in the DLL are:\n");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
void display_reverse()
{
    struct node *temp;
    temp = head;
    printf("\nThe elements in the DLL in reverse order are:\n");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
int main()
{
    create();
    display();
    reverse();
    display_reverse();
}