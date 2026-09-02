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

  int validKey;

  do
  {
    validKey = 1;

    printf("Enter the key (26 unique letters): ");

    fgets(usKey, sizeof(usKey), stdin);

    usKey[strcspn(usKey, "\n")] = '\0';

    // Check if the key has exactly 26 characters
    if (strlen(usKey) != 26)
    {
      validKey = 0;
      continue;
    }

    // Check if every character is a letter
    for (int i = 0; i < 26; i++)
    {
      if (!isalpha(usKey[i]))
      {
        validKey = 0;
        break;
      }
    }

    // Check if every letter is unique
    for (int i = 0; i < 26 && validKey; i++)
    {
      for (int j = i + 1; j < 26; j++)
      {
        if (toupper(usKey[i]) == toupper(usKey[j]))
        {
          validKey = 0;
          break;
        }
      }
    }

  } while (!validKey);

  printf("Enter the plaintext: ");

  fgets(plaintext, sizeof(plaintext), stdin);

  int size = strlen(plaintext);

  for (int j = 0; j < size; j++)
  {
    // Keep non-alphabet characters unchanged
    if (!isalpha(plaintext[j]))
    {
      ciphertext[j] = plaintext[j];
    }

    else
    {
      for (int k = 0; k < 26; k++)
      {
        if (toupper(plaintext[j]) == alphabet[k])
        {
          // Keep uppercase letters uppercase
          if (isupper(plaintext[j]))
          {
            ciphertext[j] = toupper(usKey[k]);
          }

          // Keep lowercase letters lowercase
          else
          {
            ciphertext[j] = tolower(usKey[k]);
          }

          break;
        }
      }
    }
  }

  ciphertext[size] = '\0';

  printf("ciphertext: %s", ciphertext);

  return 0;
}