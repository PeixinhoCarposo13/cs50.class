// Ao digitar " ctrl + C " você interrompe a execução de um programa no Terminal.

// Função que imprime " MEAW " na tela.
void meaw(int n);

// Função para verificar se um número é válido
int check_positive_number(void);

#include <stdio.h>

int main()
{
  int times;

  times = check_positive_number();
  meaw(times);

  return 0;
}

int check_positive_number(void)
{
  int n;

  do
  {
    printf("How many times the cat will MEAW?");
    scanf("%d", &n);
  } while (n < 0);

  return n;
}

void meaw(int n)
{
  for (int i = 0; i < n; i++)
  {
    printf(" MEAW\n");
  }
}