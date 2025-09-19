#include <stdio.h>

typedef struct {
    char nome[30];
    char codigo[4];
    char cidade[20];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} CartaSuperTrunfo;

int main() {
    CartaSuperTrunfo carta1;
    snprintf(carta1.nome, sizeof(carta1.nome), "Espirito Santo");
    snprintf(carta1.codigo, sizeof(carta1.codigo), "E03");
    snprintf(carta1.cidade, sizeof(carta1.cidade), "Vitoria");
    carta1.populacao = 322869;
    carta1.area = 97123.0f;
    carta1.pib = 31.42f;
    carta1.pontos_turisticos = 15;

    printf("\n==============================\n");
    printf("        CARTA 1\n");
    printf("==============================\n");
    printf("Estado: %s\n", carta1.nome);
    printf("Código da carta: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.cidade);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.1f km²\n", carta1.area);
    printf("PIB: R$%.2f bilhões\n", carta1.pib);
    printf("Nº de pontos turísticos: %d\n", carta1.pontos_turisticos);
    printf("==============================\n");
    return 0;
}
