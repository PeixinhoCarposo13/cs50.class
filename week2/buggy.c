#include <stdio.h>

void printColumn(int height);

int main(void)
{
  int height;
  printf("Height: ");
  scanf("%d", &height);

  printColumn(height);

  return 0;
}

void printColumn(int height)
{
  for (int i = 0; i < height; i++)
  {
    printf("#\n");
  }
}