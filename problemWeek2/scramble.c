/*
No jogo Scrabble , os jogadores formam palavras para marcar pontos, e a pontuação total é a soma dos valores de cada letra na palavra.

UM B C D E F G H EU J K L M N O P Q R S T U V C X Y Z
1	3	3	2	1	4	2	4	1	8	5	1	3	1	1	3	10	1	1	1	1	4	4	8	4	10

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void uppercase(char palavra[], int tamanhoPalavra);

int main(void){
    char palavra[50];
    int soma = 0;

    char caracteres[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int pontos[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    printf("Insira uma palavra: ");
    scanf("%49s", palavra);

    int tamanhoPalavra = strlen(palavra);

    uppercase(palavra, tamanhoPalavra);

    for (int i = 0; i < tamanhoPalavra; i++)
    {
        for(int j = 0; j < 26; j++){
            if(palavra[i] == caracteres[j]){
                soma += pontos[j];
            }
        }
    }

    printf("%d", soma);

    return 0;
}

void uppercase(char palavra[], int tamanhoPalavra){
    for (int t = 0; t < tamanhoPalavra; t++)
    {
        palavra[t] = toupper(palavra[t]);
    }
}