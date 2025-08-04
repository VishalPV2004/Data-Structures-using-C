#include <stdio.h>
#define MAXSIZE 100
#define SUCCESS 0
#define FAILURE -1

int CIRCULAR_QUEUE[MAXSIZE];
int front = -1;
int rear = -1;

int enqueue() {
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);

    if ((rear + 1) % MAXSIZE == front) {
        printf("BUFFER OVERFLOW\n");
        return FAILURE;
    }

    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAXSIZE;
    }
    CIRCULAR_QUEUE[rear] = data;
    return SUCCESS;
}

int deque() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return FAILURE;
    }

    int data = CIRCULAR_QUEUE[front];

    if (front == rear) {
        // Only one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAXSIZE;
    }

    return data;
}

int peek() {
    if (front == -1) {
        printf("Queue is empty\n");
        return FAILURE;
    }
    return CIRCULAR_QUEUE[rear];
}

int display() {
    if (front == -1 && rear == -1) {
        printf("Queue underflow!\n");
        return FAILURE;
    }

    printf("Displaying contents...\n");
    int i = front;
    while (1) {
        printf("%d ", CIRCULAR_QUEUE[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
    return SUCCESS;
}

int main() {
    int ch, res;

    printf("1. Enqueue\n2. Deque\n3. Display\n4. Peek\n5. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                res = enqueue();
                if (res == SUCCESS)
                    printf("Enqueued successfully!\n");
                else
                    printf("Enqueue Failure!\n");
                break;

            case 2:
                res = deque();
                if (res != FAILURE)
                    printf("Deque successful: %d\n", res);
                else
                    printf("Deque Failure\n");
                break;

            case 3:
                display();
                break;

            case 4: {
                int data = peek();
                if (data != FAILURE)
                    printf("Data at rear: %d\n", data);
                break;
            }

            case 5:
                return 0;

            default:
                printf("INVALID choice\n");
                break;
        }
    }
}
