#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *merged_start = NULL;
struct node *split_start = NULL;
struct node *ptr = NULL;
struct node *preptr = NULL;

struct node *create_node(int val) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

void append(struct node **start, int val) {
    struct node *new_node = create_node(val);
    if (*start == NULL) {
        *start = new_node;
        return;
    }
    ptr = *start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
}

struct node *copy_list(struct node *start) {
    if (start == NULL) return NULL;
    struct node *new_head = NULL;
    struct node *tail = NULL;
    ptr = start;
    while (ptr != NULL) {
        struct node *new_node = create_node(ptr->data);
        if (new_head == NULL) {
            new_head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        ptr = ptr->next;
    }
    return new_head;
}

void display(struct node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    ptr = start;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val, pos, i, n;

    while (1) {
        printf("1. Input elements for List 1\n");
        printf("2. Input elements for List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Merge List 1 and List 2\n");
        printf("6. Display Merged List\n");
        printf("7. Split List 1\n");
        printf("8. Display Split Lists\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements to enter in List 1: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &val);
                    append(&start1, val);
                }
                break;

            case 2:
                printf("Enter number of elements to enter in List 2: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &val);
                    append(&start2, val);
                }
                break;

            case 3:
                printf("List 1: ");
                display(start1);
                break;

            case 4:
                printf("List 2: ");
                display(start2);
                break;

            case 5:
                if (start1 == NULL && start2 == NULL) {
                    printf("Both lists are empty!\n");
                    break;
                }
                merged_start = copy_list(start1);
                struct node *temp2 = copy_list(start2);

                if (merged_start == NULL) {
                    merged_start = temp2;
                } else {
                    ptr = merged_start;
                    while (ptr->next != NULL) {
                        ptr = ptr->next;
                    }
                    ptr->next = temp2;
                }
                printf("Lists merged into a separate Merged List.\n");
                break;

            case 6:
                printf("Merged List: ");
                display(merged_start);
                break;

            case 7:
                if (start1 == NULL) {
                    printf("List 1 is empty!\n");
                    break;
                }

                printf("Enter position after which to split List 1: ");
                scanf("%d", &pos);

                ptr = start1;
                preptr = NULL;

                for (i = 1; i <= pos && ptr != NULL; i++) {
                    preptr = ptr;
                    ptr = ptr->next;
                }

                if (preptr == NULL || ptr == NULL) {
                    printf("Invalid position!\n");
                } else {
                    preptr->next = NULL;
                    split_start = ptr;
                    printf("List 1 split successfully.\n");
                }
                break;

            case 8:
                printf("First Part of Split (List 1): ");
                display(start1);
                printf("Second Part of Split: ");
                display(split_start);
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
