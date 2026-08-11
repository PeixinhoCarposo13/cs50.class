#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  if (argc == 2)
  {
    printf("Hello, %s!\n", argv[1]);
  }
  else
  {
    printf("Usage: %s <name>\n", argv[0]);
  }

  return 0;
}

// .\'greet.exe' henry sai a resposta no command.