/*
In a file called mario.c in a folder called mario-less, implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:

       #
      ##
     ###
    ####
   #####
  ######
 #######
########
But prompt the user for an int for the pyramid’s actual height, so that the program can also output shorter pyramids like the below:

  #
 ##
###
Re-prompt the user, again and again as needed, if their input is not greater than 0 or not an int altogether.

*/

#include <stdio.h>

int main(void)
{
  int height;

  // Prompt the user for the pyramid's height
  do
  {
    printf("Height: ");
    scanf("%d", &height);

    // For Loop to print the pyramid
    for (int i = 1; i <= height; i++)
    {
      // For Loop to print spaces
      for (int j = 0; j < height - i; j++)
      {
        printf(" ");
      }

      // For Loop to print hashes
      for (int k = 0; k < i; k++)
      {
        printf("#");
      }

      // Move to the next line
      printf("\n");
    }

  } while (height != 0);

  return 0;
}