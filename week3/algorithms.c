#include <stdio.h>

int main(void)
{
  // linear search
  printf("==========Linear Search==========\n");
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 3;
  int i;

  for (i = 0; i < size; i++)
  {
    if (arr[i] == target)
    {
      printf("Element found at arr[%d]\n", i);
      break;
    }
  }

  if (i == size)
  {
    printf("Element not found\n");
  }

  return 0;
}