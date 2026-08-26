#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createList()
{
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int n, value;

    printf("Enter the number of nodes to create: ");
    if (scanf("%d", &n) != 1) return NULL;

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void displayList(struct Node* head)
{
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* insertAtBeginning(struct Node* head, int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* insertAfterNode(struct Node* head, int target, int value)
{
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", target);
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* insertBeforeNode(struct Node* head, int target, int value)
{
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->data == target) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Node with value %d not found.\n", target);
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* deleteFirst(struct Node* head)
{
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteLast(struct Node* head)
{
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* deleteSpecific(struct Node* head, int target)
{
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->data == target) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Node with value %d not found.\n", target);
        return head;
    }

    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    return head;
}

int main()
{
    struct Node* head = NULL;
    int choice, value, target;

    while (1) {
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Insert at Starting\n");
        printf("4. Insert at End\n");
        printf("5. Insert After Specific Node\n");
        printf("6. Insert Before Specific Node\n");
        printf("7. Delete First Node\n");
        printf("8. Delete Last Node\n");
        printf("9. Delete Specific Node\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createList();
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter value to insert at starting: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 5:
                printf("Enter the target node value after which to insert: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertAfterNode(head, target, value);
                break;
            case 6:
                printf("Enter the target node value before which to insert: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertBeforeNode(head, target, value);
                break;
            case 7:
                head = deleteFirst(head);
                break;
            case 8:
                head = deleteLast(head);
                break;
            case 9:
                printf("Enter the node value to delete: ");
                scanf("%d", &target);
                head = deleteSpecific(head, target);
                break;
            case 10:
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
