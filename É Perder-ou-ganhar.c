#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int numeroJogador, numeroComputador, resultado;
    char tipoComparacao;

    // Gerar número aleatório
    srand(time(0));
    numeroComputador = rand() % 100 + 1; // número entre 1 e 100

    // Início do jogo
    printf("Bem-vindo ao jogo Maior, Menor ou Igual!\n");

    printf("Você deve escolher um número e o tipo de comparação.\n");

    printf("M. Maior\n");

    printf("N. Menor\n");

    printf("I. Igual\n");

    printf("Escolha a comparação: ");
    scanf(" %c", &tipoComparacao);
    printf("Escolha um número entre 1 e 100: ");
    scanf("%d", &numeroJogador);

    // Exibir numero do computador
    printf("Número do Computador: %d\n", numeroComputador);

    switch (tipodeComparacao)
    {
    case 'M':
        resultado = numeroJogador > numeroComputador ? 1 : 0;
        break;
    case 'N':
        resultado = numeroJogador < numeroComputador ? 1 : 0;
        break;
    case 'I':
        resultado = numeroJogador == numeroComputador ? 1 : 0;
        break;
    default:
        printf("Opção inválida!\n");
        break;
    }
    if (resultado == 1)
    {
        printf("Parabéns! Você ganhou!\n");
    }
    else
    {
        printf("Que pena! Você perdeu!\n");
    }
    return 0;
   