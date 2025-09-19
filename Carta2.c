#include <stdio.h>

typedef struct {
    char nome[50];
    char codigo[10];
    char cidade[30];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} CartaSuperTrunfo;

int main() {
    CartaSuperTrunfo carta2;
    snprintf(carta2.nome, sizeof(carta2.nome), "Ceará");
    snprintf(carta2.codigo, sizeof(carta2.codigo), "C02");
    snprintf(carta2.cidade, sizeof(carta2.cidade), "Fortaleza");
    carta2.populacao = 2578483;
    carta2.area = 148825.6f;
    carta2.pib = 73.42f;
    carta2.pontos_turisticos = 11;

    printf("\n==============================\n");
    printf("        CARTA 2\n");
    printf("==============================\n");
    printf("Estado: %s\n", carta2.nome);
    printf("Código da carta: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.cidade);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.1f km²\n", carta2.area);
    printf("PIB: R$%.2f bilhões\n", carta2.pib);
    printf("Nº de pontos turísticos: %d\n", carta2.pontos_turisticos);
    printf("==============================\n");
    return 0;
}
