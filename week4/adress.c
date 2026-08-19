#include <stdio.h>

int main(void)
{
  int n = 50;
  int *pointer = &n;

  printf("%i\n", *pointer);

  return 0;
}