#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa
typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float superPoder;
} Cidade;

int main() {
//variaveis que irao armazenar os dados pedidos
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
//entrada de dados
    puts("Digite o codigo da Cidade ex A01: ");
    scanf("%s", codigo);
    printf("Digite a populacao da Cidade\n");
    scanf("%d", &populacao);
    printf("Digite a area da Cidade\n");
    scanf("%f", &area);
    printf("Digite o PIB da Cidade\n");
    scanf("%f", &pib);
    printf("Digite o numero de pontos turisticos da Cidade\n");
    scanf("%d", &pontos_turisticos);
    //saida de dados com formatacao
    printf("Codigo da Cidade: %s\n", codigo);
    printf("Populacao da Cidade: %.3d\n", populacao);
    printf("Área: %.3f km²\n", area);
    printf("PIB da Cidade: %.2f\n", pib);
    printf("Pontos turisticos da Cidade: %d\n", pontos_turisticos);
    return 0;
}
