#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int resultado1, resultado2;
    char primeiroAtributo, segundoAtributo;
    int ataque1, ataque2, defesa1, defesa2, recuo1, recuo2;
    int soma1, soma2;

    // Gerar número aleatório
    srand(time(0));
    ataque1 = rand() % 100 + 1;
    ataque2 = rand() % 100 + 1;
    defesa1 = rand() % 100 + 1;
    defesa2 = rand() % 100 + 1;
    recuo1  = rand() % 100 + 1;
    recuo2  = rand() % 100 + 1;

    printf("Bem-vindo ao jogo!\n");
    printf("Valores das cartas:\n");
    printf("Carta 1 - Ataque: %d | Defesa: %d | Recuo: %d\n", ataque1, defesa1, recuo1);
    printf("Carta 2 - Ataque: %d | Defesa: %d | Recuo: %d\n", ataque2, defesa2, recuo2);

    // Escolha do primeiro atributo
    do {
        printf("\nEscolha o primeiro Atributo:\n");
        printf("A - Ataque\nD - Defesa\nR - Recuo\n");
        printf("Digite sua escolha: ");
        scanf(" %c", &primeiroAtributo);
        primeiroAtributo = toupper(primeiroAtributo);
        if(primeiroAtributo != 'A' && primeiroAtributo != 'D' && primeiroAtributo != 'R')
            printf("Opção inválida!\n");
    } while(primeiroAtributo != 'A' && primeiroAtributo != 'D' && primeiroAtributo != 'R');

    // Escolha do segundo atributo - dinâmico!
    do {
        printf("\nEscolha o segundo Atributo (diferente do primeiro):\n");
        if(primeiroAtributo != 'A') printf("A - Ataque\n");
        if(primeiroAtributo != 'D') printf("D - Defesa\n");
        if(primeiroAtributo != 'R') printf("R - Recuo\n");
        printf("Digite sua escolha: ");
        scanf(" %c", &segundoAtributo);
        segundoAtributo = toupper(segundoAtributo);
        if(segundoAtributo == primeiroAtributo || 
           (segundoAtributo != 'A' && segundoAtributo != 'D' && segundoAtributo != 'R'))
            printf("Opção inválida ou repetida! Tente novamente.\n");
    } while(segundoAtributo == primeiroAtributo || 
            (segundoAtributo != 'A' && segundoAtributo != 'D' && segundoAtributo != 'R'));

    // Switch para comparar atributos, usando operador ternário
    switch(primeiroAtributo) {
        case 'A':
            resultado1 = (ataque1 > ataque2) ? 1 : (ataque1 < ataque2 ? 2 : 0);
            soma1 = ataque1;
            soma2 = ataque2;
            break;
        case 'D':
            resultado1 = (defesa1 > defesa2) ? 1 : (defesa1 < defesa2 ? 2 : 0);
            soma1 = defesa1;
            soma2 = defesa2;
            break;
        case 'R':
            // Exemplo: para recuo vence menor valor
            resultado1 = (recuo1 < recuo2) ? 1 : (recuo1 > recuo2 ? 2 : 0);
            soma1 = recuo1;
            soma2 = recuo2;
            break;
        default:
            printf("Erro inesperado!\n");
    }

    switch(segundoAtributo) {
        case 'A':
            resultado2 = (ataque1 > ataque2) ? 1 : (ataque1 < ataque2 ? 2 : 0);
            soma1 += ataque1;
            soma2 += ataque2;
            break;
        case 'D':
            resultado2 = (defesa1 > defesa2) ? 1 : (defesa1 < defesa2 ? 2 : 0);
            soma1 += defesa1;
            soma2 += defesa2;
            break;
        case 'R':
            resultado2 = (recuo1 < recuo2) ? 1 : (recuo1 > recuo2 ? 2 : 0);
            soma1 += recuo1;
            soma2 += recuo2;
            break;
        default:
            printf("Erro inesperado!\n");
    }

    // Exibição clara dos resultados
    printf("\nResultados das Comparações:\n");
    printf("Primeiro atributo (%c): Carta 1 = %d, Carta 2 = %d\n", primeiroAtributo,
            (primeiroAtributo=='A'?ataque1:(primeiroAtributo=='D'?defesa1:recuo1)),
            (primeiroAtributo=='A'?ataque2:(primeiroAtributo=='D'?defesa2:recuo2)));
    printf("Segundo atributo (%c): Carta 1 = %d, Carta 2 = %d\n", segundoAtributo,
            (segundoAtributo=='A'?ataque1:(segundoAtributo=='D'?defesa1:recuo1)),
            (segundoAtributo=='A'?ataque2:(segundoAtributo=='D'?defesa2:recuo2)));
    printf("Soma dos atributos: Carta 1 = %d, Carta 2 = %d\n", soma1, soma2);

    // Vencedor ou empate
    if(soma1 > soma2)
        printf("Carta 1 venceu!\n");
    else if(soma2 > soma1)
        printf("Carta 2 venceu!\n");
    else
        printf("Empate!\n");

    return 0;
}

