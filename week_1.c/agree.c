#include <stdio.h>

int main()
{
  char answear[50];

  printf("Do you agree? ");
  scanf("%s", answear);

  if (answear == "yes" || answear == "YES")
  {
    printf("You agreed!\n");
  }
  else if (answear == "no" || answear == "NO")
  {
    printf("You disagreed!\n");
  }
  else
  {
    printf("Invalid response!\n");
  }

  return 0;
}