#include <stdio.h>
#include <string.h>

int main(void)
{
  // Selection Sort
  printf("==========Selection Sort==========\n");
  int intArr[] = {64, 25, 12, 22, 11, 90, 45, 78, 34, 56};
  int size = sizeof(intArr) / sizeof(intArr[0]);
  int iterations = 0, passing = 0, swaps = 0;

  for (int i = 0; i < size - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < size; j++)
    {
      if (intArr[j] < intArr[minIndex])
      {
        minIndex = j;
      }
      passing++;
    }
    // Swap the found minimum element with the first element
    int temp = intArr[minIndex];
    intArr[minIndex] = intArr[i];
    intArr[i] = temp;
    iterations++;
    swaps++;
  }

  // Print the sorted array
  for (int i = 0; i < size; i++)
  {
    printf("%d ", intArr[i]);
  }
  printf("\nNumber of iterations: %d\n", iterations);
  printf("Number of passings: %d\n", passing);
  printf("Number of swaps: %d\n", swaps);
  printf("\n");

  printf("==========Bubble Sort==========\n");
  int intArr2[] = {64, 25, 12, 22, 11, 90, 45, 78, 34, 56};
  int size2 = sizeof(intArr2) / sizeof(intArr2[0]);
  int swaps2 = 0, passing2 = 0, iterations2 = 0;

  for (int i = 0; i < size2 - 1; i++)
  {
    for (int j = 0; j < size2 - i - 1; j++)
    {
      if (intArr2[j] > intArr2[j + 1])
      {
        // Swap the elements
        int temp = intArr2[j];
        intArr2[j] = intArr2[j + 1];
        intArr2[j + 1] = temp;
        swaps2++;
      }
      passing2++;
    }
    iterations2++;
  }

  // Print the sorted array
  for (int i = 0; i < size2; i++)
  {
    printf("%d ", intArr2[i]);
  }
  printf("\nNumber of swaps: %d\n", swaps2);
  printf("Number of iterations: %d\n", iterations2);
  printf("Number of passings: %d\n", passing2);
  printf("\n");

  return 0;
}