#include <stdio.h>

int stringLenth(char str[]);

int main(void)
{
  char length[100];

  printf("Length of string: ");
  scanf("%s", length);

  printf("Length of string: %d\n", stringLenth(length));

  return 0;
}

int stringLenth(char str[])
{
  int length = 0;
  while (str[length] != '\0')
  {
    length++;
  }
  return length;
}