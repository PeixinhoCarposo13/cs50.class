#include <stdio.h>
#include <string.h>

int main(void)
{
  char str[100];

  printf("Enter a string: ");
  scanf("%s", str);

  int length = strlen(str);

  printf("Length of string: %d\n", length);

  return 0;
}