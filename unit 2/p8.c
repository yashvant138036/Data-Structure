#include<stdio.h>

#define max 10

int queue[max];
int front = -1, rear = -1;

void insert()
{
    int val;

    if(rear == max - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &val);

        if(front == -1)
            front = 0;

        queue[++rear] = val;
    }
}

void delete()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted = %d\n", queue[front]);
        front++;

        if(front > rear)
        {
            front = rear = -1;
        }
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue Elements: ");

        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int ch;

    while(1)
    {
        printf("\n----- Queue Menu -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
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
                printf("Program Ended.\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
