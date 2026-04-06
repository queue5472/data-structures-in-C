#include <stdio.h>
#include <stdlib.h>
// Adds two numbers represented by linked lists
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
int power(int x, int y)
// function to calculate x^y
{
    int ans = 1;
    for (int i = 0; i < y; i++)
    {
        ans *= x;
    }
    return ans;
}
int sum_list_num(node **headA, node **headB, int a, int b)
// finds the sum of the numbers represented by lists A and B, with a and b digits(nodes) respectively
{
    int pow_a = power(10, a - 1);
    int pow_b = power(10, b - 1);
    int num_a = 0, num_b = 0;
    node *tempA = *headA, *tempB = *headB;
    while (tempA != NULL)
    {
        num_a += (tempA->data) * pow_a;
        pow_a /= 10;
        tempA = tempA->next;
    }
    while (tempB != NULL)
    {
        num_b += (tempB->data) * pow_b;
        pow_b /= 10;
        tempB = tempB->next;
    }
    return num_a + num_b;
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
    node *headA = NULL, *tailA = NULL;
    char more = 'y';
    int a, b;
    printf("Enter the number of nodes in List A\n");
    scanf("%d", &a);
    while (more == 'y')
    {
        int ch;
        printf("Enter 1 to insert a node at the beginning and 2 to insert at the last of the first list.\n");
        scanf("%d", &ch);
        if (ch == 1)
            insertAtFirst(&headA, &tailA);
        if (ch == 2)
            insertAtLast(&headA, &tailA);
        printf("Do you want to add another node?\n");
        scanf(" %c", &more);
    }
    printList(headA);
    node *headB = NULL, *tailB = NULL;
    printf("Enter the number of nodes in List B\n");
    scanf("%d", &b);
    more = 'y';
    while (more == 'y')
    {
        int ch;
        printf("Enter 1 to insert a node at the beginning and 2 to insert at the last of the second list.\n");
        scanf("%d", &ch);
        if (ch == 1)
            insertAtFirst(&headB, &tailB);
        if (ch == 2)
            insertAtLast(&headB, &tailB);
        printf("Do you want to add another node?\n");
        scanf(" %c", &more);
    }
    printf("The sum of the numbers represented by linked lists is %d\n", sum_list_num(&headA, &headB, a, b));
    freeMemory(&headA);
    freeMemory(&headB);
    return 0;
}