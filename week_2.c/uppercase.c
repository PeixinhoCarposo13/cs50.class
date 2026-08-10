#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  char str[100];

  printf("Enter a string: ");
  scanf("%s", str);

  int length = strlen(str);

  for (int i = 0; i < length; i++)
  {
    str[i] = toupper(str[i]);
  }

  printf("Uppercase of string: %s\n", str);

  return 0;
}