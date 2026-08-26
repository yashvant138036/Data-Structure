#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp, *newnode, *prev;
    int n, i, data, key, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    printf("\nOriginal List: ");
    temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("\n1. Insert After Specific Node");
    printf("\n2. Insert Before Specific Node");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    printf("Enter specific node: ");
    scanf("%d", &key);

    printf("Enter new data: ");
    scanf("%d", &data);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if(choice == 1)
    {
        temp = head;

        while(temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }

        if(temp == NULL)
        {
            printf("Node not found.");
        }
        else
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    else if(choice == 2)
    {
        temp = head;
        prev = NULL;

        while(temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
        {
            printf("Node not found.");
        }
        else if(temp == head)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            newnode->next = temp;
            prev->next = newnode;
        }
    }
    else
    {
        printf("Invalid choice.");
    }

    printf("\nFinal List: ");
    temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}

