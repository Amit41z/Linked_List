#include <stdio.h>
#include <stdlib.h>
void create();
void display();
void insert_begin();
void insert_end();
void insert_after_pos();
void insert_at_pos();
void delete_begin();
void delete_end();
void delete_pos();

int main()
{
    int choice;
    while (1)
    {
        printf("\n*****\n");
        printf("0. Create\n");
        printf("1. Display\n");
        printf("2. Insert Node at beginning\n");
        printf("3. Insert Node at end of LinkedList\n");
        printf("4. Insert Node after a specific position\n");
        printf("5. Insert Node at a specific position\n");
        printf("6. Delete Node at beginning\n");
        printf("7. Delete Node at end\n");
        printf("8. Delete Node at position\n");
        printf("9. ** To exit **");

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
            insert_end();
            break;
        case 4:
            insert_after_pos();
            break;
        case 5:
            insert_at_pos();
            break;
        case 6:
            delete_begin();
            break;
        case 7:
            delete_end();
            break;
        case 8:
            delete_pos();
            break;
        case 9:
            exit(0);
        default:
            printf("\n Wrong Choice");
            break;
        }
    }
}

struct node
{
    int data;
    struct node *next, *prev;
};
struct node *head = NULL, *newnode, *tail;
int pos, i = 1;

void create()
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

void insert_begin()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->prev = 0;

    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insert_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->prev = 0;

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insert_after_pos()
{
    int count = 0;
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    int c = count;
    printf("Enter the position:");
    scanf("%d", &pos);
    if (pos > c)
    {
        printf("Invalid position!");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        newnode->prev = 0;
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

void insert_at_pos()
{
    int count = 0;
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    int c = count;
    printf("Enter the position:");
    scanf("%d", &pos);
    if (pos > c)
    {
        printf("Invalid position!");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        newnode->prev = 0;
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

void delete_begin()
{
    struct node *temp;
    if (head == 0)
    {
        printf("List is empty!");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = 0;
        temp->next = 0;
        free(temp);
        printf("Node Successfully deleted!");
    }
}

void delete_end()
{
    struct node *temp;
    if (head == 0)
    {
        printf("List is empty!");
    }
    else
    {
        temp = tail;
        tail = tail->prev;
        tail->next = 0;
        temp->prev = 0;
        free(temp);
        printf("Node Successfully deleted!");
    }
}

void delete_pos()
{
    int count = 0;
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    int c = count;
    printf("Enter the position:");
    scanf("%d", &pos);
    if (pos > c)
    {
        printf("Invalid position!");
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}