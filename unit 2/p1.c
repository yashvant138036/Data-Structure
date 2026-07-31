#include <stdio.h>

#define MAX 10

int stack[MAX];
int top = -1;


void push()
{
    int value;

    if (top == MAX - 1)
    {
        printf("\nStack Overflow!\n");
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("Value pushed successfully.\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow!\n");
    }
    else
    {
        printf("\nPopped value = %d\n", stack[top]);
        top--;
    }
}

void print()
{
    int i;

    if (top == -1)
    {
        printf("\nStack is Empty!\n");
    }
    else
    {
        printf("\nStack elements are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

void peek()
{
    if (top == -1)
    {
        printf("\nStack is Empty!\n");
    }
    else
    {
        printf("\nTop element = %d\n", stack[top]);
    }
}

void peep()
{
    int position;

    printf("\nEnter position from top: ");
    scanf("%d", &position);

    if (top - position + 1 < 0)
    {
        printf("\nInvalid Position!\n");
    }
    else
    {
        printf("\nElement = %d\n", stack[top - position + 1]);
    }
}

void change()
{
    int position, value;

    printf("\nEnter position from top: ");
    scanf("%d", &position);

    if (top - position + 1 < 0)
    {
        printf("\nInvalid Position!\n");
    }
    else
    {
        printf("Enter new value: ");
        scanf("%d", &value);

        stack[top - position + 1] = value;

        printf("\nValue changed successfully.\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n\n===== STACK MENU =====");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Print");
        printf("\n4. Peek");
        printf("\n5. Peep");
        printf("\n6. Change");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                print();
                break;

            case 4:
                peek();
                break;

            case 5:
                peep();
                break;

            case 6:
                change();
                break;

            case 7:
                printf("\nProgram Exit.\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 7);

    return 0;
}
