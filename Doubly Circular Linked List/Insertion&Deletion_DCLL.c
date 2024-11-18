#include <stdio.h>
#include <stdlib.h>
void create();
void display();
void insert_begin();
void insert_end();
void insert_at_pos();
void delete_begin();
void delete_end();
void delete_pos();

struct node *head = NULL, *tail;
struct node *newnode, *temp;
int pos, i = 1;
struct node
{
    int data;
    struct node *next, *prev;
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
        printf("3. Insert Node at a specific position\n");
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
            insert_at_pos();
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
}

void display()
{
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
}

void insert_begin()
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
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode;
        head = newnode;
    }
}

void insert_end()
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
}

void insert_at_pos()
{
    int count = 0;
    temp = tail->next;
    while (temp->next != tail->next)
    {
        temp = temp->next;
        count++;
    }
    int c = count + 1;
    // printf("%d", c);
    printf("Enter position:");
    scanf("%d", &pos);

    if (pos < 0 || pos > c)
    {
        printf("Invalid position!");
    }
    else if (pos == 1)
    {
        insert_begin();
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        newnode->prev = 0;

        temp = tail->next;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}

void delete_begin()
{
    temp = head;
    if (head == 0)
    {
        printf("List is empty!");
    }
    else if (head->next == head)
    {
        head = tail = 0;
        free(temp);
    }
    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
        free(temp);
    }
}

void delete_end()
{
    temp = tail;
    if (head == 0)
    {
        printf("List is empty!");
    }
    else if (head->next == head)
    {
        head = tail = 0;
        free(temp);
    }
    else
    {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
}

void delete_pos()
{
    int count = 0;
    temp = head;
    while (temp != tail)
    {
        temp = temp->next;
        count++;
    }
    int c = count + 1;
    // printf("%d", c);
    printf("Enter position:");
    scanf("%d", &pos);

    if (pos < 0 || pos > c)
    {
        printf("Invalid position!");
    }
    else if (pos == 1)
    {
        delete_begin();
    }
    else
    {
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp->next == head)
        {
            tail = temp->prev;
            free(temp);
        }
        else
        {
            free(temp);
        }
    }
}