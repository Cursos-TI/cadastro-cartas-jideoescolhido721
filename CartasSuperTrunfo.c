#include <stdio.h>
typedef struct {
    char nome[30];             // Nome do Estado
    char codigo[4];            // Código da carta
    char cidade[20];           // Nome da cidade (Vitória)
    int populacao;             // População da cidade
    float area;                // Área em km²
    float pib;                 // PIB em bilhões de reais
    int pontos_turisticos;     // Número de pontos turísticos
} CartaSuperTrunfo;

int main() {
    CartaSuperTrunfo carta1;

    // Preenchendo os campos da carta
    snprintf(carta1.nome, sizeof(carta1.nome), "Espirito Santo");
    snprintf(carta1.codigo, sizeof(carta1.codigo), "E03");
    snprintf(carta1.cidade, sizeof(carta1.cidade), "Vitoria");
    carta1.populacao = 322869;
    carta1.area = 97123.0f; // 97.123 km² (corrigido para o valor total do estado)
    carta1.pib = 31.420f;   // PIB em bilhões de reais
    carta1.pontos_turisticos = 15;

    // Exibindo a carta
    printf("Estado: %s\n", carta1.nome);
    printf("Código da carta: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.cidade);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.3f km²\n", carta1.area);
    printf("PIB: R$%.3f bilhões\n", carta1.pib);
    printf("Nº de pontos turísticos: %d\n", carta1.pontos_turisticos);

    return 0;
}

