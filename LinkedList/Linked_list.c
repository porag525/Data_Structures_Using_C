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
   LinkedlistTravers(head);
   return 0;
}