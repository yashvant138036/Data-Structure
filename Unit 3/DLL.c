#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

void create()
{
    struct node *ptr, *preptr;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        ptr = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &ptr->data);
        ptr->prev = NULL;
        ptr->next = NULL;
        if(start == NULL) {
            start = ptr;
        } else {
            preptr = start;
            while(preptr->next != NULL) {
                preptr = preptr->next;
            }
            preptr->next = ptr;
            ptr->prev = preptr;
        }
    }
}

void display()
{
    struct node *ptr;
    if(start == NULL) {
        printf("List is empty\n");
        return;
    }
    ptr = start;
    printf("List elements: ");
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert_start()
{
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    ptr->prev = NULL;
    ptr->next = start;
    if(start != NULL) {
        start->prev = ptr;
    }
    start = ptr;
}

void insert_end()
{
    struct node *ptr, *preptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    if(start == NULL) {
        ptr->prev = NULL;
        start = ptr;
        return;
    }
    preptr = start;
    while(preptr->next != NULL) {
        preptr = preptr->next;
    }
    preptr->next = ptr;
    ptr->prev = preptr;
}

void insert_after()
{
    struct node *ptr, *preptr;
    int val;
    printf("Enter value after which to insert: ");
    scanf("%d", &val);
    preptr = start;
    while(preptr != NULL && preptr->data != val) {
        preptr = preptr->next;
    }
    if(preptr == NULL) {
        printf("Node not found\n");
        return;
    }
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    ptr->next = preptr->next;
    ptr->prev = preptr;
    if(preptr->next != NULL) {
        preptr->next->prev = ptr;
    }
    preptr->next = ptr;
}

void insert_before()
{
    struct node *ptr, *preptr;
    int val;
    printf("Enter value before which to insert: ");
    scanf("%d", &val);
    if(start == NULL) {
        printf("List is empty\n");
        return;
    }
    if(start->data == val) {
        insert_start();
        return;
    }
    preptr = start;
    while(preptr != NULL && preptr->data != val) {
        preptr = preptr->next;
    }
    if(preptr == NULL) {
        printf("Node not found\n");
        return;
    }
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    ptr->next = preptr;
    ptr->prev = preptr->prev;
    preptr->prev->next = ptr;
    preptr->prev = ptr;
}

void delete_first()
{
    struct node *ptr;
    if(start == NULL) {
        printf("List is empty\n");
        return;
    }
    ptr = start;
    start = start->next;
    if(start != NULL) {
        start->prev = NULL;
    }
    free(ptr);
    printf("Node deleted\n");
}

void delete_last()
{
    struct node *ptr;
    if(start == NULL) {
        printf("List is empty\n");
        return;
    }
    ptr = start;
    if(ptr->next == NULL) {
        start = NULL;
        free(ptr);
        printf("Node deleted\n");
        return;
    }
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    printf("Node deleted\n");
}

void delete_specific()
{
    struct node *ptr;
    int val;
    if(start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter value to delete: ");
    scanf("%d", &val);
    if(start->data == val) {
        delete_first();
        return;
    }
    ptr = start;
    while(ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }
    if(ptr == NULL) {
        printf("Node not found\n");
        return;
    }
    ptr->prev->next = ptr->next;
    if(ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
    printf("Node deleted\n");
}

int main()
{
    int choice;
    while(1) {
        printf("\n1. Create\n2. Display\n3. Insert Start\n4. Insert End\n5. Insert After\n6. Insert Before\n7. Delete First\n8. Delete Last\n9. Delete Specific\n10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_start();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                insert_after();
                break;
            case 6:
                insert_before();
                break;
            case 7:
                delete_first();
                break;
            case 8:
                delete_last();
                break;
            case 9:
                delete_specific();
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
