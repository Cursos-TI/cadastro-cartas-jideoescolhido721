#include <stdio.h>
#include <string.h>

/*
 * Projeto: Batalha de Cartas no Super Trunfo
 * Autor: [Seu Nome]Leandro Messias Magalhães
 * Data: 30/09/2025
 * Descrição: Simulação de confronto entre duas cartas
 *            com atributos de estados brasileiros.
 */
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    char codigo[10];
    char cidade[30];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} CartaSuperTrunfo;

void calcular_atributos(CartaSuperTrunfo *carta)
{
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = (carta->pib * 1000000000) / carta->populacao;
    carta->super_poder = carta->populacao + carta->area + carta->pib + carta->pontos_turisticos + carta->pib_per_capita + (1.0f / carta->densidade_populacional);
}

void comparar_e_exibir(const CartaSuperTrunfo *c1, const CartaSuperTrunfo *c2)
{
    printf("\n===== O Desafio Final =====\n");
    printf("População: %d\n", c1->populacao > c2->populacao);
    printf("Área: %d\n", c1->area > c2->area);
    printf("PIB: %d\n", c1->pib > c2->pib);
    printf("Pontos Turísticos: %d\n", c1->pontos_turisticos > c2->pontos_turisticos);
    printf("PIB per Capita: %d\n", c1->pib_per_capita > c2->pib_per_capita);
    printf("Densidade Populacional: %d\n", c1->densidade_populacional < c2->densidade_populacional);
    printf("Super Poder: %d\n", c1->super_poder > c2->super_poder);
}

int main()
{
    CartaSuperTrunfo carta1 = {
        "Espirito Santo", "E03", "Vitoria", 322869UL, 97123.0f, 31.42f, 15};
    CartaSuperTrunfo carta2 = {
        "Ceará", "C02", "Fortaleza", 2578483UL, 148825.6f, 73.42f, 11};

    calcular_atributos(&carta1);
    calcular_atributos(&carta2);

    printf("\n==============================\n");
    printf("        CARTA 1\n");
    printf("==============================\n");
    printf("Estado: %s\n", carta1.nome);
    printf("Código da carta: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.cidade);
    printf("População: %lu\n", carta1.populacao);
    printf("Área: %.1f km²\n", carta1.area);
    printf("PIB: R$%.2f bilhões\n", carta1.pib);
    printf("Nº de pontos turísticos: %d\n", carta1.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidade_populacional);
    printf("PIB per Capita: R$%.2f\n", carta1.pib_per_capita);
    printf("Super Poder: %.2f\n", carta1.super_poder);

    printf("\n==============================\n");
    printf("        CARTA 2\n");
    printf("==============================\n");
    printf("Estado: %s\n", carta2.nome);
    printf("Código da carta: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.cidade);
    printf("População: %lu\n", carta2.populacao);
    printf("Área: %.1f km²\n", carta2.area);
    printf("PIB: R$%.2f bilhões\n", carta2.pib);
    printf("Nº de pontos turísticos: %d\n", carta2.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidade_populacional);
    printf("PIB per Capita: R$%.2f\n", carta2.pib_per_capita);
    printf("Super Poder: %.2f\n", carta2.super_poder);

    comparar_e_exibir(&carta1, &carta2);
    return 0;
}
