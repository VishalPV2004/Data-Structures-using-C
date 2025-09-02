#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
int *stack;
int top = -1;

void PUSH(int num);
int POP();
void DISPLAY();
int PEEK();

int main()
{
    stack = (int*)calloc(MAX_SIZE, sizeof(int));
    while(1)
    {
        printf("1.PUSH 2.POP 3.DISPLAY 4.PEEK 5.EXIT\n");
        int ch;
        printf("Enter your choice : ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
            {
              int num;
              printf("Enter the data : ");
              scanf("%d",&num);
              PUSH(num);
            break;
            }
            
            case 2:
            {
              int pop = POP();
              if (pop != -1)
              {
                  printf("Poppped element : %d\n",pop);
              }
            break;
            }
            
            case 3:
            {
              int peek = PEEK();
              if (peek != -1)
              {
                  printf("Top element : %d\n",peek);
              }
            break;
            }
            
            case 4:
            {
               DISPLAY();
               break;
            }
            
            case 5:
            {
               free(stack);
               return 0;
            break;
            }
            
            default:{
               printf("INVALID OPTIONS!\n");
            break;
            }
        }
    }
    
    return 0;
}

//---------------------------------------------------------------------------

void PUSH(int data)
{
    if (top == MAX_SIZE-1)
    {
        printf("Stack is FULL!\n");
        return;
    }
    stack[++top] = data;
    printf("Data pushed!\n");
}

int POP()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
}

int PEEK()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

void DISPLAY()
{
    if (top == -1)
    {
        printf("Stack is Empty!\n");
        return;
    }
    
    for(int i = top ; i >= 0; i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
