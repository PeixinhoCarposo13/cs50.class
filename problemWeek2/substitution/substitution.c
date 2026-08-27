/*
In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing every letter with another letter.
 To do so, we use a key: in this case, a mapping of each of the letters of the alphabet to the letter it should correspond to when
 we encrypt it. To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse the
 process: translating the encrypt text (generally called ciphertext) back into the original message (generally called plaintext).

A key, for example, might be the string NQXPOMAFTRHLZGECYJIUWSKDVB. This 26-character key means that A (the first letter of the alphabet)
4should be converted into N (the first character of the key), B (the second letter of the alphabet) should be converted into Q (the second
character of the key), and so forth.

A message like HELLO, then, would be encrypted as FOLLE, replacing each of the letters according to the mapping determined by the key.

In a file called substitution.c in a folder called substitution, create a program that enables you to encrypt messages using a
substitution cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what
the key should be in the secret message they’ll provide at runtime.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                       'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  char usKey[28]; // 26 letters + newline + null terminator
  char plaintext[1000];
  char ciphertext[1000];

  do
  {
    printf("Enter the key (26 unique letters): ");
    fgets(usKey, sizeof(usKey), stdin);
    usKey[strcspn(usKey, "\n")] = '\0';

  } while (strlen(usKey) != 26);

  printf("Enter the plaintext: ");
  fgets(plaintext, sizeof(plaintext), stdin);

  for (int i = 0; i < strlen(plaintext); i++)
  {
    plaintext[i] = toupper(plaintext[i]); // Convert to uppercase for consistency
  }

  for (int j = 0; j < strlen(plaintext); j++)
  {
    for (int k = 0; k < 26; k++)
    {
      if (plaintext[j] == alphabet[k])
      {
        ciphertext[j] = usKey[k];
        break;
      }
      else
      {
        ciphertext[j] = plaintext[j]; // Keep non-alphabet characters unchanged
      }
    }
  }

  for (int m = 0; m < strlen(plaintext); m++)
  {
    printf("%c", ciphertext[m]);
  }
  printf("\n");
  for (int n = 0; n < strlen(plaintext); n++)
  {
    printf("%c", plaintext[n]);
  }

  return 0;
}