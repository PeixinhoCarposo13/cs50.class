/*
Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.

In a file called mario.c in a folder called mario-more, implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:

   #  #
  ##  ##
 ###  ###
####  ####
And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive int between, say, 1 and 8, inclusive.

*/
#include <stdio.h>

int main(void)
{
  int height;

  do
  {
    // Here will request the height for the pyramid
    printf("What is the height of the pyramid (between 1 and 8): ");
    scanf("%d", &height);

    // Here will print the pyramid based on the height provided by the user
    for (int i = 1; i <= height; i++)
    {
      // Here will print the spaces before the left blocks
      for (int j = 0; j < height - i; j++)
      {
        printf(" ");
      }

      // Here will print the blocks of the left pyramid
      for (int j = 0; j < i; j++)
      {
        printf("#");
      }

      // Here will print the spaces between the two pyramids
      printf("  ");

      // Here will print the blocks of the right pyramid
      for (int j = 0; j < i; j++)
      {
        printf("#");
      }

      // Here will move to the next line
      printf("\n");
    }
  } while (height != 0 && height >= 1 && height <= 8);

  return 0;
}