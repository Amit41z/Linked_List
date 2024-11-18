#include <stdio.h>
#include <stdlib.h>
void create();
void display();
void insert_begin();
void insert_end();
void insert_after_pos();
void delete_begin();
void delete_end();
void delete_pos();
struct node *head = NULL;
struct node *newnode, *temp;
int pos, i = 1;
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int choice;
    while (1)
    {
        printf("\n*****\n");
        printf("0. Create\n");
        printf("1. Display\n");
        printf("2. Insert Node at beginning\n");
        printf("3. Insert Node after a specific position\n");
        printf("4. Insert Node at end of LinkedList\n");
        printf("5. Delete Node at beginning\n");
        printf("6. Delete Node at end\n");
        printf("7. Delete Node at position\n");
        printf("8. ** To exit **");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            create();
            break;
        case 1:
            display();
            break;
        case 2:
            insert_begin();
            break;
        case 3:
            insert_after_pos();
            break;
        case 4:
            insert_end();
            break;
        case 5:
            delete_begin();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            delete_pos();
            break;
        case 8:
            exit(0);
        default:
            printf("\n Wrong Choice");
            break;
        }
    }
}

void create()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    if (head == 0)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("Linked List is Empty!");
    }
    else
    {
        printf("The elements in the linked list are:\n");
        temp = head;
        while (temp != 0)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

void insert_begin()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    if (head == 0)
    {
        head = temp = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void insert_after_pos()
{
    int count = 0;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    int c = count;
    printf("Enter position:");
    scanf("%d", &pos);
    if (pos > c)
    {
        printf("Invalid Position!");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void insert_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    if (head == 0)
    {
        head = temp = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void delete_begin()
{
    if (head == 0)
    {
        printf("List is empty!");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("Deleted Successfully!");
    }
}
void delete_end()
{
    struct node *prevnode;
    if (head == 0)
    {
        printf("List is empty!");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            prevnode = temp;
            temp = temp->next;
        }
        if (temp == head)
        {
            head = 0;
        }
        else
        {
            prevnode->next = 0;
        }
        free(temp);
        printf("Deleted Successfully!");
    }
}
void delete_pos()
{
    struct node *nextnode;
    temp = head;
    printf("Enter position:");
    scanf("%d", &pos);

    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
    printf("Deleted Successfully!");
}
