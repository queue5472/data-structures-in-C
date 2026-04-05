#include <stdio.h>
#include <stdlib.h>
// Remove duplicates from a sorted linked list
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
void deleteFirst(node **head, node **tail)
// function to delete the first node of the Singly Linked List
{
    if (*head != NULL)
    {
        node *temp = (*head)->next;
        free(*head);
        *head = temp;
    }
    else
    {
        printf("The list is already empty\n");
        return;
    }
}
void deleteLast(node **head, node **tail)
// function to delete the first node of the singly Linked List
{
    if (*tail != NULL)
    {
        node *temp = *head;
        while (temp->next != *tail)
        {
            temp = temp->next;
        }
        free(*tail);
        *tail = temp;
        (*tail)->next = NULL;
    }
    else
    {
        printf("The list is already empty\n");
        return;
    }
}
void delete_duplicates(node **head)
// deletes duplicate elements from a sorted list
{
    node *curr = *head;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            node *del = curr->next;
            curr->next = curr->next->next;
            free(del);
        }
        else
        {
            curr = curr->next;
        }
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
    printf("Please insert the elements in ascending order\n");
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
    more = 'y';
    while (more == 'y')
    {
        int ch;
        printf("Enter 1 to delete a node from the beginning and 2 to delete a node from the end. Otherwise, Enter -1\n");
        scanf("%d", &ch);
        if (ch == 1)
            deleteFirst(&head, &tail);
        else if (ch == 2)
            deleteLast(&head, &tail);
        printf("Do want to delete another node?\n");
        scanf(" %c", &more);
    }
    delete_duplicates(&head);
    printf("The list after deleting duplicates is :\n");
    printList(head);
    freeMemory(&head);
    return 0;
}