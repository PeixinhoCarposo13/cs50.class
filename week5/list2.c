#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int number;
  struct node *next;
} node;

int main()
{
  node *list = NULL;

  for (int i = 0; i < 3; i++)
  {
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
      return 1;
    }
    n->number = i + 1;
    n->next = NULL;

    // Prepend the new node to the list
    n->next = list;
    list = n;
  }

  // Print the list
  
  /*node *ptr = list;
  while (ptr != NULL)
  {
    printf("%i\n", ptr->number);
    ptr = ptr->next;
  }*/

  for (node *ptr = list; ptr != NULL; ptr = ptr->next)
  {
    printf("%i\n", ptr->number);
  }

  return 0;
}