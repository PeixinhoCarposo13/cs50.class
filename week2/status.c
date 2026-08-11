#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Missing command-line argument\n");
    return 1;
  }
  else
  {
    printf("Hello, %s!\n", argv[1]);
  }

  return 0;
}

// .\'greet.exe' henry sai a resposta no command.