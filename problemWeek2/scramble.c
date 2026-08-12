/*
No jogo Scrabble , os jogadores formam palavras para marcar pontos, e a pontuação total é a soma dos valores de cada letra na palavra.

UM B C D E F G H EU J K L M N O P Q R S T U V C X Y Z
1	3	3	2	1	4	2	4	1	8	5	1	3	1	1	3	10	1	1	1	1	4	4	8	4	10

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void uppercase(char palavra[], int tamanhoPalavra);

int main(void)
{
    int soma[2] = {0, 0};
    char palavraJogador[2][50];

    char caracteres[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int pontos[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    while (1)
    {
        int opcao;

        printf("Digite 1 para jogar ou 0 para sair: ");
        scanf("%d", &opcao);

        if (opcao == 0)
        {
            break;
        }

        if (opcao != 1)
        {
            printf("Opcao invalida. Tente novamente.\n");
            continue;
        }

        if (opcao == 1)
        {
            // Zera a pontuação para uma nova partida
            soma[0] = 0;
            soma[1] = 0;

            // Primeiro os dois jogadores digitam as palavras
            for (int i = 0; i < 2; i++)
            {
                printf("Jogador %d, insira sua palavra: ", i + 1);
                scanf("%49s", palavraJogador[i]);
            }

            // Depois calcula os pontos das duas palavras
            for (int j = 0; j < 2; j++)
            {
                int tamanhoPalavra = strlen(palavraJogador[j]);

                uppercase(palavraJogador[j], tamanhoPalavra);

                for (int k = 0; k < tamanhoPalavra; k++)
                {
                    for (int l = 0; l < 26; l++)
                    {
                        if (palavraJogador[j][k] == caracteres[l])
                        {
                            soma[j] += pontos[l];
                        }
                    }
                }
            }

            // Mostra a pontuação dos dois jogadores
            for (int j = 0; j < 2; j++)
            {
                printf("Jogador %d: %d pontos\n", j + 1, soma[j]);
            }

            // Determina o vencedor
            if (soma[0] > soma[1])
            {
                printf("Jogador 1 venceu!\n");
            }
            else if (soma[0] < soma[1])
            {
                printf("Jogador 2 venceu!\n");
            }
            else
            {
                printf("Empate!\n");
            }
        }
    }

    return 0;
}

void uppercase(char palavra[], int tamanhoPalavra)
{
    for (int t = 0; t < tamanhoPalavra; t++)
    {
        palavra[t] = toupper(palavra[t]);
    }
}