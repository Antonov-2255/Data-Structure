#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
} *front, *rear, *ptr;

void enque()
{
    ptr = (struct node *)malloc(sizeof(struct node)); // Remove the * in sizeof
    if (ptr == NULL)
    {
        printf("\n Queue OVERFLOW..!!");
        return;
    }
    else
    {
        if (front == NULL)
        {
            printf("\nENTER 1st Node:");
            scanf("%d", &ptr->value);
            ptr->next = NULL;
            front = ptr;
            rear = ptr;
        }
        else
        {
            printf("\nENTER Node:");
            scanf("%d", &ptr->value);
            ptr->next = NULL;
            rear->next = ptr;
            rear = ptr;
        }
    }
}

void deque()
{
    if (front == NULL)
    {
        printf("\n Queue UNDERFLOW..!!!");
        return;
    }
    else
    {
        ptr = front;
        if (front == rear)
        {
            front = NULL;
            rear = NULL;
        }
        else
        {
            front = ptr->next;
        }
        printf("\n DELETED VALUE IS %d", ptr->value); // Change ptr->info to ptr->value
        free(ptr);
    }
}

void travers()
{
    if (front == NULL)
    {
        printf("\n Queue is empty..!!!");
        return;
    }
    else
    {
        ptr = front;
        while (ptr != NULL)
        {
            printf("\n%d", ptr->value);
            ptr = ptr->next;
        }
    }
}

int main() // Change void main() to int main()
{
    int ch;
    while (1)
    {
        printf("\n1. enque \n2. deque \n3. Travers \n4. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enque();
            break; // insert
        case 2:
            deque();
            break; // delete
        case 3:
            travers();
            break; // display
        case 4:
            exit(0);
        default:
            printf("\n Please enter a valid choice 1-4:");
        }
    }

    return 0; // Add a return statement to indicate successful execution
}
