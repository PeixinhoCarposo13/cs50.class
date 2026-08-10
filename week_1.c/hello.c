// Ao digitar "code + nome do arquivo" no Terminal você cria um novo arquivo.
// Ao digitar "make + nome do arquivo" no Terminal você compila o arquivo.
// Ao digitar "gcc -o hello hello.c" no Terminal você compila o arquivo hello.c e cria o executável hello.
// Ao digitar "./ + nome do arquivo compilado" no Terminal você executa o arquivo.
// Ao digitar "ls" no Terminal você lista os arquivos da pasta atual.
// Ao digitar "clear" no Terminal você limpa a tela do Terminal.
// Use ctrl + S para salvar o arquivo no editor de código VS Code.
// Ao digitar "\n" você pula uma linha no código.
// Ao digitar "\r" você retorna ao início da linha no código.
// Para utilizar aspas duplas dentro de aspas duplas, use a barra invertida antes das aspas: \"texto\".
// Ao digitar "cd + local onde deseja ir" no Terminal você navega entre pastas.
// Ao digitar "cpy + nome do arquivo + novo local do arquivo" no Terminal você copia o arquivo.
// Ao digitar "mkdir + nome da pasta" no Terminal você cria uma nova pasta.
// Ao digitar "mv + nome do arquivo + novo local ou novo nome do arquivo" no Terminal você move ou renomeia o arquivo.
// Ao digitar "rm + nome do arquivo" no Terminal você remove o arquivo.
// Ao digitar "rmdir + nome da pasta" no Terminal você remove a pasta.
// Ao colocar " .. " apos mv ou cd você volta uma pasta na hierarquia de pastas.

#include <stdio.h>

int main()
{
  char name[50];

  printf("Hello, World!\n");
  printf(" Wat is your name? ");
  scanf("%s", name);

  return 0;
}