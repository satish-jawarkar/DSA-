#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* createLinkedList(int a[], int n)
{
    Node* head = NULL;
    Node* last = NULL;
    for(int i=0; i<n; i++)
    {
        Node *myNode = (Node*)malloc(sizeof(Node));
        myNode->data = a[i];
        myNode->next = NULL;
        if(i==0)
        {
            last = myNode;
            head = myNode;
        }
        else
        {
            last->next = myNode;
            last = myNode;
        }
    }
    return head;
}

void printLinkedList(Node* head)
{
    while(head!=NULL)
    {
        printf("%d ->",head->data);
        head = head->next;
    }
    printf("\n");
}

void push(Node **head, int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int pop(Node **head)
{
    if(*head == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    Node *temp = *head;
    *head = (*head)->next;
    int poppedData = temp->data;
    free(temp);
    return poppedData;
}

int main()
{
    int n;
    printf("Enter the size of the linked list: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the linked list: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    Node *head = createLinkedList(a, n);
    printLinkedList(head);

    int choice;
    int dataToPush;
    while(1)
    {
        printf("Enter 1 to push, 2 to pop, 0 to exit: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the data to push onto the stack: ");
                scanf("%d", &dataToPush);
                push(&head, dataToPush);
                printLinkedList(head);
                break;

            case 2:
                int poppedData = pop(&head);
                printf("Popped data: %d\n", poppedData);
                printLinkedList(head);
                break;

            case 0:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}