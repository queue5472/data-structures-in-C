#include <stdio.h>
#include <stdlib.h>
// delete the last occurence of the given key
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
void deleteLastOccurence(node **head, node **tail, int x)
// finds and deletes the last occurence of x.
{
    node *curr = *head, *prev = NULL, *temp = NULL, *prev_temp = NULL;
    while (curr != NULL)
    {
        if (curr->data == x)
        {
            temp = curr;      // stores the pointer to the last occurence of x
            prev_temp = prev; // stores the pointer to the node just before x
        }
        curr = curr->next;
        if (prev == NULL)
            prev = *head;
        else
            prev = prev->next;
    }
    if (prev_temp != NULL)
    {
        node *del = temp;
        prev_temp->next = temp->next;
        free(del);
    }
    else
    {
        *head = temp->next;
        free(temp);
    }
}
void printList(node *head)
// function to print the Singly Linked List
{
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
    printList(head);
    int x;
    printf("Enter the key whose last occurence you want to delete\n");
    scanf("%d", &x);
    deleteLastOccurence(&head, &tail, x);
    printf("The list after deleting the last occurence of %d : \n", x);
    printList(head);
    freeMemory(&head);
    return 0;
}