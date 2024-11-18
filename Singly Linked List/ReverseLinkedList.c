#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void reverse();

struct node
{
    int data;
    struct node *next;
};
struct node *head = 0, *newnode, *temp;

int main()
{
    int choice;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue(0,1)?");
        scanf("%d", &choice);
    }
    printf("The elements in the linked list is:\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    reverse();
    getch();
}

void reverse()
{
    struct node *prevnode, *currnode, *nextnode;
    prevnode = 0;
    currnode = nextnode = head;
    while (nextnode != 0)
    {
        nextnode = nextnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    head = prevnode;
    printf("\nThe elements in the linked list in reverse order is:\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
