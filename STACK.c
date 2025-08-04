#include<stdio.h>
#include <stdlib.h>
#define SIZE 100
#define SUCCESS 0
#define FAILURE 1

int STACK[SIZE] = {0};
int top = -1;

int push()
{
    int data;
    printf("Enter data to be pushed : ");
    scanf("%d",&data);
    
    if (top >= SIZE-1)
    {
        printf("OVERFLOW");
        return FAILURE;
    }
    
    STACK[++top] = data;
    return SUCCESS;
}

int pop()
{
    int data;
    printf("Popping data : ");
    
    if (top == -1)
    {
        printf("UNDERFLOW");
        return FAILURE;
    }
    
    data = STACK[top--];
    return data;
}

int display()
{
    if (top == -1)
    {
        return FAILURE;
    }
    
    for(int temp = 0 ; temp <= top ; temp++)
    {
        printf("%d ",STACK[temp]);
    }
    return SUCCESS;
}

int peek()
{
    if (top == -1)
      return FAILURE;
    
    return STACK[top];
}
int main()
{
    printf("1. PUSH\n2. POP\n3. DISPLAY\n4. PEEK\n 5.EXIT\n");
    
    int ch;
    int res;
    while(1)
    {
        printf("\nEnter your choice : \n");
        scanf("%d",&ch);
        
        switch(ch)
        {
                case 1:
                    res = push();
                    if (res == SUCCESS)
                       printf("\nPUSH Successful!\n");
                    else
                       printf("\nPUSH FAILED\n");
                    break;
                
                case 2:
                    res = pop();
                    if (res != FAILURE)
                       printf("\nPOP Successful! : %d\n",res);
                    else
                       printf("\nPOP Failed\n");
                    break;
                
                case 3:
                    res = display();
                    if (res == FAILURE)
                        printf("\nSTACK EMPTY!\n");
                    else
                        printf("\nDISPLAY SUCCESSFUL\n");
                    break;
                
                case 4:
                    int data = peek();
                    if (data != FAILURE)
                       printf("\nData at top : %d\n",data);
                    else
                       printf("\nSTACK EMPTY!\n");
                    break;
                
                case 5:
                    printf("\nEXITING....\n");
                    exit(0);
                    break;
                
                default:
                    printf("\nINVALID INPUT\n");
                    break;
        }
    }
}
