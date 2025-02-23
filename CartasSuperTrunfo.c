#include <stdio.h>

// Definindo a estrutura para os dados da cidade
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

// Função para calcular o superPoder
float calcularSuperPoder(Cidade cidade) {
    return (cidade.populacao + cidade.area + cidade.pib + cidade.pontos_turisticos + cidade.densidade_populacional + cidade.pib_per_capita) / 6.0;
}

// Função para comparar os valores de superPoder de duas cidades
void comparar_cidades(Cidade cidade1, Cidade cidade2) {
    if (cidade1.superPoder > cidade2.superPoder) {
        printf("A cidade com o maior superPoder é: %s\n", cidade1.codigo);
    } else if (cidade1.superPoder < cidade2.superPoder) {
        printf("A cidade com o maior superPoder é: %s\n", cidade2.codigo);
    } else {
        printf("As cidades %s e %s têm o mesmo superPoder.\n", cidade1.codigo, cidade2.codigo);
    }
}

// Função para cadastrar os dados da cidade
void cadastrar_cidade(Cidade* cidade) {
    printf("Código da cidade (ex: A01): ");
    scanf("%s", cidade->codigo);
    printf("População: ");
    scanf("%d", &cidade->populacao);
    printf("Área (em km²): ");
    scanf("%f", &cidade->area);
    printf("PIB (em bilhões): ");
    scanf("%f", &cidade->pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);

    // Calcula as propriedades adicionais
    cidade->densidade_populacional = cidade->populacao / cidade->area;
    cidade->pib_per_capita = cidade->pib / cidade->populacao;
    cidade->superPoder = calcularSuperPoder(*cidade);
}

// Função para exibir os dados da cidade
void exibir_cidade(Cidade cidade) {
    printf("\nCódigo: %s\n", cidade.codigo);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões\n", cidade.pib);
    printf("Número de pontos turísticos: %d\n", cidade.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", cidade.densidade_populacional);
    printf("PIB per Capita: %.2f bilhões/hab\n", cidade.pib_per_capita);
    printf("Super Poder: %.2f\n", cidade.superPoder);
}

// Método principal que irá chamar as funções
int main() {
    Cidade cidades[32];  // Limite de 32 cidades
    int total_cidades = 0, opcao;

    do {
        printf("\n1. Cadastrar cidade\n");
        printf("2. Exibir cidades\n");
        printf("3. Comparar superPoder entre duas cidades\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total_cidades < 32) {
                    cadastrar_cidade(&cidades[total_cidades]);
                    total_cidades++;
                } else {
                    printf("Limite de cidades cadastradas atingido.\n");
                }
                break;
            case 2:
                for (int i = 0; i < total_cidades; i++) {
                    exibir_cidade(cidades[i]);
                }
                break;
            case 3:
                if (total_cidades >= 2) {
                    int cidade1, cidade2;
                    printf("Digite o índice da primeira cidade (0 a %d): ", total_cidades - 1);
                    scanf("%d", &cidade1);
                    printf("Digite o índice da segunda cidade (0 a %d): ", total_cidades - 1);
                    scanf("%d", &cidade2);
                    if (cidade1 >= 0 && cidade1 < total_cidades && cidade2 >= 0 && cidade2 < total_cidades) {
                        comparar_cidades(cidades[cidade1], cidades[cidade2]);
                    } else {
                        printf("Índices de cidades inválidos.\n");
                    }
                } else {
                    printf("É necessário cadastrar pelo menos 2 cidades para comparar.\n");
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}