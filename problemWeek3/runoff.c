/*
Vou desenvolver um programa que vai realizar a eleição de tres candidatos,
o usuario vai ter que rankear de 1 a 3 os candidatos, sendo 1 o mais votado e 3 o menos votado.
Caso um candidato tenha mais de 50% dos primeiros votos, ele será declarado o vencedor. Caso contrário, os dois candidatos com mais votos irão para um segundo turno.
*/

#include <stdio.h>

int main(void)
{
    char listaDeCandidatos[3][50] = {"Carlos", "Alice", "Douglas"};
    int votosPrimeiro[3] = {0, 0, 0};
    int votosSegundo[3] = {0, 0, 0};
    int votosTerceiro[3] = {0, 0, 0};

    // Solicitar numero de pessoas que vão votar
    int numeroDeEleitores;
    int votoPrimeiro, votoSegundo, votoTerceiro;

    printf("Digite o numero de eleitores: ");
    scanf("%d", &numeroDeEleitores);

    // Solicitar votos dos eleitores
    for (int i = 0; i < numeroDeEleitores; i++)
    {
        // Vou printar os candidatos para o eleitor escolher
        printf("\nCandidatos:\n");

        for (int j = 0; j < 3; j++)
        {
            printf("%d - %s\n", j + 1, listaDeCandidatos[j]);
        }

        // Voto primeiro Lugar
        printf("Eleitor %d, escolha o candidato para o primeiro lugar (1 a 3): ", i + 1);
        scanf("%d", &votoPrimeiro);

        if (votoPrimeiro < 1 || votoPrimeiro > 3)
        {
            printf("Voto invalido. Por favor, digite um numero entre 1 e 3.\n");
            i--; // Decrementa para repetir a votação do mesmo eleitor
            continue;
        }

        // Voto segundo Lugar
        printf("Eleitor %d, escolha o candidato para o segundo lugar (1 a 3): ", i + 1);
        scanf("%d", &votoSegundo);

        if (votoSegundo < 1 || votoSegundo > 3)
        {
            printf("Voto invalido. Por favor, digite um numero entre 1 e 3.\n");
            i--; // Decrementa para repetir a votação do mesmo eleitor
            continue;
        }

        if (votoSegundo == votoPrimeiro)
        {
            printf("Voto invalido. O candidato ja foi escolhido como primeiro lugar.\n");
            i--; // Decrementa para repetir a votação do mesmo eleitor
            continue;
        }

        // Voto terceiro Lugar
        printf("Eleitor %d, escolha o candidato para o terceiro lugar (1 a 3): ", i + 1);
        scanf("%d", &votoTerceiro);

        if (votoTerceiro < 1 || votoTerceiro > 3)
        {
            printf("Voto invalido. Por favor, digite um numero entre 1 e 3.\n");
            i--; // Decrementa para repetir a votação do mesmo eleitor
            continue;
        }

        if (votoTerceiro == votoPrimeiro)
        {
            printf("Voto invalido. O candidato ja foi escolhido como primeiro lugar.\n");
            i--; // Decrementa para repetir a votação do mesmo eleitor
            continue;
        }
        else if (votoTerceiro == votoSegundo)
        {
            printf("Voto invalido. O candidato ja foi escolhido como segundo lugar.\n");
            i--; // Decrementa para repetir a votação do mesmo eleitor
            continue;
        }

        // Contabilizar os votos somente depois que todos forem validados
        votosPrimeiro[votoPrimeiro - 1]++;
        votosSegundo[votoSegundo - 1]++;
        votosTerceiro[votoTerceiro - 1]++;
    }

    // Exibir resultados
    printf("\nResultados:\n");

    for (int j = 0; j < 3; j++)
    {
        printf(
            "Candidato %s recebeu %d votos de primeiro lugar, %d votos de segundo lugar e %d votos de terceiro lugar.\n", listaDeCandidatos[j], votosPrimeiro[j], votosSegundo[j], votosTerceiro[j]);
    }

    // Verificar se algum candidato tem mais de 50% dos votos de primeiro lugar
    int totalVotosPrimeiro = votosPrimeiro[0] + votosPrimeiro[1] + votosPrimeiro[2];
    for (int k = 0; k < 3; k++)
    {
        if (votosPrimeiro[k] > totalVotosPrimeiro / 2)
        {
            printf("\nO candidato %s venceu a eleição com mais de 50%% dos votos de primeiro lugar!\n", listaDeCandidatos[k]);
            return 0;
        }
    }

    // Encontrar candidato com menos votos
    int eliminado = 0;

    for (int i = 1; i < 3; i++)
    {
        // Comparar votos de primeiro lugar
        if (votosPrimeiro[i] < votosPrimeiro[eliminado])
        {
            eliminado = i;
        }
        else if (votosPrimeiro[i] == votosPrimeiro[eliminado])
        {
            // Desempate pelos votos de segundo lugar
            if (votosSegundo[i] < votosSegundo[eliminado])
            {
                eliminado = i;
            }
            else if (votosSegundo[i] == votosSegundo[eliminado])
            {
                // Desempate pelos votos de terceiro lugar ( nesse caso quem tem mais votos de terciro lugar é eliminado )
                if (votosTerceiro[i] > votosTerceiro[eliminado])
                {
                    eliminado = i;
                }
            }
        }
    }

    printf("Candidato eliminado: %s\n", listaDeCandidatos[eliminado]);

    int candidatosSegundoTurno[2];
    int posicao = 0;

    for (int i = 0; i < 3; i++)
    {
        if (i != eliminado)
        {
            candidatosSegundoTurno[posicao] = i;
            posicao++;
        }
    }

    printf("\nCandidatos do segundo turno:\n");

    printf("1 - %s\n", listaDeCandidatos[candidatosSegundoTurno[0]]);
    printf("2 - %s\n", listaDeCandidatos[candidatosSegundoTurno[1]]);

    // Solicitar votos do segundo turno
    int votosSegundoTurno[2] = {0, 0};
    int votoSegundoTurno;

    for (int i = 0; i < numeroDeEleitores; i++)
    {
        printf("\nEleitor %d, escolha seu candidato (1 ou 2): ", i + 1);
        scanf("%d", &votoSegundoTurno);

        if (votoSegundoTurno == 1)
        {
            votosSegundoTurno[0]++;
        }
        else if (votoSegundoTurno == 2)
        {
            votosSegundoTurno[1]++;
        }
        else
        {
            printf("Voto invalido. Digite 1 ou 2.\n");
            i--; // Decrementa para repetir a votação do mesmo eleitor
            continue;
        }
    }

    // Exibir resultado do segundo turno
    printf("\nResultados do segundo turno:\n");

    printf(
        "%s recebeu %d votos.\n", listaDeCandidatos[candidatosSegundoTurno[0]], votosSegundoTurno[0]);

    printf(
        "%s recebeu %d votos.\n",
        listaDeCandidatos[candidatosSegundoTurno[1]],
        votosSegundoTurno[1]);

    // Verificar vencedor do segundo turno
    if (votosSegundoTurno[0] > votosSegundoTurno[1])
    {
        printf(
            "\nO vencedor da eleicao foi %s!\n", listaDeCandidatos[candidatosSegundoTurno[0]]);
    }
    else if (votosSegundoTurno[1] > votosSegundoTurno[0])
    {
        printf(
            "\nO vencedor da eleicao foi %s!\n", listaDeCandidatos[candidatosSegundoTurno[1]]);
    }
    else
    {
        printf("\nO segundo turno terminou empatado.\n");
    }

    return 0;
}