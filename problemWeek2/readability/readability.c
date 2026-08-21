/*
According to Scholastic, E.B. White’s Charlotte’s Web is between a second- and fourth-grade reading level, and Lois Lowry’s
The Giver is between an eighth- and twelfth-grade reading level. What does it mean, though, for a book to be at a particular
reading level?

Well, in many cases, a human expert might read a book and make a decision on the grade (i.e., year in school) for which they
think the book is most appropriate. But an algorithm could likely figure that out too!

In a file called readability.c in a folder called readability, you’ll implement a program that calculates the approximate
grade level needed to comprehend some text. Your program should print as output “Grade X” where “X” is the grade level
computed, rounded to the nearest integer. If the grade level is 16 or higher (equivalent to or greater than a senior
undergraduate reading level), your program should output “Grade 16+” instead of giving the exact index number.
If the grade level is less than 1, your program should output “Before Grade 1”.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
  char text[1000];

  printf("Enter the text: ");
  fgets(text, sizeof(text), stdin);

  int length = strlen(text);
  int words = 0;
  int sentences = 0;

  for (int i = 0; i < length; i++)
  {

    if (text[i] != ' ' && (i == 0 || text[i - 1] == ' '))
    {
      words++;
    }
    if (text[i] == '.' || text[i] == '!' || text[i] == '?')
    {
      sentences++;
    }
  }

  float L = (float)words / length * 100;
  float S = (float)sentences / words * 100;
  float index = 0.0588 * L - 0.296 * S - 15.8;

  if (index < 1)
  {
    printf("Before Grade 1\n");
  }
  else if (index >= 16)
  {
    printf("Grade 16+\n");
  }
  else
  {
    printf("Grade %.0f\n", index);
  }

  printf("The text length is: %d\n", length);
  printf("The number of words is: %d\n", words);
  printf("The number of sentences is: %d\n", sentences);
}