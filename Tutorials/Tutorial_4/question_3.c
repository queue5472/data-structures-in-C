#include <stdio.h>
#include <stdlib.h>
// delete without head pointer
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
node *find_node(node **head, int x)
// finds the node which has to be deleted based on the data provided by the user
{
    node *temp = *head;
    while (temp->data != x)
    {
        temp = temp->next;
    }
    return temp;
}
void deleteNode_1(node **del)
// deletes the node using only the address of the node to be deleted, not the head pointer
{
    (*del)->data = (*del)->next->data;
    struct node *temp = (*del)->next->next;
    free((*del)->next);
    (*del)->next = temp;
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
    printf("The original list is :\n");
    printList(head);
    int del;
    printf("Enter the data in the node to be deleted\n");
    scanf("%d", &del);
    node *del_node = find_node(&head, del);
    deleteNode_1(&del_node);
    printf("The list after deletion is :\n");
    printList(head);
    freeMemory(&head);
    return 0;
}