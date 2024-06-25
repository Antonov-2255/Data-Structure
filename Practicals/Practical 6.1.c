#include<stdio.h>
#include<stdlib.h>

int queue[5];
int front = -1;
int rear = -1;

void enqueue()
{
    int n;
    if ((front == 0 && rear == 4) || (front == rear + 1))
    {
        printf("\nQueue is Full!!!");
    }
    else
    {
        printf("Enter Value of N: ");
        scanf("%d", &n);
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % 5;
        }
        queue[rear] = n;
    }
}

void dequeue()
{
    int n;
    if (front == -1)
    {
        printf("Queue is Empty!!!");
    }
    else
    {
        n = queue[front];
        printf("\nDeleted value is %d", n);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % 5;
        }
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is Empty!!!!\n");
    }
    else
    {
        printf("\nValue of Queue is: ");
        i = front;
        do
        {
            printf("%d ", queue[i]);
            i = (i + 1) % 5;
        } while (i != (rear + 1) % 5);
    }
}

/*void display()
{
    int i;
    if(front==-1)
    {
        printf("Queue is Empty!!!!");
    }
    else
    {
        printf("\n Value of Queue is: ");
        for(i=front; i!=rear; i=(i+1)%5)
        {
            printf("%d", queue[i]);
        }
        printf("|%d|", queue[i]);
    }
}*/


int main()
{
    int ch;
    do
    {
        printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit");
        printf("\n Enter Your Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Please enter a valid choice");
        }
    } while (1);
    return 0;
}
