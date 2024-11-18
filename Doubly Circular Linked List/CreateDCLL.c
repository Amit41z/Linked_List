#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    struct node
    {
        int data;
        struct node *next, *prev;
    };
    struct node *head = NULL, *tail, *newnode;
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
            head->prev = head;
            head->next = head;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
        printf("Do you want to continue(0,1)?");
        scanf("%d", &choice);
    }
    struct node *temp;
    temp = head;
    if (head == 0)
    {
        printf("List is empty!");
    }
    else
    {
        while (temp != tail) // while(temp->next!=tail->next)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("%d\t", temp->data);
    }
    getch();
}