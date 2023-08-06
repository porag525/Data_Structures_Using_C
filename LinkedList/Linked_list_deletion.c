#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *nxt;
};

void Linkedlist_Travers(struct Node *ptr)
{
    printf("Linkedlist elements:\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->nxt;
    }
    printf("\n");
}

struct Node *Insert_At_End(struct Node *head, int data)
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

struct Node *Delete_The_Head(struct Node *head)
{
    struct Node *p = head;
    head = head->nxt;
    free(p);
    printf("After delete the head node:\n");
    return head;
}
struct Node *Delete_The_Last(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = p->nxt;
    while (q->nxt != NULL)
    {
        p = q;
        q = q->nxt;
    }
    free(q);
    p->nxt = NULL;
    printf("After delete the Last node:\n");
    return head;
}
struct Node *Delete_At_Given_Index(int idx, struct Node *head)
{
    struct Node *p = head;
    int c = 1;
    while (c < idx - 1)
    {
        p = p->nxt;
        c++;
    }
    struct Node *q = p->nxt;
    p->nxt = q->nxt;
    free(q);
    printf("After delete the node at given idx %d:\n", idx);
    return head;
}
struct Node *Delete_At_Given_Value(int value, struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->nxt;
    while (q->data != value && q->nxt != NULL)
    {
        p = p->nxt;
        q = q->nxt;
    }
    if (q->data == value)
    {
        p->nxt = q->nxt;
        free(q);
        printf("After delete the node at given value :\n");
        return head;
    }
    else
    {
        printf("Given value not found in the Linkedlist !!!!!!!!!!\n");
        return head;
    }
}

int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1;
    head->nxt = NULL;

    head = Insert_At_End(head, 2);
    head = Insert_At_End(head, 3);
    head = Insert_At_End(head, 4);
    head = Insert_At_End(head, 5);
    Linkedlist_Travers(head);
    // head=Delete_The_Head(head);
    // Linkedlist_Travers(head);
    // head=Delete_The_Last(head);
    // Linkedlist_Travers(head);
    // head = Delete_At_Given_Index(4, head);
    // Linkedlist_Travers(head);
    head = Delete_At_Given_Value(10, head);
    Linkedlist_Travers(head);
}