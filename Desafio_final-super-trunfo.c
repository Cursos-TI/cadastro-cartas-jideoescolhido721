#include <stdio.h>
#include <string.h>

#define NUM_ATRIBUTOS 4

typedef struct {
    char nome[50];
    int populacao;
    int area;
    int densidade;
    int pib;
} Carta;

void exibirAtributosDisponiveis(int escolhido) {
    printf("Escolha um atributo:\n");
    if (escolhido != 1) printf("1 - Populacao\n");
    if (escolhido != 2) printf("2 - Area\n");
    if (escolhido != 3) printf("3 - Densidade Demografica\n");
    if (escolhido != 4) printf("4 - PIB\n");
}

int obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.densidade;
        case 4: return c.pib;
        default: return -1;
    }
}

int compararAtributo(int valor1, int valor2, int atributo) {
    return (atributo == 3) ? (valor1 < valor2 ? 1 : (valor1 > valor2 ? 2 : 0)) :
                             (valor1 > valor2 ? 1 : (valor1 < valor2 ? 2 : 0));
}

int main() {
    Carta carta1 = {"Brasil", 213000000, 8516000, 25, 2200};
    Carta carta2 = {"Japao", 125800000, 377975, 347, 5000};

    int atributo1, atributo2;

    printf("Comparacao entre %s e %s\n\n", carta1.nome, carta2.nome);

    // Escolha do primeiro atributo
    exibirAtributosDisponiveis(0);
    scanf("%d", &atributo1);

    // Escolha do segundo atributo
    do {
        exibirAtributosDisponiveis(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 == atributo1) {
            printf("Voce ja escolheu esse atributo. Escolha outro.\n");
        }
    } while (atributo2 == atributo1);

    // Obter valores
    int valor1_attr1 = obterValorAtributo(carta1, atributo1);
    int valor2_attr1 = obterValorAtributo(carta2, atributo1);
    int valor1_attr2 = obterValorAtributo(carta1, atributo2);
    int valor2_attr2 = obterValorAtributo(carta2, atributo2);

    // Comparacoes individuais
    int resultado1 = compararAtributo(valor1_attr1, valor2_attr1, atributo1);
    int resultado2 = compararAtributo(valor1_attr2, valor2_attr2, atributo2);

    // Soma dos atributos
    int soma1 = valor1_attr1 + valor1_attr2;
    int soma2 = valor2_attr1 + valor2_attr2;

    // Resultado final
    printf("\nResultado da comparacao:\n");
    printf("%s - %s: %d, %s: %d | Soma: %d\n", carta1.nome,
           atributo1 == 1 ? "Populacao" : atributo1 == 2 ? "Area" : atributo1 == 3 ? "Densidade" : "PIB",
           valor1_attr1,
           atributo2 == 1 ? "Populacao" : atributo2 == 2 ? "Area" : atributo2 == 3 ? "Densidade" : "PIB",
           valor1_attr2,
           soma1);

    printf("%s - %s: %d, %s: %d | Soma: %d\n", carta2.nome,
           atributo1 == 1 ? "Populacao" : atributo1 == 2 ? "Area" : atributo1 == 3 ? "Densidade" : "PIB",
           valor2_attr1,
           atributo2 == 1 ? "Populacao" : atributo2 == 2 ? "Area" : atributo2 == 3 ? "Densidade" : "PIB",
           valor2_attr2,
           soma2);

    if (soma1 > soma2)
        printf("\n%s venceu a rodada!\n", carta1.nome);
    else if (soma2 > soma1)
        printf("\n%s venceu a rodada!\n", carta2.nome);
    else
        printf("\nEmpate!\n");

    return 0;
}
