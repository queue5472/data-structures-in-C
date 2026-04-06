#include <stdio.h>
#include <stdlib.h>
// Reverse a Linked List
typedef struct node
// creating a user-defined 'node' data structure with the alias 'node'.
{
    int data;
    struct node *next;
} node;
void insertAtLast(node **head, node **tail)
// function to insert a node at the end of the Singly Linked List
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    printf("Enter the data you want to add into the node\n");
    scanf("%d", &new_node->data);
    if (*tail != NULL)
    {
        (*tail)->next = new_node;
    }
    else
    {
        *head = new_node;
    }
    *tail = new_node;
}
void insertAtFirst(node **head, node **tail)
// function to insert a node at the beginning of the Singly Linked List
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    printf("Enter the data you want to add into the node\n");
    scanf("%d", &new_node->data);
    if (*head != NULL)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        *head = *tail = new_node;
    }
}
node *reverseList(node **head, node **tail)
// reverses the list and returns the pointer to the head of the reversed list
{
    node *prev = NULL, *curr = *head;
    while (curr != NULL)
    {
        node *temp = curr->next;
        // reversing the pointers
        curr->next = prev;

        prev = curr;
        curr = temp;
    }
    return prev;
}
void printList(node *head)
// function to print the Singly Linked List
{
    if (head == NULL)
    {
        printf("EMPTY LIST\n");
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void freeMemory(node **head)
// function to free the dynamically allocated memory through malloc
{
    node *temp = *head;
    while (temp != NULL)
    {
        node *traverse = temp->next;
        free(temp);
        temp = traverse;
    }
    *head = NULL;
}
int main()
{
    node *head = NULL, *tail = NULL;
    char more = 'y';
    while (more == 'y')
    {
        int ch;
        printf("Enter 1 to insert a node at the beginning and 2 to insert at the last\n");
        scanf("%d", &ch);
        if (ch == 1)
            insertAtFirst(&head, &tail);
        if (ch == 2)
            insertAtLast(&head, &tail);
        printf("Do you want to add another node?\n");
        scanf(" %c", &more);
    }
    printf("The original linked list is :\n");
    printList(head);
    node *reversed_head = reverseList(&head, &tail);
    printf("The reversed linked list is :\n");
    printList(reversed_head);
    freeMemory(&head);
    return 0;
}
