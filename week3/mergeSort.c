#include <stdio.h>
#include <string.h>

/*
Merge Sort is a divide-and-conquer algorithm that divides the input array into two halves,
recursively sorts them, and then merges the sorted halves back together.
The merge sort algorithm has a time complexity of O(n log n) and is stable,
meaning that it preserves the relative order of equal elements.
*/

int main(void)
{
  int arr[] = {38, 27, 43, 3, 9, 82, 10};
  int size = sizeof(arr) / sizeof(arr[0]);

  // Fisrt i need to separate the array into two halves, then i will sort them and finally merge them back together
  int mid = size / 2;
  int left[mid];
  int right[size - mid];

  // Copy elements to the left array
  for (int i = 0; i < mid; i++)
  {
    left[i] = arr[i];
  }

  // Copy elements to the right array
  for (int j = mid; j < size; j++)
  {
    right[j - mid] = arr[j];
  }

  return 0;
}