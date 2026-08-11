#include <stdio.h>

int main()
{
  int x;
  int y;

  printf(" What is the value of x? ");
  scanf("%d", &x);

  printf("What is the value of y? ");
  scanf("%d", &y);

  if (x > y)
  {
    printf("x is greater than y\n");
  }
  else if (y > x)
  {
    printf("y is greater than x\n");
  }
  else
  {
    printf("x is equal to y\n");
  }

  return 0;
}