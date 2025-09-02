#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int count = 0;

typedef struct Node
{
    int id;
    int interview_score;
    double salary;
    char *name;
    struct Node* next;
}node;

struct Node* head = NULL;

struct Node* createNode(int id, int interview_score, double salary, char *name)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    ptr->id = id;
    ptr->interview_score = interview_score;
    ptr->salary = salary;
    ptr->name = strdup(name);  
    ptr->next = NULL;
    
    return ptr;
}

struct Node* createAndAssignNode()
{
    int id, interview_score;
    double salary;
    char name[100];
    
    printf("Enter ID : ");
    scanf("%d",&id);
    
    printf("Enter interview score : ");
    scanf("%d",&interview_score);
    
    printf("Enter salary : ");
    scanf("%lf",&salary);
    
    printf("Enter your name : ");
    scanf("%s",name);
    
    struct Node* node = createNode(id,interview_score,salary,name);
    return node;
}

void unwrap_node(struct Node * node)
{
    if (node == NULL)
    {
        printf("NULL PTR!\n");
        return;
    }
    printf("\nID : %d, Interview score : %d, Salary : %.2lf, Name : %s\n",
           node->id, node->interview_score, node->salary, node->name);
}

void insert_at_beginning(struct Node* node)
{
    count++;
    node->next = head;
    head = node;
}

void insert_at_end(struct Node* node)
{
    count++;
    if (head == NULL)
    {
        head = node;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
}

void insert(struct Node* node, int position)
{
    if (position == 1)
    {
        insert_at_beginning(node);
    }
    else if (position == count+1)
    {
        insert_at_end(node);
    }
    else if (position > count+1 || position < 1)
    {
        printf("Invalid position\n");
    }
    else
    {
        count++;
        struct Node *temp = head;
        int i = 1;
        while(i < position-1)
        {
            temp = temp->next;
            i++;
        }
        node->next = temp->next;
        temp->next = node;
    }
}

void display()
{
    if (count == 0)
    {
        printf("LIST EMPTY!\n");
        return;
    }
    struct Node * temp = head;
    printf("\n---- Linked List Contents ----\n");
    while(temp != NULL)
    {
        unwrap_node(temp);
        temp = temp->next;
    }
    printf("------------------------------\n");
}

void update(int position, struct Node * node)
{
    if (position > count || position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1)
    {
        node->next = head->next;
        free(head->name);
        free(head);
        head = node;
        return;
    }

    struct Node * temp = head;
    int i = 1;
    while(i < position-1)
    {
        temp = temp->next;
        i++;
    }

    struct Node * toDelete = temp->next;
    node->next = toDelete->next;
    free(toDelete->name);
    free(toDelete);
    temp->next = node;
}

struct Node* delete_at_beginning()
{
    if (count == 0)
    {
        printf("Underflow list!\n");
        return NULL;
    }
    count--;
    struct Node * temp = head;
    head = head->next;
    temp->next = NULL;
    return temp;
}

struct Node* delete_at_end()
{
    if (count == 0)
    {
        printf("Underflow list!\n");
        return NULL;
    }
    count--;
    struct Node *temp = head;
    if (temp->next == NULL)
    {
        head = NULL;
        return temp;
    }
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    struct Node *pop = temp->next;
    temp->next = NULL;
    return pop;
}

struct Node* delete(int position)
{
    if (count == 0)
    {
        printf("List Underflow\n");
        return NULL;
    }
    if (position == 1)
    {
        return delete_at_beginning();
    }
    else if (position == count)
    {
        return delete_at_end();
    }
    else if (position > count || position < 1)
    {
        printf("INVALID position\n");
        return NULL;
    }
    count--;
    int i = 1;
    struct Node* temp = head;
    while(i < position-1)
    {
        temp = temp->next;
        i++;
    }
    struct Node * node = temp->next;
    temp->next = temp->next->next;
    node->next = NULL;
    return node;
}

void free_list()
{
    struct Node * temp = head;
    while(temp != NULL)
    {
        struct Node * next = temp->next;
        free(temp->name);
        free(temp);
        temp = next;
    }
    head = NULL;
    count = 0;
}

int main()
{
    while(1)
    {
        int choice;
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Update\n5.Exit\nEnter choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
            {
                int pos;
                printf("Enter the position to insert : ");
                scanf("%d",&pos);
                node* Nod = createAndAssignNode();
                insert(Nod,pos);
                break;
            }
            
            case 2:
            {
                int pos;
                printf("Enter the position to delete : ");
                scanf("%d",&pos);
                node* Nod = delete(pos);
                unwrap_node(Nod);
                if (Nod) {
                    free(Nod->name);
                    free(Nod);
                }
                break;
            }
            
            case 3:
            {
                display();
                break;
            }
            
            case 4:
            {
                int pos;
                printf("Enter position to update : ");
                scanf("%d",&pos);
                node* Nod = createAndAssignNode();
                update(pos,Nod);
                break;
            }
            
            case 5:
            {
                printf("Exiting...\n");
                free_list();
                return 0;
            }
            default : 
            {
                printf("INVALID CHOICE!\n");
                break;
            }
        }
    }
    return 0;
}
