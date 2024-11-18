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
struct node *tail = NULL;
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
}

void display()
{
    struct node *temp;
    printf("The elements in the linked list are:\n");
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

void insert_begin()
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
    }
}

void insert_end()
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

        temp = tail->next;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void delete_begin()
{
    temp = tail->next;
    if (tail == 0)
    {
        printf("List is empty!");
    }
    else if (temp->next == temp)
    {
        tail = 0;
        free(temp);
    }
    else
    {
        tail->next = temp->next;
        free(temp);
    }
}

void delete_end()
{
    struct node *currnode, *prevnode;
    currnode = tail->next;
    if (tail == 0)
    {
        printf("List is empty!");
    }
    else if (currnode->next == currnode)
    {
        tail = 0;
        free(currnode);
    }
    else
    {
        while (currnode->next != tail->next)
        {
            prevnode = currnode;
            currnode = currnode->next;
        }
        prevnode->next = tail->next;
        tail = prevnode;
        free(currnode);
    }
}

void delete_pos()
{
    struct node *currnode, *nextnode;
    int count = 0;
    currnode = tail->next;
    while (currnode->next != tail->next)
    {
        currnode = currnode->next;
        count++;
    }
    int c = count + 1;
    printf("%d", c);
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
        while (i < pos - 1)
        {
            currnode = currnode->next;
            i++;
        }
        nextnode = currnode->next;
        currnode->next = nextnode->next;
        free(nextnode);
    }
}