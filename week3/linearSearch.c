#include <stdio.h>
#include <string.h>

int main(void)
{
  // linear search
  printf("==========Linear Search==========\n");
  int intArr[] = {1, 2, 3, 4, 5};                                    // here i have an array of integers
  char *strArray[] = {"apple", "banana", "cherry", "date", "berry"}; // here i have an array of strings

  int size = sizeof(intArr) / sizeof(intArr[0]);
  int sizeStr = sizeof(strArray) / sizeof(strArray[0]);

  int target = 3;
  int i;

  for (i = 0; i < size; i++)
  {
    if (intArr[i] == target)
    {
      printf("Element found at intArr[%d]\n", i);
      break;
    }
  }

  if (i == size)
  {
    printf("Element not found\n");
  }

  // linear search for strings
  printf("==========Linear Search (Strings)==========\n");
  char *targetStr = "cherry";

  for (i = 0; i < sizeStr; i++)
  {
    if (strcmp(strArray[i], targetStr) == 0) // using strcmp to compare strings, if the result is 0, it means the strings are equal
    {
      printf("Element found at strArray[%d]\n", i);
      break;
    }
  }

  if (i == sizeStr)
  {
    printf("Element not found\n");
  }

  return 0;
}