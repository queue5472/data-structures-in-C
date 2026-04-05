#include <stdio.h>
#include <stdlib.h>
// Partitioning a linked list around a given value and keeping the original order
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
void concatenate(node **headA, node **headB, node **headC, node **tailA, node **tailB)
// concatenates three lists
{
    (*tailA)->next = *headB;
    (*tailB)->next = *headC;
}
void append(node **head, node **tail, int x)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->data = x;
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
node *partitioning(node **head, node **tail, int x)
// creates a new list by placing all elements lesser than x before x, and all greater, after x
// preserving the original relative order and returns the pointer to the new list
{
    node *head_l = NULL, *tail_l = NULL, *head_e = NULL, *tail_e = NULL, *head_g = NULL, *tail_g = NULL; // l-> lesser, e -> equal, g-> greater
    node *temp = *head;
    while (temp != NULL)
    {
        if (temp->data < x)
        {
            append(&head_l, &tail_l, temp->data);
        }
        else if (temp->data == x)
        {
            append(&head_e, &tail_e, temp->data);
        }
        else
        {
            append(&head_g, &tail_g, temp->data);
        }
        temp = temp->next;
    }
    concatenate(&head_l, &head_e, &head_g, &tail_l, &tail_e);
    return head_l;
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
    printf("Enter the element along which you want to partition\n");
    scanf("%d", &x);
    printf("The list after partition is :\n");
    node *new_head = partitioning(&head, &tail, x);
    printList(new_head);
    freeMemory(&head);
    freeMemory(&new_head);
    return 0;
}