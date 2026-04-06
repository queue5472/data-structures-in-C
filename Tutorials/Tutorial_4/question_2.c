#include <stdio.h>
#include <stdlib.h>
// Detect and remove loop in a linked list using Floyd's Cycle Detection Algorithm
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
node *detect_loop(node *head)
// detects a loop in the linked list if it exists
{
    node *p = head, *q = head;
    while (p && q && q->next) // none of these pointers should be NULL, otherwise the loop stops
    {
        p = p->next;
        q = q->next->next;
        if (p == q)
            return p;
    }
    return NULL;
}
void remove_loop(node *p, node **head)
// finds the starting point of the loop, and removes it
{
    if (p == NULL)
    {
        printf("NO Loop Detected\n");
        return;
    }
    node *q = *head;
    while (p != q) // Floyd's Cycle Detection algorithm
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL; // Cuts off the linked list at the starting of the loop
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
    int count = 0;
    while (more == 'y')
    {
        int ch;
        printf("Enter 1 to insert a node at the beginning and 2 to insert at the last\n");
        scanf("%d", &ch);
        if (ch == 1)
            insertAtFirst(&head, &tail);
        else if (ch == 2)
            insertAtLast(&head, &tail);
        ++count;
        printf("Do you want to add another node?\n");
        scanf(" %c", &more);
    }
    printList(head);
    int x;
    printf("Enter the size of the loop\n");;
    scanf("%d",&x);
    if(x==0)
    {
        printf("No loop.\n");
        printList(head);
        return 1;
    }
    node *temp = head;
    for(int i = 1;temp!=NULL&& i<count-x;i++)
        temp = temp->next;
    tail->next = temp;
    remove_loop(detect_loop(head),&head);
    printList(head);
    freeMemory(&head);
    return 0;
}