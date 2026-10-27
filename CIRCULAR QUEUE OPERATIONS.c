#include <stdio.h>
#define MAX 3

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int element)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = element;
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element = %d\n", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % MAX;
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Elements are:\n");

    for (i = front; ; i = (i + 1) % MAX)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;
    }

    printf("\n");
}

int main()
{
    int choice, element;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                enqueue(element);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
