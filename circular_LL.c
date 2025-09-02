#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

struct Node
{
    int data;
    struct Node * next;
};

static int count = 0;
struct Node* tail = NULL;

struct Node* createNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // ❌ Wrong check: (tail == tail->next) was invalid when list is empty
    // ✅ Fix: if list is empty (tail == NULL), then set tail = node
    if (tail == NULL)
    {
        tail = node;
    }

    node->data = data;
    node->next = node;  // circular link to itself
    return node;
}

void insert_at_beginning(int data)
{
    if (count >= MAXSIZE)   // ❌ should be >=, not >
    {
        printf("overflow!\n");
        return;
    }
    struct Node * node = createNode(data);
    if (node == NULL) return; // safeguard against malloc fail

    count++;
    if (tail == NULL)
    {
        tail = node;
        return;
    }
    node->next = tail->next;
    tail->next = node;
}

void insert_at_ending(int data)
{
    if (count >= MAXSIZE)   // ❌ should be >=, not >
    {
        printf("overflow\n");
        return;
    }
    struct Node* node = createNode(data);
    if (node == NULL) return; // safeguard

    if (tail == NULL)
    {
        tail = node;   // ❌ directly set tail = node, no need to call insert_at_beginning
    }
    else
    {
        node->next = tail->next;
        tail->next = node;
        tail = node;
    }
    count++;
}

void insert(int data, int pos)
{
    if (pos < 1 || pos > count + 1 || pos > MAXSIZE)
    {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1)
    {
        insert_at_beginning(data);
        return;
    }
    else if (pos == count + 1)
    {
        insert_at_ending(data);
        return;
    }

    struct Node* node = createNode(data);
    if (node == NULL) return;

    count++;
    struct Node* head = tail->next;
    int i = 1;
    struct Node* temp = head;
    while(i < pos-1)
    {
        temp = temp->next;
        i++;
    }
    node->next = temp->next;
    temp->next = node;
}

int delete_at_beginning()
{
    if (count == 0)
    {
        printf("Underflow\n");
        return -1;
    }
    struct Node* head = tail->next;
    int data = head->data;

    if (tail == head)   // only one node
    {
        free(tail);
        tail = NULL;    // ❌ missing earlier
    }
    else
    {
        tail->next = head->next;
        free(head);
    }
    count--;
    return data;
}

int delete_at_ending()
{
    if (count == 0)
    {
        printf("Underflow\n");
        return -1;
    }
    struct Node *head = tail->next;
    int data = tail->data;

    if (head == tail)   // only one node
    {
        free(tail);
        tail = NULL;    // ❌ missing earlier
    }
    else
    {
        while(head->next != tail)
        {
            head = head->next;
        }
        head->next = tail->next;
        free(tail);
        tail = head;
    }
    count--;
    return data;
}

int delete(int pos)
{
    if (pos < 1 || pos > count)
    {
        printf("INVALID POSITION\n");
        return -1;
    }
    if (pos == 1)
    {
        return delete_at_beginning();
    }
    else if (pos == count)
    {
        return delete_at_ending();
    }

    struct Node* head = tail->next;
    int i = 1;
    while(i < pos-1)
    {
        head = head->next;
        i++;
    }
    struct Node* node = head->next;
    int data = node->data;
    head->next = node->next;
    free(node);   // ❌ you forgot to free this node earlier
    count--;
    return data;
}

void display()
{
    if (count == 0)
    {
        printf("List underflow\n");
        return;
    }
    struct Node* head = tail->next;
    struct Node* temp = head;
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    while(temp != head);
    printf("\n");
}

int main()
{
   while(1)
   {
       int choice;
       scanf("%d",&choice);
       int value;
       int position;
       switch(choice)
       {
           case 1:
           {
            printf("Enter value : ");
            scanf("%d",&value);
            printf("Enter position : ");
            scanf("%d",&position);
            insert(value,position);
            break;   
           }
           case 2:
           {
            printf("Enter the position : ");
            scanf("%d",&position);
            int pop = delete(position);
            if (pop != -1)
                printf("Deleted element : %d\n",pop);
            break;
           }
           case 3:
           {
            printf("Displaying elements : ");
            display();
            break;
           }
           default:
           {
               printf("invalid entry!\n");
               break;
           }
       }
   }
   return 0;
}
