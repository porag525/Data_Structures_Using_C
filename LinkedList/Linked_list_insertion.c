#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *nxt;
};

void LinkedlistTravers(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element :%d\n", ptr->data);
        ptr = ptr->nxt;
    }
}

struct Node *InsertAtBegining(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->nxt = head;
    return ptr;
}

struct Node *InsertAtIndex(struct Node *head, int data, int idx)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != idx - 1)
    {
        p = p->nxt;
        i++;
    }
    ptr->data = data;
    ptr->nxt = p->nxt;
    p->nxt = ptr;

    return head;
}

struct Node *InsertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (p->nxt != NULL)
    {
        p = p->nxt;
    }
    ptr->data = data;
    p->nxt = ptr;
    ptr->nxt = NULL;
    return head;
}
struct Node *InsertAfter(struct Node *head, struct Node *previousNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->nxt = previousNode->nxt;
    previousNode->nxt = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    // Allocate memory for  nodes in the linkedlist in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link the first and second node;
    head->data = 100;
    head->nxt = second;

    // Link the second and third node;
    second->data = 200;
    second->nxt = third;

    // Terminate the list at the third node;
    third->data = 300;
    third->nxt = NULL;
    // LinkedlistTravers(head);

    // head = InsertAtBegining(head, 50);
    // LinkedlistTravers(head);

    // head = InsertAtIndex(head, 150, 2);
    // LinkedlistTravers(head);
    // head = InsertAtEnd(head, 500);
    // LinkedlistTravers(head);
    head = InsertAfter(head, third, 1);
    LinkedlistTravers(head);
    return 0;
}