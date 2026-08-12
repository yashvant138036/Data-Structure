#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int n, data, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("\nOriginal List: ");
    display(head);

    printf("\nEnter data to insert at beginning: ");
    scanf("%d", &data);
    insertAtBeginning(&head, data);

    printf("After insertion at beginning: ");
    display(head);

    printf("\nEnter data to insert at end: ");
    scanf("%d", &data);
    insertAtEnd(&head, data);

    printf("After insertion at end: ");
    display(head);

    return 0;
}

