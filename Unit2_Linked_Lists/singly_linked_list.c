#include <stdio.h>
#include <stdlib.h>

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
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the data \n");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

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

/*The above function takes a pointer to the pointer and thus modifies the original pointer this can also be implemented using a single pointer
and then proceeding to return that pointer and similarly assigning the function to the orignal function in the main function  */

node *insertAtLastAlternative1(node *head, node **tail)
{
    node *newb = malloc(sizeof(node));
    if (newb == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    printf("Whats the data ? \n");
    scanf("%d", &newb->data);
    newb->next = NULL;

    if (head == NULL)
    {
        head = newb;
        *tail = newb;
        return head;
    }

    if (*tail != NULL)
    {
        (*tail)->next = newb;
    }
    else
    {
        node *p = head;
        while (p->next)
            p = p->next;
        p->next = newb;
    }

    *tail = newb;
    return head;
    // ask your self why tail is using a double pointer instead of one ??
}
node *insertAtLastAlternative2(node *head)
{
    node *newb = (node *)malloc(sizeof(node));
    if (newb == NULL)
    {
        printf("Memory allocation failed\n");
        return head; // Return the original head if memory allocation fails
    }

    printf("Enter the data you want to add into the node\n");
    scanf("%d", &newb->data);
    newb->next = NULL;

    if (head == NULL)
    {
        return newb; // Return the new head if the list was previously empty
    }

    node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next; // points at the last node of the list
    }

    ptr->next = newb;
    return head;

} // this would also have worked as well as we are not changing the value of the head and thus we are not required to return it as well

// this can also be done using the pointer to the pointer method... How about you try that one out yourself ??

void insertAtFirst(node **head, node **tail)
// function to insert a node at the beginning of the Singly Linked List
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return; // Exit the function if memory allocation fails
        // Fun Fact: This actually is a concept checking the avail list which was borrowed from fortran and which even earlier versions of C had to check for avail list using something we called memory manager
        // It is also recommended that you guys read about the concepts of garbage collector and avail lists
    }

    printf("Enter the data you want to add into the node\n");
    scanf("%d", &new_node->data);

    if (*head == NULL)
    {
        *head = *tail = new_node;
        new_node->next = NULL;
    }
    else
    {
        new_node->next = *head;
        *head = new_node;
    }
}

// can you also do the alternative methods for this like we did for the insert at last function ? Try yourself and push the code here as well !!

void insertAtPosition(node **head, node **tail, int pos)
{
    if (pos <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    node *newb = (node *)malloc(sizeof(node));
    if (newb == NULL)
    {
        printf("Memory allocation failed, This happens when the avail list is empty and modern C helps us not check at it and does the checking itself and return null if failed like this situation\n ");
        return;
    }

    printf("Enter the data you want to add into the node\n");
    scanf("%d", &newb->data);

    if (pos == 1)
    {
        newb->next = *head;
        *head = newb;
        if (*tail == NULL)
        {
            *tail = newb; // tail bhi change karlo
        }
        return;
    }

    node *temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        free(newb); // Free the allocated memory if position is too much
        return;
    }

    newb->next = temp->next;
    temp->next = newb;

    if (newb->next == NULL)
    {
        *tail = newb; // Update tail if new node is inserted at the end
    }
}

// as you have prolly realised this shifts the current node at the position to the right and thus inserts the new node at the position and what if we needed to insert the new node before the position ? Check Below for that implementation

node *insertBeforePosition(node *head, node **tail, int pos)
{
    if (pos <= 0)
    {
        printf("Invalid position\n");
        return head;
    }

    node *newb = malloc(sizeof(node));
    if (newb == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    printf("Enter the data you want to add into the node\n");
    scanf("%d", &newb->data);
    newb->next = NULL;

    if (pos == 1)
    {
        newb->next = head;
        if (head == NULL) // empty list case
            *tail = newb;
        return newb;
    }

    node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        free(newb);
        return head;
    }

    newb->next = temp->next;
    temp->next = newb;

    if (newb->next == NULL)
    {
        *tail = newb;
    }

    return head;
}
void deleteFirst(node **head, node **tail)
{
    if (*head == NULL)
        return;

    node *temp = *head;
    *head = (*head)->next;

    if (*head == NULL)
        *tail = NULL;

    free(temp);
}

void deleteAtPosition(node **head, node **tail, int pos)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (pos == 1)
    {
        deleteFirst(head, tail);
        return;
    }

    node *temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }

    node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    if (temp->next == NULL)
    {
        *tail = temp; // Update tail if the last node is deleted
    }

    free(nodeToDelete);
}

// just like the insert functions can you write the alternative methods for the delete functions as well ? Try it out yourself and push the code here as well !!

void deleteLast(node **head, node **tail)
{
    if (*tail == NULL)
    {
        printf("The list is already empty\n");
        return;
    }

    if (*head == *tail)
    {
        free(*tail);
        *head = *tail = NULL;
        return;
    }

    node *temp = *head;
    while (temp->next != *tail)
    {
        temp = temp->next;
    }

    free(*tail);
    *tail = temp;
    (*tail)->next = NULL;
}

void concatenateLists(node **head_1, node **tail_1,
                      node *head_2, node *tail_2)
{
    if (*head_1 == NULL)
    {
        *head_1 = head_2;
        *tail_1 = tail_2;
        return;
    }

    if (head_2 == NULL)
        return;

    (*tail_1)->next = head_2;
    *tail_1 = tail_2;
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

    insertAtFirst(&head, &tail);
    insertAtLast(&head, &tail);

    head = insertAtLastAlternative1(head, &tail);
    head = insertAtLastAlternative2(head);

    insertAtPosition(&head, &tail, 2);
    head = insertBeforePosition(head, &tail, 2); // there is a lot of type mismatch in the arguement due to sticking to a particular method of implementation
    // I am sure you guys can realise most of the times we can and its preferable to use ** and void instead of returning the head and using * but it is always recommended to have knowledge of other methods

    printList(head);

    deleteFirst(&head, &tail);
    deleteAtPosition(&head, &tail, 2);
    deleteLast(&head, &tail);

    printList(head);

    node *head_2 = NULL, *tail_2 = NULL;
    insertAtLast(&head_2, &tail_2);
    insertAtLast(&head_2, &tail_2);

    concatenateLists(&head, &tail, head_2, tail_2);

    printList(head);

    freeMemory(&head);

    return 0;
}