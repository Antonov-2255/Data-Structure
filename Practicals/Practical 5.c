#include <stdio.h>
#include <stdlib.h>

int queue[5];
int front = -1;
int rear = -1;

void insert()
{
    int n;
    if (rear == 4)
    {
        printf("\nQueue is full");
    }
    else
    {
        printf("Enter value of n: ");
        scanf("%d", &n);
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
        queue[rear] = n;
    }
}

void delete()
{
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1;
        }
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Values in the queue are: ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    int ch;
    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice");
                break;
        }
    } while (1);
}
