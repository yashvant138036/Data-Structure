#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void createList(struct Node** head);
void displayList(struct Node* head);
void insertBeginning(struct Node** head);
void insertEnd(struct Node** head);

int main()
{
    struct Node* head = NULL;
    int choice;

    while (1) {
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Insert Node at Starting\n");
        printf("4. Insert Node at End\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList(&head);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                insertBeginning(&head);
                break;
            case 4:
                insertEnd(&head);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void createList(struct Node** head)
{
    int n, data, i;
    struct Node *newNode, *temp;

    if (*head != NULL) {
        printf("List is already created! You can use insertion operations.\n");
        return;
    }

    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    printf("Linked list created successfully!\n");
}

void displayList(struct Node* head)
{
    struct Node* temp = head;

    if (head == NULL) {
        printf("The list is currently empty.\n");
        return;
    }

    printf("Linked List contents: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertBeginning(struct Node** head)
{
    int value;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter value to insert at the starting: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;

    printf("Node inserted at the beginning successfully.\n");
}

void insertEnd(struct Node** head)
{
    int value;
    struct Node* temp;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter value to insert at the end: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Node inserted at the end successfully.\n");
}
