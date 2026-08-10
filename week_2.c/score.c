#include <stdio.h>

float average(int scores[], int num_scores);

int main(void)
{
  const int NUM_SCORES = 3;

  int scores[NUM_SCORES];

  printf("Enter %d scores:\n", NUM_SCORES);
  for (int i = 0; i < NUM_SCORES; i++)
  {
    printf("Score %d: ", i + 1);
    scanf("%d", &scores[i]);
  }

  printf("Average: %.2f\n", average(scores, NUM_SCORES));

  return 0;
}

float average(int scores[], int num_scores)
{
  int sum = 0;
  for (int i = 0; i < num_scores; i++)
  {
    sum += scores[i];
  }
  return (float)sum / num_scores;
}