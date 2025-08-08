#include<stdio.h>
#include<stdlib.h>

static int size = 0;

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory Allocation failed!\n");
        return NULL;
    }
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void insertAtBegin(struct Node **head, int data) {
    struct Node *temp = createNode(data);
    temp->next = *head;
    *head = temp;
    size++;
}

void insertAtEnd(struct Node **head, int data) {
    struct Node *temp = createNode(data);
    if (*head == NULL) {
        *head = temp;
    } else {
        struct Node *ptr = *head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
    size++;
}

void insertAtPosition(struct Node **head, int pos, int data) {
    if (pos < 1 || pos > size + 1) {
        printf("Position out of bounds!\n");
        return;
    }

    if (pos == 1) {
        insertAtBegin(head, data);
        return;
    }
    
    if (pos == size+1)
    {
        insertAtEnd(head, data);
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    struct Node *node = createNode(data);
    node->next = temp->next;
    temp->next = node;
    size++;
}

void deleteAtBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Underflow\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
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
    while(temp->next->next != NULL)
    {
        temp = temp -> next;
    }
    struct Node *del = temp->next;
    temp->next = NULL;
    size--;
    free(del);
}

void deleteAtPosition(struct Node **head, int pos)
{
    if (pos < 1 || pos > size)
    {
        printf("Invalid position\n");
        return ;
    }
    if (pos == 1)
    {
        deleteAtBeginning(head);
        return;
    }
    if (pos == size)
    {
        deleteAtEnd(head);
        return;
    }
    struct Node *temp = *head;
    
    for(int i = 1 ; i < (pos - 1) ; i++)
    {
       temp = temp->next;   
    }
    struct Node *tmp = temp->next;
    temp->next = temp->next->next;
    size--;
    free(tmp);
}

void display(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = *head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    insertAtBegin(&head, 5);    
    insertAtBegin(&head, 3);    
    insertAtPosition(&head, 2, 10); 
    insertAtEnd(&head, 7);
    //deleteAtBeginning(&head);
    //deleteAtPosition(&head,1);
    deleteAtPosition(&head,5);
    //deleteAtPosition(&head,1);
    display(&head);
    return 0;
}
