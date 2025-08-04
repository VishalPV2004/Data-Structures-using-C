#include<stdio.h>
#define MAXSIZE 100
#define SUCCESS 0
#define FAILURE 1

int QUEUE[MAXSIZE] = {0};

int FRONT = 0;
int REAR = -1;

int enqueue()
{
    if (REAR >= MAXSIZE-1)
    {
        printf("OVERFLOW\n");
        return FAILURE;
    }
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    
    QUEUE[++REAR] = data;
    return SUCCESS;
}

int peek()
{
    if (REAR == -1)
      return FAILURE;
    
    int data = QUEUE[REAR];
    return data;
}

int display()
{
    if (REAR == -1)
      return FAILURE;
    
    int temp = FRONT;
    for(temp = FRONT ; temp <= REAR ; temp++)
    {
        printf("%d ",QUEUE[temp]);
    }
    
    return SUCCESS;
}

int deque()
{
    if (FRONT > REAR)
    {
        printf("UNDERFLOW\n");
        return FAILURE;
    }
    
    int data = QUEUE[FRONT++];
    return SUCCESS;
}
int main()
{
    printf("1. ENQUEUE\n 2. DEQUE\n 3. DISPLAY\n 4. PEEK\n");
    
    int ch;
    int res;
    while(1)
    {
        printf("Enter your choice : ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
               res = enqueue();
              if (res != FAILURE)
                 printf("Enqueued!\n");
              else
                 printf("EnQueue not successful\n");
              break;
            
            case 2:
               res = deque();
              if (res != FAILURE)
                 printf("Dequed!\n");
              else 
                 printf("Dqueue FAILURE\n");
              break;
             
            case 3:
                res = display();
               if (res == SUCCESS)
                  printf("DISPLAYED!\n");
               else
                  printf("QUEUE EMPTY\n");
              break;
             
            case 4:
               int data = peek();
               if (data != FAILURE)
                  printf("Data : %d\n",data);
               else
                  printf("QUEUE EMPTY!\n");
                break;
            
            default:
               printf("INVALID OPTION\n");
               break;
        }
    }
}
