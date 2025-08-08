#include<stdio.h>
#include<stdlib.h>

int size = 0;

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int val)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return NULL;
    }
    
    temp->next = NULL;
    temp->data = val;
    temp->prev = NULL;
    return temp;
}

void insertAtBegin(struct Node **head, int data)
{
    struct Node *temp = createNode(data);
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    temp->next = *head;
    (*head)->prev = temp;
    *head = temp;
    size++;
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *temp = createNode(data);
    if (*head == NULL)
    {
        *head = temp;
        size++;
        return;
    }
    struct Node *tmp = *head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = temp;
    temp->prev = tmp;
    temp->next = NULL;
    size++;
}

void deleteAtBegin(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Underflow!\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    temp->next = NULL;
    size--;
    free(temp);
}

void deleteAtEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Underflow!\n");
        return;
    }
    struct Node *temp = *head;
    
    if (temp->next == NULL)
    {
        *head = NULL;
        free(temp);
        size--;
        return;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->prev->next = NULL;
    temp->prev = NULL;
    temp->next = NULL;
    size--;
    free(temp);
}

void insertAtPosition(struct Node **head, int pos, int val)
{
    if (pos < 1 || pos > (size+1))
    {
        printf("Invalid position!....Dropping data : %d",val);
        return;
    }
    struct Node *temp = createNode(val);
    struct Node *tmp = *head;
    
    if (pos == 1)
    {
        insertAtBegin(head,val);
        return;
    }
    else if (pos == size+1)
    {
        insertAtEnd(head,val);
        return;
    }
    
    for(int i = 1 ; i < (pos-1) ; i++)
    {
        tmp = tmp->next;
    }
    
    temp->prev = tmp;
    temp->next = tmp->next;
    tmp->next->prev = temp;
    tmp->next = temp;
    
    size++;
}

void deleteAtPosition(struct Node **head, int pos)
{
    if (pos < 1 || pos > size)
    {
        printf("Invalid position\n");
        return;
    }
    
    if (pos == 1)
    {
        deleteAtBegin(head);
        return;
    }
    else if (pos == size)
    {
        deleteAtEnd(head);
        return;
    }
    struct Node *temp = *head;
    
    for(int i = 1 ; i < pos; i++)
    {
        temp = temp->next;
    }
    
    if (temp->next != NULL)
       temp->next->prev = temp->prev;
    if (temp->prev != NULL)
       temp->prev->next = temp->next;

    temp->next = NULL;
    temp->prev = NULL;
    
    free(temp);    
    size--;
}

void display(struct Node **head)
{
    struct Node *temp = *head;
    printf("\nDisplaying elements : ");
    if (temp == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    while(temp != NULL)
    {
        printf(" %d ->",temp->data);
        temp = temp->next;
    }
    printf(" NULL");
}

int main()
{
    struct Node* head = NULL;
    insertAtBegin(&head,5);
    insertAtEnd(&head,3);
    display(&head);
}


