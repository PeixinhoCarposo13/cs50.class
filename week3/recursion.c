#include <stdio.h>
#include <string.h>

/*
When a function calls itself, it is called recursion. Recursion is a programming technique where a function solves a problem by breaking it down
into smaller subproblems of the same type. A recursive function typically has two main components: the base case and the recursive case.
The base case is the condition under which the recursion stops, while the recursive case is where the function calls itself with modified
arguments to work towards the base case.
*/

int factorial(int n)
{
  if (n == 0) // base case
  {
    return 1;
  }
  else
  {
    return n * factorial(n - 1); // recursive case
  }
}

void pyramidPrint(int n)
{
  if (n <= 0) // base case
  {
    return;
  }
  else
  {
    printf("\n");
    for (int i = 0; i < n; i++)
    {
      printf("*");
    }
    pyramidPrint(n - 1); // recursive case
  }
}

int main(void)
{

  pyramidPrint(5);
  printf("Factorial of 5 is: %d\n", factorial(5));

  return 0;
}