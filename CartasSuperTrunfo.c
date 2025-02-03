#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa
//classe que ira armazenar a base de cada cidade
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

// Funcao para calcular o superPoder de cada cidade
float calcularSuperPoder(Cidade cidade) {
    return (cidade.populacao + cidade.area + cidade.pib + cidade.pontos_turisticos + cidade.densidade_populacional + cidade.pib_per_capita) / 6.0;
}
// funcao aonde os dados serao coletados para cada cidade
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
}

void exibirCidade(Cidade cidades){
    printf("\nCódigo: %s\n", cidades.codigo);
    printf("População: %d\n", cidades.populacao);
}


int main() {
//variaveis que irao armazenar os dados pedidos
    Cidade cidades[32]; // limitando o numero de cidades em 32 apenas
    int cidades_total = 0, opcao;
//entrada de dados
    do
    {
        printf("\n1. Cadastrar cidade\n");
        printf("2. Exibir cidades\n");
        printf("3. Comparar superPoder entre duas cidades\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1 :
            if (cidades < 32)
            {
                cadastrar_cidade(&cidades[cidades_total]);
                cidades_total++;
            }else{
                printf("Limite de 32 cidades foi atingido");
            }
            
            break;
        case 2:
            for ( int i = 0; i < cidades_total; i++)
            {
               exibirCidade(cidades[i]);
            }
            


        break;

        case 3:


        break;


        case 0 :


        break;
        
        default:
            break;
        }
        /* code */
    } while (opcao != 0);
    




    // puts("Digite o codigo da Cidade ex A01: ");
    // scanf("%s", codigo);
    // printf("Digite a populacao da Cidade\n");
    // scanf("%d", &populacao);
    // printf("Digite a area da Cidade\n");
    // scanf("%f", &area);
    // printf("Digite o PIB da Cidade\n");
    // scanf("%f", &pib);
    // printf("Digite o numero de pontos turisticos da Cidade\n");
    // scanf("%d", &pontos_turisticos);
    // //saida de dados com formatacao
    // printf("Codigo da Cidade: %s\n", codigo);
    // printf("Populacao da Cidade: %.3d\n", populacao);
    // printf("Área: %.3f km²\n", area);
    // printf("PIB da Cidade: %.2f\n", pib);
    // printf("Pontos turisticos da Cidade: %d\n", pontos_turisticos);
    // return 0;
}
