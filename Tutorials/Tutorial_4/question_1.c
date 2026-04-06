#include <stdio.h>
#include <stdlib.h>
// Delete Middle of Linked List by using Tortoise and Hare algorithm(fast and slow ptr approach )
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
void deleteMiddle(node **head, node **tail)
{
    // Checking for the edge case : empty list
    if (*head == NULL || *tail == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    // Checking for the edge case : only one node
    if (*head == *tail)
    {
        free(*head);
        *head = *tail = NULL;
        return;
    }
    node *prev = NULL, *slow = *head, *fast = *head;
    // finding the middle element of the list
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
    {
        if (prev == NULL)
            prev = *head;
        else
            prev = prev->next;
        slow = slow->next;
        fast = fast->next->next;
    }
    // in the case of even number of nodes
    if (fast != NULL && fast->next != NULL)
    {
        if (prev == NULL)
            prev = *head;
        else
            prev = prev->next;
        slow = slow->next;
        fast = fast->next;
    }
    // deleting the found middle element, which is stored by the slow pointer
    node *temp = slow->next;
    free(slow);
    prev->next = temp;
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
    deleteMiddle(&head, &tail);
    printf("The list after deleting the middle element is :\n");
    printList(head);
    freeMemory(&head);
    return 0;
}